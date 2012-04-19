/*
 * TumblrApi.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#include "TwitterApi.h"

TwitterApi* TwitterApi::m_instance = NULL;

const QString TwitterApi::CONSUMER_KEY = QString("XgkQwRz4PN7pWrBNLs8pfw");
const QString TwitterApi::CONSUMER_SECRET = QString("hNtFbL8DiRrijdn3sjAjLDWJiEGg58LQ2AbhdDDnj8");
const QString TwitterApi::API_BASE = QString("https://api.twitter.com/1/");

TwitterApi::TwitterApi() {
    oauthRequest = new KQOAuthRequest;
    oauthManager = new KQOAuthManager(this);
    //this file should be a file path relative to the assets directory
    //oauthManager->setSuccessHtmlFile("success.html");
    oauthRequest->setEnableDebugOutput(true);
}

TwitterApi::~TwitterApi() {
    delete oauthRequest;
    delete oauthManager;
}

TwitterApi* TwitterApi::instance() {
	if(!m_instance) {
		m_instance = new TwitterApi;
	}
	return m_instance;
}

KQOAuthManager* TwitterApi::getRequestManager() {
	return oauthManager;
}

void TwitterApi::onTemporaryTokenReceived(QString token, QString tokenSecret)
{
    qDebug() << "Temporary token received: " << token << tokenSecret;

    QUrl userAuthURL("https://api.twitter.com/oauth/authorize");

    if( oauthManager->lastError() == KQOAuthManager::NoError) {
        qDebug() << "Asking for user's permission to access protected resources. Opening URL: " << userAuthURL;
        oauthManager->getUserAuthorization(userAuthURL);
    }

}

void TwitterApi::onAuthorizationReceived(QString token, QString verifier) {
    qDebug() << "User authorization received: " << token << verifier;

    oauthManager->getUserAccessTokens(QUrl("https://api.twitter.com/oauth/access_token"));
    if( oauthManager->lastError() != KQOAuthManager::NoError) {
        emit loginComplete(false);
    }
}

void TwitterApi::onAccessTokenReceived(QString token, QString tokenSecret) {
    qDebug() << "Access token received: " << token << tokenSecret;

    disconnect(oauthManager, SIGNAL(accessTokenReceived(QString,QString)), this, SLOT(onAccessTokenReceived(QString,QString)));

    if(token == NULL) {
    	emit loginComplete(false);
    	return;
    }
    oauthSettings.setValue("oauth_token", token);
    oauthSettings.setValue("oauth_token_secret", tokenSecret);

    emit loginComplete(token.length() > 0);
    qDebug() << "Access tokens now stored.";
}

void TwitterApi::onAuthorizedRequestDone() {
    qDebug() << "Request sent to Twitter!";
}

void TwitterApi::onRequestReady(QByteArray response) {
    qDebug() << "Response from the service: " << response;
    switch(oauthManager->lastError()){
    case KQOAuthManager::NoError:
    	break;
    default:
    	qDebug() << "There was an error";
    	break;
    }
    disconnect(oauthManager, SIGNAL(requestReady(QByteArray)), this, SLOT(onRequestReady(QByteArray)));
}

void TwitterApi::getAccess()
{
    connect(oauthManager, SIGNAL(temporaryTokenReceived(QString,QString)), this, SLOT(onTemporaryTokenReceived(QString, QString)));
    connect(oauthManager, SIGNAL(authorizationReceived(QString,QString)), this, SLOT( onAuthorizationReceived(QString, QString)));
    connect(oauthManager, SIGNAL(accessTokenReceived(QString,QString)), this, SLOT(onAccessTokenReceived(QString,QString)));
    connect(oauthManager, SIGNAL(requestReady(QByteArray)), this, SLOT(onRequestReady(QByteArray)));

    oauthRequest->initRequest(KQOAuthRequest::TemporaryCredentials, QUrl("https://api.twitter.com/oauth/request_token"));
    oauthRequest->setConsumerKey(CONSUMER_KEY);
    oauthRequest->setConsumerSecretKey(CONSUMER_SECRET);
    oauthManager->setHandleUserAuthorization(true);
    oauthManager->executeRequest(oauthRequest);
}

bool TwitterApi::checkToken() {
	return oauthSettings.value("oauth_token_secret").toString().isEmpty() || oauthSettings.value("oauth_token").toString().isEmpty();
}

KQOAuthRequest* TwitterApi::getUserInfo() {
	KQOAuthRequest *xRequest = new KQOAuthRequest(this);
	if(!checkToken()) {
		xRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl(API_BASE + "account/verify_credentials.json"));
		addAuth(xRequest);
		xRequest->setHttpMethod(KQOAuthRequest::GET);
	}
	return xRequest;
}

KQOAuthRequest* TwitterApi::updateStatus(QString status) {
	KQOAuthRequest *xRequest = new KQOAuthRequest(this);
	xRequest->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl(API_BASE + "statuses/update.json"));
	addAuth(xRequest);
	xRequest->setHttpMethod(KQOAuthRequest::POST);
	KQOAuthParameters params;
	params.insert("status",status);
	xRequest->setAdditionalParameters(params);
	return xRequest;
}

KQOAuthRequest* TwitterApi::getHomeTimeline() {
	KQOAuthRequest *req = new KQOAuthRequest(this);
	req->initRequest(KQOAuthRequest::AuthorizedRequest, QUrl(API_BASE + "statuses/home_timeline.json"));
	addAuth(req);
	req->setHttpMethod(KQOAuthRequest::GET);
	return req;
}

void TwitterApi::addAuth(KQOAuthRequest* req) {
	req->setConsumerKey(CONSUMER_KEY);
	req->setConsumerSecretKey(CONSUMER_SECRET);
	req->setToken(oauthSettings.value("oauth_token").toString());
	req->setTokenSecret(oauthSettings.value("oauth_token_secret").toString());
	qDebug() << oauthSettings.value("oauth_token_secret").toString() << " + " << oauthSettings.value("oauth_token").toString();
}

void TwitterApi::logout() {
	oauthSettings.setValue("oauth_token","");
	oauthSettings.setValue("oauth_token_secret","");
}

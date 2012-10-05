/*
 * LoginLayout.cpp
 *
 *  Created on: Mar 24, 2012
 *      Author: Kyle
 */

#include "LoginLayout.h"

LoginLayout::LoginLayout() {
    QmlDocument *qml = QmlDocument::create("asset:///twitterlogin.qml");
    qml->setContextProperty("loginLayout", this);

    Control *root = qml->createRootObject<Control>();
    this->setRoot(root);
}

LoginLayout::~LoginLayout() {
}

Q_INVOKABLE QString LoginLayout::getLoginButtonText() {
	if(!TwitterApi::instance()->checkToken()) {
		return "Logged In. Click to continue";
	}
	return "Login";
}

void LoginLayout::setUrl(QUrl authUrl) {
	webView->setUrl(authUrl);
}


void LoginLayout::makeLoginRequest()
{
	qDebug() << "Making request";
	connect(TwitterApi::instance(), SIGNAL(loginComplete(bool)), this,
			SLOT(onLoginResponse(bool)));
	TwitterApi::instance()->getAccess();
}

void LoginLayout::onButtonClicked()
{
	if(TwitterApi::instance()->checkToken()) {
		Button *loginButton = root()->findChild<Button*>("login");
		loginButton->setText("Logging In");
		webView = root()->findChild<WebView*>("webView");
		connect(TwitterApi::instance(), SIGNAL(urlReady(QUrl)), this, SLOT(setUrl(QUrl)));
		makeLoginRequest();
	} else {
		Button *loginButton = root()->findChild<Button*>("login");
		RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::UserObj, TwitterApi::instance()->getUserInfo());
		connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onUserDataLoad(AbstractObjectBase*)));
		env->makeRequest();
	}
}

void LoginLayout::requestComplete(QNetworkReply* reply)
{
	qDebug() << "Response Received";
	qDebug() << QString(reply->readAll());
}

void LoginLayout::onLoginResponse(bool success) {
	if(success) {
		Button *loginButton = root()->findChild<Button*>("login");
		loginButton->setText("Login Success");
		RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::UserObj, TwitterApi::instance()->getUserInfo());
		connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onUserDataLoad(AbstractObjectBase*)));
		env->makeRequest();
	} else {
		Button *loginButton = root()->findChild<Button*>("login");
		loginButton->setText("Login Failed");
	}
	disconnect(TwitterApi::instance(), SIGNAL(loginComplete(bool)),this,SLOT(onLoginResponse(bool)));
}

void LoginLayout::onUserDataLoad(AbstractObjectBase* user) {
	disconnect(qobject_cast<RequestEnvelope*>(sender()), SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onUserDataLoad(AbstractObjectBase*)));
	User* usr = qobject_cast<User*>(user);
	HomeLayout *home = new HomeLayout(usr);
	Page *p = new Page();
	p->setContent(home);
	Twitter::instance()->nav->push(p);
	//Application::setScene(home);
}


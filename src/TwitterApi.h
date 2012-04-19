/*
 * TwitterApi.h
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#ifndef TWITTERAPI_H_
#define TWITTERAPI_H_

#include <iostream>
#include <QtCore>
#include <QtCore/QObject>
#include <QSettings>
#include <oauth/kqoauthmanager.h>
#include <oauth/kqoauthrequest_xauth.h>
#include <oauth/kqoauthrequest.h>

class TwitterApi : public QObject {
	Q_OBJECT
public:
	static const QString API_BASE;
	static TwitterApi* instance();
	void getAccess();
    void logout();
	bool checkToken();
	KQOAuthManager* getRequestManager();

	//api methods
	KQOAuthRequest* getUserInfo();
	KQOAuthRequest* updateStatus(QString status);
	KQOAuthRequest* getHomeTimeline();
	void addAuth(KQOAuthRequest* req);
private:
	TwitterApi();
	virtual ~TwitterApi();
	static const QString CONSUMER_KEY;
	static const QString CONSUMER_SECRET;
	static TwitterApi* m_instance;
    KQOAuthManager *oauthManager;
    KQOAuthRequest *oauthRequest;
    QSettings oauthSettings;

signals:
	void loginComplete(bool);

private slots:
	void onTemporaryTokenReceived(QString temporaryToken, QString temporaryTokenSecret);
	void onAuthorizationReceived(QString token, QString verifier);
	void onAccessTokenReceived(QString token, QString tokenSecret);
	void onAuthorizedRequestDone();
	void onRequestReady(QByteArray);
};

#endif /* TUMBLRAPI_H_ */

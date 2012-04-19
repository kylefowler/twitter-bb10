/*
 * RequestEnvelope.h
 *
 *  Created on: Feb 19, 2012
 *      Author: Kyle
 */

#ifndef REQUESTENVELOPE_H_
#define REQUESTENVELOPE_H_

#include <qobject.h>
#include <QtCore>
#include "ApiResponseObjectFactory.h"
#include "ApiResponse.h"
#include "oauth/kqoauthrequest.h"
#include "TwitterApi.h"

class RequestEnvelope: public QObject {
	Q_OBJECT
public:
	RequestEnvelope(ApiResponseObjectFactory::ApiType,KQOAuthRequest*);
	~RequestEnvelope();
	KQOAuthRequest* getRequest();
	void makeRequest();
public slots:
	void onRequestCallback(QByteArray);
signals:
	void requestComplete(AbstractObjectBase*);
	void requestError(ResponseMeta*);
private:
	KQOAuthRequest* request;
	ApiResponse* response;
};

#endif /* REQUESTENVELOPE_H_ */

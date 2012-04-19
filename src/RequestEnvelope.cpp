/*
 * RequestEnvelope.cpp
 *
 *  Created on: Feb 19, 2012
 *      Author: Kyle
 */

#include "RequestEnvelope.h"

RequestEnvelope::RequestEnvelope(ApiResponseObjectFactory::ApiType type,KQOAuthRequest* apiRequest) {
	response = new ApiResponse(type);
	request = apiRequest;
}

RequestEnvelope::~RequestEnvelope() {
	delete request;
}

KQOAuthRequest* RequestEnvelope::getRequest() {
	return request;
}

void RequestEnvelope::makeRequest() {
	connect(TwitterApi::instance()->getRequestManager(), SIGNAL(requestReady(QByteArray)), this, SLOT(onRequestCallback(QByteArray)));
	request->setEnableDebugOutput(true);
	TwitterApi::instance()->getRequestManager()->executeRequest(request);
}

void RequestEnvelope::onRequestCallback(QByteArray resp) {
	disconnect(TwitterApi::instance()->getRequestManager(), SIGNAL(requestReady(QByteArray)), this, SLOT(onRequestCallback(QByteArray)));
	if(resp.isEmpty()) {
		//error need to tell the UI
		return;
	}
	response->parse(resp);
	qDebug() << resp;
	 if(response->getType() == ApiResponseObjectFactory::Empty){
		emit requestComplete(NULL);
	} else if(response->getResponse() != NULL) {
		emit requestComplete(response->getResponse());
	} else {
		emit requestError(response->getMeta());
	}
}

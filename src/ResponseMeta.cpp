/*
 * ResponseMeta.cpp
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#include "ResponseMeta.h"

ResponseMeta::ResponseMeta() {

}

ResponseMeta::~ResponseMeta() {
}

void ResponseMeta::parse(QVariantMap obj) {
	setStatus(obj["status"].toInt());
	setMsg(obj["msg"].toString());
}

void ResponseMeta::setStatus(const int respStatus) {
	status = respStatus;
}

void ResponseMeta::setMsg(const QString& respMsg) {
	msg = respMsg;
}

int ResponseMeta::getStatus() {
	return status;
}

QString ResponseMeta::getMsg() {
	return msg;
}


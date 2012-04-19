/*
 * ResponseMeta.h
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#ifndef RESPONSEMETA_H_
#define RESPONSEMETA_H_

#include "AbstractObjectBase.h"
#include <QtCore>

class ResponseMeta: public AbstractObjectBase {
public:
	ResponseMeta();
	virtual ~ResponseMeta();
	void parse(QVariantMap);
	void setStatus(const int);
	void setMsg(const QString&);
	int getStatus();
	QString getMsg();
private:
	int status;
	QString msg;
};

#endif /* RESPONSEMETA_H_ */

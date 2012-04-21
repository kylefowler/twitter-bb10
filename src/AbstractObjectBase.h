/*
 * AbstractObjectBase.h
 *
 *  Created on: Feb 18, 2012
 *      Author: Kyle
 */

#ifndef ABSTRACTOBJECTBASE_H_
#define ABSTRACTOBJECTBASE_H_

#include <QtCore/QObject>
#include <QtCore/QVariantMap>
#include <QtCore/QVariantList>

class AbstractObjectBase : public QObject {
	Q_OBJECT
public:
	AbstractObjectBase();
	virtual ~AbstractObjectBase();
	virtual void parse(QVariantMap) =0;
	virtual void parse(QVariantList) =0;
};

#endif /* ABSTRACTOBJECTBASE_H_ */

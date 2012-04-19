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

class AbstractObjectBase {
public:
	AbstractObjectBase();
	virtual ~AbstractObjectBase();
	virtual void parse(QVariantMap);
};

#endif /* ABSTRACTOBJECTBASE_H_ */

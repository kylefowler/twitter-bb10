/*
 * User.h
 *
 *  Created on: Feb 20, 2012
 *      Author: Kyle
 */

#ifndef USER_H_
#define USER_H_

#include "AbstractObjectBase.h"
#include <QtCore>
#include <QtCore/QList>
#include "qlist.h"

class User: public AbstractObjectBase {
public:
	User();
	virtual ~User();
	void parse(QVariantMap);
	QString getName();
	int getFriendsCount();
	int getStatusesCount();
    void setFriendsCount(int friends);
    void setStatusesCount(int statuses);
    void setName(QString name);
private:
	QString name;
	int friendsCount;
	int statusesCount;
};

#endif /* USER_H_ */

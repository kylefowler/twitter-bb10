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
	Q_OBJECT
	Q_PROPERTY(QString name READ name)
	Q_PROPERTY(QString screenName READ screenName)
	Q_PROPERTY(QString location READ location)
	Q_PROPERTY(QString url READ url)
public:
	User();
	virtual ~User();
	void parse(QVariantMap);
	void parse(QVariantList);
	QString name();
	QString screenName();
	QString location();
	QString url();
	int getFriendsCount();
	int getStatusesCount();
    void setFriendsCount(int friends);
    void setStatusesCount(int statuses);
    void setFollowerCount(int followers);
    void setName(QString name);
    void setScreenName(QString screenName);
    void setUrl(QString url);
    void setLocation(QString location);
private:
	QString m_name;
	QString m_location;
	QString m_url;
	QString m_screenName;
	int friendsCount;
	int followersCount;
	int statusesCount;
};

#endif /* USER_H_ */

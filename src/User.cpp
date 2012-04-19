/*
 * User.cpp
 *
 *  Created on: Feb 20, 2012
 *      Author: Kyle
 */

#include "User.h"

User::User() {
}

User::~User() {
}

void User::parse(QVariantMap qMap)
{
	setName(qMap["name"].toString());
	setStatusesCount(qMap["statuses_count"].toInt());
	setFriendsCount(qMap["friends_count"].toInt());
}

QString User::getName()
{
	return name;
}

int User::getFriendsCount()
{
	return friendsCount;
}

int User::getStatusesCount()
{
	return statusesCount;
}

void User::setFriendsCount(int following)
{
    this->statusesCount = following;
}

void User::setStatusesCount(int likes)
{
    this->friendsCount = likes;
}

void User::setName(QString name)
{
    this->name = name;
}

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
	setScreenName(qMap["screen_name"].toString());
	setUrl(qMap["url"].toString());
	setLocation(qMap["location"].toString());
	setFollowerCount(qMap["followers_count"].toInt());
	setStatusesCount(qMap["statuses_count"].toInt());
	setFriendsCount(qMap["friends_count"].toInt());
}

void User::parse(QVariantList list)
{
}

QString User::name()
{
	return m_name;
}

QString User::screenName()
{
	return m_screenName;
}

QString User::url()
{
	return m_url;
}

QString User::location()
{
	return m_location;
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

void User::setFollowerCount(int followers)
{
    this->followersCount = followers;
}

void User::setName(QString name)
{
    this->m_name = name;
}

void User::setScreenName(QString screenName) {
	this->m_screenName = screenName;
}
void User::setUrl(QString url) {
	this->m_url = url;
}
void User::setLocation(QString location) {
	this->m_location = location;
}

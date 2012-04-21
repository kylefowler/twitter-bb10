/*
 * Tweet.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: Kyle
 */

#include "Tweet.h"
#include <QtCore>

Tweet::Tweet() {

}

Tweet::~Tweet() {
}

void Tweet::parse(QVariantMap tweet)
{
	foreach(const QString& key, tweet.keys()) {
		qDebug() << key;
	}
	text = tweet["text"].toString();
	id = tweet["id"].toString();
	retweetCount = tweet["retweet_count"].toInt();
}

void Tweet::parse(QVariantList tweets) {}

QString Tweet::getText()
{
	return text;
}

int Tweet::getRetweetCount()
{
	return retweetCount;
}

QString Tweet::getTweetId()
{
	return id;
}

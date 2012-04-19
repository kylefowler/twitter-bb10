/*
 * Tweet.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: Kyle
 */

#include "Tweet.h"

Tweet::Tweet() {

}

Tweet::~Tweet() {
}

void Tweet::parse(QVariantMap tweet)
{
	text = tweet["text"].toString();
	id = tweet["id"].toString();
	retweetCount = tweet["retweet_count"].toInt();
}

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

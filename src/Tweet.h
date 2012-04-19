/*
 * Tweet.h
 *
 *  Created on: Apr 18, 2012
 *      Author: Kyle
 */

#ifndef TWEET_H_
#define TWEET_H_

#include "AbstractObjectBase.h"

class Tweet: public AbstractObjectBase {
public:
	Tweet();
	virtual ~Tweet();
	void parse(QVariantMap);
	QString getText();
	int getRetweetCount();
	QString getTweetId();
private:
	QString text;
	QString id;
	int retweetCount;
};

#endif /* TWEET_H_ */

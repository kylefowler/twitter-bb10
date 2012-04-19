/*
 * ApiResponseObjectFactory.h
 *
 *  Created on: Feb 19, 2012
 *      Author: Kyle
 */

#ifndef APIRESPONSEOBJECTFACTORY_H_
#define APIRESPONSEOBJECTFACTORY_H_

#include "AbstractObjectBase.h"
#include "ResponseMeta.h"
#include "User.h"
#include "Tweet.h"

class ApiResponseObjectFactory {
public:
	enum ApiType { Empty, UserObj, TweetObj };

	ApiResponseObjectFactory();
	virtual ~ApiResponseObjectFactory();
	static AbstractObjectBase* createApiResponseObject(ApiType type) {
		switch(type) {
		default:
		case UserObj:
			return new User;
		case TweetObj:
			return new Tweet;
		case Empty:
			return NULL;
		}
	}
};

#endif /* APIRESPONSEOBJECTFACTORY_H_ */

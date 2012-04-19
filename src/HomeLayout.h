/*
 * HomeLayout.h
 *
 *  Created on: Feb 21, 2012
 *      Author: Kyle
 */

#ifndef HOMELAYOUT_H_
#define HOMELAYOUT_H_

#include <bb/cascades/CustomControl>
#include <bb/cascades/databinding/qlistdatamodel.h>
#include "User.h"
#include "RequestEnvelope.h"
#include "AbstractObjectBase.h"
#include "Twitter.hpp"

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class Label;
        class Button;
        class TextArea;
    }
}

class HomeLayout: public bb::cascades::CustomControl
{
	Q_OBJECT
public:
	HomeLayout(User*);
	virtual ~HomeLayout();
private:
	Label *userName;
	Button *logoutButton;
	Button *tweetButton;
	TextArea *tweetText;
	User *user;
private slots:
	void onLogoutClicked();
	void onTweetClicked();
	void onTweetPosted(AbstractObjectBase*);
};
#endif /* HOMELAYOUT_H_ */

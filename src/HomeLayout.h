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
	Q_INVOKABLE void onTweetClicked(QString text);
private:
	User *user;
public slots:
	void onLogoutClicked();
private slots:
	void onTweetPosted(AbstractObjectBase*);
};
#endif /* HOMELAYOUT_H_ */

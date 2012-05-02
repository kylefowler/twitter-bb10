/*
 * LoginLayout.h
 *
 *  Created on: Mar 24, 2012
 *      Author: Kyle
 */

#ifndef LOGINLAYOUT_H_
#define LOGINLAYOUT_H_

#include <bb/cascades/CustomControl>
#include <QtCore/QObject>
#include <QSettings>
#include <QtNetwork/qnetworkreply.h>
#include <bb/cascades/Application>
#include <bb/cascades/Container>
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Control>
#include <bb/cascades/Button>
#include <bb/cascades/TextField>
#include <bb/cascades/animation/groupanimation.h>
#include <bb/cascades/animation/translatetransition.h>
#include <bb/cascades/animation/stockcurve.h>
#include <bb/cascades/Page>
#include "AbstractObjectBase.h"
#include "Twitter.hpp"
#include "TwitterApi.h"
#include "RequestEnvelope.h"
#include "HomeLayout.h"

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class Button;
        class TextField;
        class SequentialAnimation;
    }
}

class LoginLayout: public bb::cascades::CustomControl {
	Q_OBJECT
public:
	LoginLayout();
	virtual ~LoginLayout();
    Button *loginButton;
    void makeLoginRequest();
    Q_INVOKABLE QString getLoginButtonText();
public slots:
	void onButtonClicked();
private slots:
	void requestComplete(QNetworkReply*);
	void onLoginResponse(bool);
	void onUserDataLoad(AbstractObjectBase*);
};

#endif /* LOGINLAYOUT_H_ */

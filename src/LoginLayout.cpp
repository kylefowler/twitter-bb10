/*
 * LoginLayout.cpp
 *
 *  Created on: Mar 24, 2012
 *      Author: Kyle
 */

#include "LoginLayout.h"

LoginLayout::LoginLayout() {
    QmlDocument *qml = QmlDocument::create("twitterlogin.qml");
    qml->setContextProperty("loginLayout", this);

    Control *root = qml->createRootNode<Control>();
    bb::cascades::CustomControl::setRoot(root);
}

LoginLayout::~LoginLayout() {
}

Q_INVOKABLE QString LoginLayout::getLoginButtonText() {
	if(!TwitterApi::instance()->checkToken()) {
		return "Logged In. Click to continue";
	}
	return "Login";
}


void LoginLayout::makeLoginRequest()
{
	qDebug() << "Making request";
	connect(TwitterApi::instance(), SIGNAL(loginComplete(bool)),this,SLOT(onLoginResponse(bool)));
	TwitterApi::instance()->getAccess();
}

void LoginLayout::onButtonClicked()
{
	if(TwitterApi::instance()->checkToken()) {
		Button *loginButton = root()->findChild<Button*>("login");
		loginButton->setText("Logging In");
		makeLoginRequest();
	} else {
		Button *loginButton = root()->findChild<Button*>("login");
		SequentialAnimation* anim = SequentialAnimation::create(loginButton)
						.add(TranslateTransition::create(loginButton).toX(100).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(-100).duration(500).easingCurve(StockCurve::QuadraticIn))
						.add(TranslateTransition::create(loginButton).toX(50).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(0).duration(500).easingCurve(StockCurve::QuadraticIn));
		anim->play();
		RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::UserObj, TwitterApi::instance()->getUserInfo());
		connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onUserDataLoad(AbstractObjectBase*)));
		env->makeRequest();
	}
}

void LoginLayout::requestComplete(QNetworkReply* reply)
{
	qDebug() << "Response Received";
	qDebug() << QString(reply->readAll());
}

void LoginLayout::onLoginResponse(bool success) {
	if(success) {
		Button *loginButton = root()->findChild<Button*>("login");
		loginButton->setText("Login Success");
		SequentialAnimation* anim = SequentialAnimation::create(loginButton)
						.add(TranslateTransition::create(loginButton).toX(100).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(-100).duration(500).easingCurve(StockCurve::QuadraticIn))
						.add(TranslateTransition::create(loginButton).toX(50).duration(500).easingCurve(StockCurve::QuadraticOut))
						.add(TranslateTransition::create(loginButton).toX(0).duration(500).easingCurve(StockCurve::QuadraticIn));
		anim->play();
		RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::UserObj, TwitterApi::instance()->getUserInfo());
		connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onUserDataLoad(AbstractObjectBase*)));
		env->makeRequest();
	} else {
		Button *loginButton = root()->findChild<Button*>("login");
		loginButton->setText("Login Failed");
	}
	disconnect(TwitterApi::instance(), SIGNAL(loginComplete(bool)),this,SLOT(onLoginResponse(bool)));
}

void LoginLayout::onUserDataLoad(AbstractObjectBase* user) {
	disconnect(qobject_cast<RequestEnvelope*>(sender()), SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onUserDataLoad(AbstractObjectBase*)));
	User* usr = qobject_cast<User*>(user);
	HomeLayout *home = new HomeLayout(usr);
	Twitter::instance()->nav->push(home);
	//Application::setScene(home);
}


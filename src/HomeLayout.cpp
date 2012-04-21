/*
 * HomeLayout.cpp
 *
 *  Created on: Feb 21, 2012
 *      Author: Kyle
 */

#include "HomeLayout.h"

#include <bb/cascades/QmlDocument>
#include <bb/cascades/Control>
#include <bb/cascades/Container>
#include <bb/cascades/Label>
#include <bb/cascades/Button>
#include <bb/cascades/TextArea>

HomeLayout::HomeLayout(User *homeUser) :
                CustomControl()
{
	user = homeUser;

	QmlDocument *qml = QmlDocument::create("twitterhome.qml");
	qml->setContextProperty("homeView", this);
	qml->setContextProperty("twitterUser", user);

	Control *root = qml->createRootNode<Control>();
	bb::cascades::CustomControl::setRoot(root);
}

HomeLayout::~HomeLayout() {
}

void HomeLayout::onLogoutClicked() {
	TwitterApi::instance()->logout();
	Twitter::instance()->nav->pop();
}

Q_INVOKABLE void HomeLayout::onTweetClicked(QString text) {
	RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::TweetObj, TwitterApi::instance()->updateStatus(text));
	connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onTweetPosted(AbstractObjectBase*)));
	env->makeRequest();
}

void HomeLayout::onTweetPosted(AbstractObjectBase* tweet) {
	Q_UNUSED(tweet);
	RequestEnvelope *env = qobject_cast<RequestEnvelope *>(sender());
	disconnect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onTweetPosted(AbstractObjectBase*)));
	qDebug() << "Successfully posted the tweet";
	TextArea *tweetText = root()->findChild<TextArea*>("tweetText");
	tweetText->setText("Tweet Posted!");
}

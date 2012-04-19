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
	QmlDocument *qml = QmlDocument::create("twitterhome.qml");
	qml->setContextProperty("lg", this);

	user = homeUser;
	Control *root = qml->createRootNode<Control>();
	userName = root->findChild<Label*>("userName");
	userName->setText(user->getName());

    logoutButton = root->findChild<Button*>("logoutButton");
    connect(logoutButton, SIGNAL(clicked()), this, SLOT(onLogoutClicked()));

	tweetButton = root->findChild<Button*>("postTweetButton");
	connect(tweetButton, SIGNAL(clicked()), this, SLOT(onTweetClicked()));
	tweetText = root->findChild<TextArea*>("tweetText");

	bb::cascades::CustomControl::setRoot(root);
}

HomeLayout::~HomeLayout() {
	delete userName;
}

void HomeLayout::onLogoutClicked() {
	TwitterApi::instance()->logout();
	Twitter::instance()->nav->pop();
}

void HomeLayout::onTweetClicked() {
	RequestEnvelope *env = new RequestEnvelope(ApiResponseObjectFactory::TweetObj, TwitterApi::instance()->updateStatus(tweetText->text()));
	connect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onTweetPosted(AbstractObjectBase*)));
	env->makeRequest();
}

void HomeLayout::onTweetPosted(AbstractObjectBase* tweet) {
	RequestEnvelope *env = qobject_cast<RequestEnvelope *>(sender());
	disconnect(env, SIGNAL(requestComplete(AbstractObjectBase*)), this, SLOT(onTweetPosted(AbstractObjectBase*)));
	qDebug() << "Successfully posted the tweet";
	tweetText->setText("Tweet Posted!");
}

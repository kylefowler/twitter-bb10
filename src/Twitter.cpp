#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Control>
#include <bb/cascades/Button>
#include <bb/cascades/TextField>
#include <bb/cascades/animation/groupanimation.h>
#include <bb/cascades/animation/translatetransition.h>
#include <bb/cascades/animation/stockcurve.h>

#include "Twitter.hpp"
#include "TwitterApi.h"
#include "RequestEnvelope.h"
#include "LoginLayout.h"


using namespace bb::cascades;

Twitter* Twitter::appInstance = NULL;

Twitter::Twitter()
{
	// Create the NavigationControl and set its size this is the area were Controls
	// that are pushed and popped are presented. By the default the Navigation Control
	// has a navigation bar with a title, this can also be used to peek (drag on top of the bar)
	// and navigate backwards in the stack.
	nav = new NavigationPane();

	// Push the first Control to the stack.
	LoginLayout* first = new LoginLayout();
	Page *p = Page::create();
	p->setContent(first);
	nav->push(p);
	Application::instance()->setScene(nav);
}

Twitter::~Twitter()
{
}

Twitter* Twitter::instance() {
	if(!appInstance) {
		appInstance = new Twitter;
	}
	return appInstance;
}


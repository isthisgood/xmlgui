/**
 * ofGuiEventDispatcher.cpp
 * emptyExample 
 *
 * Created by Marek Bereza on 16/06/2011.
 *
 */

#include "xmlgui/framework/ofGuiEventDispatcher.h"
#include "xmlgui/framework/Container.h"
int xmlgui::ofGuiEventDispatcher::eventPriorityCounter = 500;
int xmlgui::ofGuiEventDispatcher::drawPriorityCounter = 500;


xmlgui::ofGuiEventDispatcher::ofGuiEventDispatcher() {
	drawPriorityCounter+=2;
	eventPriorityCounter-=2;
	eventPriority  = eventPriorityCounter;
	drawPriority = drawPriorityCounter;
	this->enabled = false;
	this->manualDraw = false;
}

void xmlgui::ofGuiEventDispatcher::setup(Container *root) {
	this->root = root;
}
void xmlgui::ofGuiEventDispatcher::draw(ofEventArgs &e) {
	if(manualDraw) return;
	root->draw();
	xmlgui::Resources::drawAllDeferredStrings();
}


bool xmlgui::ofGuiEventDispatcher::mousePressed(ofMouseEventArgs &e) {
	return root->touchDown(e.x, e.y, e.button);
}

void xmlgui::ofGuiEventDispatcher::mouseMoved(ofMouseEventArgs &e) {
	root->touchOver(e.x, e.y, e.button);
}

bool xmlgui::ofGuiEventDispatcher::mouseDragged(ofMouseEventArgs &e) {
	return root->touchMoved(e.x, e.y, e.button);
}

bool xmlgui::ofGuiEventDispatcher::mouseReleased(ofMouseEventArgs &e) {
	return root->touchUp(e.x, e.y, e.button);
}

bool xmlgui::ofGuiEventDispatcher::keyPressed(ofKeyEventArgs &e) {
	return root->keyPressed(e.key);
}

bool xmlgui::ofGuiEventDispatcher::keyReleased(ofKeyEventArgs &e) {
	return root->keyReleased(e.key);
}


bool xmlgui::ofGuiEventDispatcher::touchDown(ofTouchEventArgs &e) {
	return root->touchDown(e.x, e.y, e.id);
}

bool xmlgui::ofGuiEventDispatcher::touchMoved(ofTouchEventArgs &e) {
	return root->touchMoved(e.x, e.y, e.id);
}

bool xmlgui::ofGuiEventDispatcher::touchUp(ofTouchEventArgs &e) {
	return root->touchUp(e.x, e.y, e.id);
}

void xmlgui::ofGuiEventDispatcher::enableInteraction() {
	ofAddListener(ofEvents().mousePressed, this, &xmlgui::ofGuiEventDispatcher::mousePressed);
	ofAddListener(ofEvents().mouseMoved, this, &xmlgui::ofGuiEventDispatcher::mouseMoved);
	ofAddListener(ofEvents().mouseDragged, this, &xmlgui::ofGuiEventDispatcher::mouseDragged);
	ofAddListener(ofEvents().mouseReleased, this, &xmlgui::ofGuiEventDispatcher::mouseReleased);
	
	ofAddListener(ofEvents().touchDown, this, &xmlgui::ofGuiEventDispatcher::touchDown);
	ofAddListener(ofEvents().touchUp, this, &xmlgui::ofGuiEventDispatcher::touchUp);
	ofAddListener(ofEvents().touchMoved, this, &xmlgui::ofGuiEventDispatcher::touchMoved);
	
	ofAddListener(ofEvents().keyPressed, this, &xmlgui::ofGuiEventDispatcher::keyPressed);
	ofAddListener(ofEvents().keyReleased, this, &xmlgui::ofGuiEventDispatcher::keyReleased);
}


void xmlgui::ofGuiEventDispatcher::enableEvents() {

	enableInteraction();

	ofAddListener(ofEvents().draw, this, &xmlgui::ofGuiEventDispatcher::draw, drawPriority);
	

	
}

void xmlgui::ofGuiEventDispatcher::disableInteraction() {
	ofRemoveListener(ofEvents().mousePressed, this, &xmlgui::ofGuiEventDispatcher::mousePressed, eventPriority);
	ofRemoveListener(ofEvents().mouseMoved, this, &xmlgui::ofGuiEventDispatcher::mouseMoved, eventPriority);
	ofRemoveListener(ofEvents().mouseDragged, this, &xmlgui::ofGuiEventDispatcher::mouseDragged, eventPriority);
	ofRemoveListener(ofEvents().mouseReleased, this, &xmlgui::ofGuiEventDispatcher::mouseReleased, eventPriority);
	
	ofRemoveListener(ofEvents().touchDown, this, &xmlgui::ofGuiEventDispatcher::touchDown, eventPriority);
	ofRemoveListener(ofEvents().touchUp, this, &xmlgui::ofGuiEventDispatcher::touchUp, eventPriority);
	ofRemoveListener(ofEvents().touchMoved, this, &xmlgui::ofGuiEventDispatcher::touchMoved, eventPriority);
	
	ofRemoveListener(ofEvents().keyPressed, this, &xmlgui::ofGuiEventDispatcher::keyPressed, eventPriority);
	ofRemoveListener(ofEvents().keyReleased, this, &xmlgui::ofGuiEventDispatcher::keyReleased, eventPriority);
}

void xmlgui::ofGuiEventDispatcher::disableEvents() {
	disableInteraction();

	ofRemoveListener(ofEvents().draw, this, &xmlgui::ofGuiEventDispatcher::draw, drawPriority);
	

}

bool xmlgui::ofGuiEventDispatcher::isEnabled() {
	return enabled;
}

void xmlgui::ofGuiEventDispatcher::setEnabled(bool enabled) {

	if(enabled!=this->enabled) {
		if(enabled) {
			enableEvents();
		} else {
			disableEvents();
		}
	}
	this->enabled = enabled;
	
}


void xmlgui::ofGuiEventDispatcher::setManualDraw(bool manualDraw) {
	this->manualDraw = manualDraw;
}








int xmlgui::ofGuiEventDispatcher::getDrawPriority() {
	return drawPriority;
}





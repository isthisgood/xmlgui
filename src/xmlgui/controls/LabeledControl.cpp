/**
 *  LabeledControl.cpp
 *
 *  Created by Marek Bereza on 14/10/2013.
 */

#include "LabeledControl.h"
#include "Container.h"



LabeledControl::LabeledControl(): Control() {
	lastDrawnFrame = 0;
	labelColor = 0xFFFFFF;
	drawingLabel = true;
	
}

void LabeledControl::drawAllLabels() {
	xmlgui::Resources::bindFont();
	setRGBA(0xFFFFFF);
	for(int i = 0; i < labels.size(); i++) {
		xmlgui::Resources::drawString(labels[i].second,labels[i].first.x, labels[i].first.y);
	}
	xmlgui::Resources::unbindFont();
	labels.clear();
}


void LabeledControl::drawLabel(float x, float y) {
	//drawLabelsIfNeeded();
	
	
	if(drawingLabel) {
		if(x==-1) {
			x = this->x;
			y = this->y - 3;
		}
		setRGBA(labelColor);
		xmlgui::Resources::drawString(name, x, y);
		//			ofVec2f p = parent->getAbsolutePosition();
		//			labels.push_back(make_pair(ofVec2f(x,y)+p, name));
	}
	
}

void LabeledControl::drawCustomLabel(string label, float x, float y) {
	
	if(drawingLabel) {
		if(parent->isOpaque()) {
			ofSetColor(0, 0, 0, 150);
			ofRect( x, y-10, width, 14);
		}
		
		setRGBA(labelColor);
		xmlgui::Resources::drawString(label, x, y);
		
		//			ofVec2f p = parent->getAbsolutePosition();
		//			labels.push_back(make_pair(ofVec2f(x,y)+p, label));
		
	}
}


void LabeledControl::getParameterInfo(vector<ParameterInfo> &params) {
	params.push_back(ParameterInfo("Draw Label", "drawlabel", "toggle", &drawingLabel));
	params.push_back(ParameterInfo("Label Color", "labelColor", "hexcolorpicker", &labelColor));
}

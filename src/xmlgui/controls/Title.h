/*
 *  GuiTitle.h
 *  emptyExample
 *
 *  Created by Marek Bereza on 17/01/2011.
 *
 */


#pragma once

#include "xmlgui/framework/Control.h"
namespace xmlgui {
	class Title: public xmlgui::Control {
	public:
		
		Title(): Control() {
			height = 24;
			width = 110;
		}
		
		
		
		void draw() {
			if(parent->isOpaque()) {
				ofSetColor(0, 0, 0, 150);
				ofRect( x, y, width, height-5);
			}
			ofSetColor(255);
			xmlgui::Resources::drawString(this, name, x+3, y+14);
			ofLine(x, y+height-5, x+width, y+height-5);
		}
	};
}

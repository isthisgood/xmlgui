/*
 *  GuiToggle.h
 *  Gui
 *
 *  Created by Marek Bereza on 11/02/2010.
 *
 */
#pragma once

#include "xmlgui/controls/LabeledControl.h"
namespace xmlgui {
	class Toggle: public LabeledControl {
	public:


		int offColor;
		int onColor;
		int strokeColor;

		ofImage *toggleOn;
		ofImage *toggleOff;
		ofImage *toggleDown;

		string toggleOnUrl;
		string toggleOffUrl;
		string toggleDownUrl;

		bool momentary = false;
		
		function<void(bool)> onChange;

		Toggle(): LabeledControl() {
			offColor = 0x505050;
			onColor = 0x995050;
			strokeColor = 0;
            height = LabeledControl::DEFAULT_CONTROL_HEIGHT;
			width = 70;

			value = new bool[1];
			bval(value) = false;

			toggleOn = toggleOff = toggleDown = NULL;
			toggleOnUrl = toggleOffUrl = toggleDownUrl = "";
		}

		void load() {
			toggleOn = xmlgui::Resources::getImage(toggleOnUrl);
			toggleOff = xmlgui::Resources::getImage(toggleOffUrl);
			toggleDown = xmlgui::Resources::getImage(toggleDownUrl);
			if(toggleOn!=NULL) {
				scalable = false;
				width = toggleOn->getWidth();
				height = toggleOn->getHeight();
			} else if(toggleOff!=NULL) {
				scalable = false;
				width = toggleOff->getWidth();
				height = toggleOff->getHeight();
			} else if(toggleDown!=NULL) {
				scalable = false;
				width = toggleDown->getWidth();
				height = toggleDown->getHeight();
			}
		}

		void draw() {



			if(bval(value)) {
				if(toggleDown!=NULL && down) {
					ofSetHexColor(0xFFFFFF);
					toggleDown->draw(x, y);
				} else if(toggleOn && !down) {
					ofSetHexColor(0xFFFFFF);
					toggleOn->draw(x, y);
				} else {
					setRGBA(onColor);
                    ofDrawRectangle(*this);
				}
			} else {
				if(toggleDown!=NULL && down) {
					ofSetHexColor(0xFFFFFF);
					toggleDown->draw(x, y);

				} else if(toggleOff!=NULL) {
					ofSetHexColor(0xFFFFFF);
					toggleOff->draw(x, y);
				} else {

					setRGBA(offColor);
                    ofDrawRectangle(*this);
				
				}
			}

			if(toggleOff==NULL) {
				setRGBA(strokeColor);
				ofNoFill();
				ofDrawRectangle(*this);

				if(bval(value)) {
					ofDrawLine(x+3, y+3, x+width-5, y+height-5);
					ofDrawLine(x+3, y+height-5, x+width-5, y+3);
				}
				ofFill();
			}
			drawLabel(x, y-3);
		}
		bool touchDown(int _x, int _y, int button) {
			
			if(momentary) {
				bval(value) = true;
			} else {
				bval(value) = !bval(value);
			}
			if(onChange) {
				onChange(bval(value));
			}
			//			printf("Toucing down on %s\n", name.c_str());
			return true;
		}
		
		bool touchUp(int _x, int _y, int button) {
			
			if(momentary) {
				bval(value) = false;
                if(onChange) {
                    onChange(bval(value));
                }
			}
            
			return true;
		}

		void getParameterInfo(vector<ParameterInfo> &params) {
			LabeledControl::getParameterInfo(params);
			params.push_back(ParameterInfo("Value","value", "toggle",value));

			params.push_back(ParameterInfo("Off Color", "offColor", "hexcolorpicker", &offColor));
			params.push_back(ParameterInfo("On Color", "onColor", "hexcolorpicker", &onColor));
			params.push_back(ParameterInfo("Stroke Color", "strokeColor", "hexcolorpicker", &strokeColor));
			params.push_back(ParameterInfo("Toggle On", "toggleOnUrl", "file", &toggleOnUrl));
			params.push_back(ParameterInfo("Toggle Off", "toggleOffUrl", "file", &toggleOffUrl));
			params.push_back(ParameterInfo("Toggle Down", "toggleDownUrl", "file", &toggleDownUrl));
		}

		string valueToString() { return bval(value)?"true":"false"; }
		void valueFromString(string inp) { bval(value) = (inp=="true"); }

	};
}

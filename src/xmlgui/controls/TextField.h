/**     ___           ___           ___                         ___           ___     
 *     /__/\         /  /\         /  /\         _____         /  /\         /__/|    
 *    |  |::\       /  /::\       /  /::|       /  /::\       /  /::\       |  |:|    
 *    |  |:|:\     /  /:/\:\     /  /:/:|      /  /:/\:\     /  /:/\:\      |  |:|    
 *  __|__|:|\:\   /  /:/~/::\   /  /:/|:|__   /  /:/~/::\   /  /:/  \:\   __|__|:|    
 * /__/::::| \:\ /__/:/ /:/\:\ /__/:/ |:| /\ /__/:/ /:/\:| /__/:/ \__\:\ /__/::::\____
 * \  \:\~~\__\/ \  \:\/:/__\/ \__\/  |:|/:/ \  \:\/:/~/:/ \  \:\ /  /:/    ~\~~\::::/
 *  \  \:\        \  \::/          |  |:/:/   \  \::/ /:/   \  \:\  /:/      |~~|:|~~ 
 *   \  \:\        \  \:\          |  |::/     \  \:\/:/     \  \:\/:/       |  |:|   
 *    \  \:\        \  \:\         |  |:/       \  \::/       \  \::/        |  |:|   
 *     \__\/         \__\/         |__|/         \__\/         \__\/         |__|/   
 *
 *  Description: 
 *				 
 *  TextField.h, created by Marek Bereza on 14/10/2013.
 */

#pragma once
#include "xmlgui/controls/LabeledControl.h"
#include "xmlgui/textfield/TextFieldFontRenderer.h"
namespace xmlgui {
	class TextField: public LabeledControl {
	public:
		
		bool editable;
		
		//can be set manually or otherwise is controlled by enable/disable
		bool drawCursor;
		
		
		
		int cursorPosition;
		
		int selectionBegin;
		int selectionEnd;
		bool selecting;
		
		
		TextField();
		
		void draw();
		bool touchDown(int x, int y, int id);
		bool touchMoved(int x, int y, int id);
		bool touchUp(int x, int y, int id);
					
		bool keyPressed(int key);
		bool keyReleased(int key);
		void setTextFieldValue(string v);
		
	protected:
		virtual bool isKeyAllowed(int key);
		void getCursorCoords(int pos, int &cursorX);
		string getTextFieldValue();
		
		
		string displayString;
		void beginEditing();
		void endEditing();
		
		float lastTimeCursorMoved;
		int VERTICAL_PADDING;
		int HORIZONTAL_PADDING;
		static xmlgui::ofxTextInput::FontRenderer* fontRef;
		
		bool 	isEnabled;
		bool	isEditing;
		bool	mouseDownInRect;
		bool isShifted, isCommand;
        static std::map<int, char> shiftMap;
		int getCursorPositionFromMouse(int x);
		
		string valueToString() { return sval(value); }
		void valueFromString(string inp) { sval(value) = inp; }
		float lastTimeClicked;
	};

}



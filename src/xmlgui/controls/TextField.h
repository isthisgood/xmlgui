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

class TextField: public LabeledControl {
public:
	
	
	
    //can be set manually or otherwise is controlled by enable/disable
    bool drawCursor;
    
	
	
	int cursorPosition;
	
	int selectionBegin;
	int selectionEnd;
	bool selecting;
	
	
	TextField();
	
	void draw() {
	}
	
	
	
protected:
	float lastTimeCursorMoved;
	int VERTICAL_PADDING;
	int HORIZONTAL_PADDING;
	xmlgui::ofxTextInput::FontRenderer* fontRef;
	
    bool 	isEnabled;
	bool	isEditing;
	bool	mouseDownInRect;
	bool isShifted, isCommand;
	static map<int, char> shiftMap;
};

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
 *  ParameterizedGui.h, created by Marek Bereza on 13/11/2012.
 */

#include "xmlgui/container/SimpleGui.h"
#include "xmlgui/container/Parameterized.h"

namespace xmlgui {
	class ParameterizedGui: public xmlgui::SimpleGui {
	public:
		ParameterizedGui(): xmlgui::SimpleGui() {
			choice = -1;
			lastChoice = -2;
			gui = new xmlgui::SimpleGui();
			list = NULL;
			//list = gui->addList("list", choice, vector<string>());
			//addChild(gui);
		}


		// this is a workaround to let you listen to the gui
		// even though the superclass is a Listener. See
		// SimpleGui::ctrlChanged() and ::controlChanged()
		void ctrlChanged(xmlgui::Event *e) {

			if(choice!=lastChoice && choice>=0) {
				gui->clear();
				parameterizeds[choice].second->parameterize(gui);
				gui->loadSettings("settings/" + parameterizeds[choice].first + ".xml");
			}

			lastChoice = choice;
		}

		void addParameterized(string name, Parameterized *parameterized) {
			if(list==NULL) {
				list = gui->addList("list", choice, vector<string>());
				addChild(gui);
			}
			parameterizeds.push_back(make_pair(name, parameterized));

			parameterized->name = name;

			// configure it to autosave
			parameterized->parameterize(gui);
			gui->loadSettings("settings/" + name + ".xml");

			gui->clear();
			ofLogError() << "Parameterized doesn't support this feature at the moment\n";
			list->addItem(name);
		}

		void save(Parameterized *me) {
			xmlgui::SimpleGui g;
			me->parameterize(&g);
			string name = me->name;
			g.saveSettings("settings/"+name+".xml");
		}

	private:
		int choice;
		int lastChoice;
		List *list;
		vector<pair<string, Parameterized *> > parameterizeds;
		xmlgui::SimpleGui *gui;
	};
}

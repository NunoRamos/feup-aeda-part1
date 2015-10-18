#ifndef OPTIONMENU_H
#define OPTIONMENU_H

#include "../menu.h"
#include<string>
#include<utility>
#include<vector>

using namespace std;

class OptionMenu : public Menu{
public:
	OptionMenu(AdData* adData, unsigned int height, unsigned int width);
	OptionMenu(AdData* adData, unsigned int height, unsigned int width, char borderChar);
	void print();
	void addOption(string name, void(*function)(AdData* adData));
	void createMenu();
private:
	AdData* adData;
	vector<pair<string, void (*)(AdData*)>> functions;

};

#endif

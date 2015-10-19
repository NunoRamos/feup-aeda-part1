#ifndef OPTIONMENU_H
#define OPTIONMENU_H

#include "../menu.h"
#include<string>
#include<utility>
#include<vector>

using namespace std;

class OptionMenu : public Menu{
public:
	OptionMenu(Data* data, unsigned int height, unsigned int width);
	OptionMenu(Data* data, unsigned int height, unsigned int width, char borderChar);
	void print();
	void addOption(string name, void(*function)(Data* data));
	void createMenu();
private:
	vector<pair<string, void (*)(Data*)>> functions;
};

#endif

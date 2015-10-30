#ifndef OPTIONMENU_H
#define OPTIONMENU_H

#include "../menu.h"
#include<string>
#include<utility>
#include<vector>

using namespace std;

class OptionMenu : public Menu{
public:
	OptionMenu(Data* data, unsigned int height = 20, unsigned int width = 50, char borderChar = '#');
	void print();
	void addOption(string name, void(*function)(Data* data));
	void createMenu();
private:
	vector<pair<string, void (*)(Data*)>> functions;
};

#endif

#ifndef MENU_H
#define MENU_H

#include<string>
#include <utility>
#include<vector>

using namespace std;

class Menu{
public:
	Menu(unsigned int height, unsigned int width);
	Menu(unsigned int height, unsigned int width, char borderChar);
	void setBorderChar(char borderChar);
	char getBorderChar();
	void print();
	void createMenu();
	void addOption(string name, void(*function)() );
private:
	char borderChar;
	unsigned int height, width;
	unsigned int topMargin, leftMargin;
	vector<pair<string, void (*)()>> functions;
};

#endif

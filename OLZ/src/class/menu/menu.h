#ifndef MENU_H
#define MENU_H


#include"../adData/adData.h"

using namespace std;


class Menu{
public:
	Menu(AdData* adData, unsigned int height, unsigned int width);
	Menu(AdData* adData, unsigned int height, unsigned int width, char borderChar);
	void setBorderChar(char borderChar);
	char getBorderChar();
	virtual void print() = 0;
	void createMenu(); //may have to change this to a derived class that does things separately.
private:
	char borderChar;
	unsigned int height, width;
	unsigned int topMargin, leftMargin;
	AdData* adData;
};

#endif

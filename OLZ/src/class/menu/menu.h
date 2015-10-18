#ifndef MENU_H
#define MENU_H


#include"../adData/adData.h"

using namespace std;


class Menu{
public:
	Menu(unsigned int height, unsigned int width);
	Menu(unsigned int height, unsigned int width, char borderChar);
	void setBorderChar(char borderChar);
	char getBorderChar();
	virtual void print() = 0;
	virtual void createMenu() = 0;
protected:
	char borderChar;
	unsigned int height, width;
	unsigned int topMargin, leftMargin;
};

#endif

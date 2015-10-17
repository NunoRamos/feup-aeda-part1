#ifndef MENU_H
#define MENU_H

#include<string>
#include<utility>
#include<vector>
#include"../adData/adData.h"

using namespace std;

template <class T>
class Menu{
public:
	Menu(T* info, unsigned int height, unsigned int width);
	Menu(T* info, unsigned int height, unsigned int width, char borderChar);
	void setBorderChar(char borderChar);
	char getBorderChar();
	void print();
	void createMenu(); //may have to change this to a derived class that does things separately.
	void addOption(string name, void(*function)(AdData* adData));
private:
	char borderChar;
	unsigned int height, width;
	unsigned int topMargin, leftMargin;
	vector<pair<string, void (*)(T*)>> functions;
	T* info;
};

#endif

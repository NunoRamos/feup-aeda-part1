#include"menu.h"
#include<iostream>
#include<string>
#include<sstream>


Menu::Menu(AdData* adData, unsigned int height, unsigned int width)
: Menu(adData, height, width, '#'){

}

Menu::Menu(AdData* adData, unsigned int height, unsigned int width, char borderChar){
	this->height = height;
	this->width = width;
	this->borderChar = borderChar;
	this->adData = adData;
	topMargin = 1;
	leftMargin = 1;
}

void Menu::setBorderChar(char borderChar){
	this->borderChar = borderChar;
}

char Menu::getBorderChar(){
	return borderChar;
}

#include "adDisplayMenu.h"
#include <sstream>
#include <iostream>

AdDisplayMenu::AdDisplayMenu(Data* data, unsigned int height, unsigned int width, Advertisement* ad):
	Menu(data, height, width, borderChar){
	this->ad = ad;
}

AdDisplayMenu::AdDisplayMenu(Data* data, unsigned int height, unsigned int width, char borderChar, Advertisement* ad):
	Menu(data, height, width, borderChar){
	this->ad = ad;
}

void AdDisplayMenu::print(){
	//first line, only borderChar
	for(unsigned int i = 0; i < width; i++)
		cout << borderChar;

	cout << endl;

	//includes top margin with is a line full of spaces, with borderChar on either side
	for (unsigned int i = 0; i < topMargin; i++){
		cout << borderChar << string(width-2, ' ') << borderChar << endl;
	}

	//display title
	cout << borderChar << string(leftMargin, ' ') << ad->getTitle() << ' ' << borderChar << endl;

	//a white line between title and description
	for (unsigned int i = 0; i < topMargin; i++){
		cout << borderChar << string(width-2, ' ') << borderChar << endl;
	}

	//used to add menu options correctly
	string description = ad->getDescription();
	unsigned int widthForString = width - (2 + leftMargin + 1);
	for(unsigned int i = 0; i < description.length(); i++){
		string line(leftMargin, ' ');
		cout << borderChar << line
				<< description.substr(i*widthForString, widthForString-1)
				<< ' ' << borderChar << endl;
	}

	//a white line between description and lower border
		for (unsigned int i = 0; i < topMargin; i++){
			cout << borderChar << string(width-2, ' ') << borderChar << endl;
		}

	//last line
	for(unsigned int i = 0; i < width; i++)
		cout << borderChar;

	cout << endl;
}

void AdDisplayMenu::createMenu(){

}

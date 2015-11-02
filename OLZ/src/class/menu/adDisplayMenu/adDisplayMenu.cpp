#include "../../../menus.h"
#include "adDisplayMenu.h"
#include <sstream>
#include <iostream>

AdDisplayMenu::AdDisplayMenu(Data* data, Advertisement* ad, unsigned int height, unsigned int width, char borderChar):
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

	//a white line between description and contacts
		for (unsigned int i = 0; i < topMargin; i++){
			cout << borderChar << string(width-2, ' ') << borderChar << endl;
		}


		//if()

		//a white line between contacts and options
		cout << borderChar << string(width-2, ' ') << borderChar << endl;



		//im interested
		string imInterested = " 1 - I'm interested";
		string exit = " 2 - Exit";
		cout << borderChar << imInterested << string(width-imInterested.length()-2, ' ') << borderChar << endl;
		cout << borderChar << exit << string(width-exit.length()-2, ' ') << borderChar << endl;

	//last line
	for(unsigned int i = 0; i < width; i++)
		cout << borderChar;

	cout << endl;
}

void AdDisplayMenu::createMenu(){
	AdDisplayMenu::print();
	int input;
	unsigned int i = 0;
	cout << "What option would you like to choose?" << endl;
	do{
		if(i > 0)
			cout << "Please introduce a valid option." << endl;
		cin >> input;
	}while(input < 1 || input > 2);

	if(input == 1)
		interested(ad->getOwner());
}

#include "optionMenu.h"
#include <iostream>
#include <sstream>

OptionMenu::OptionMenu(AdData* adData, unsigned int height, unsigned int width) :
Menu(height, width){
	this->adData = adData;
}

OptionMenu::OptionMenu(AdData* adData, unsigned int height, unsigned int width, char borderChar) :
Menu(height, width, borderChar){
	this->adData = adData;
}

void OptionMenu::print(){
	//first line, only borderChar
	for(unsigned int i = 0; i < width; i++)
		cout << borderChar;

	cout << endl;

	//includes top margin with is a line full of spaces, with borderChar on either side
	for (unsigned int i = 0; i < topMargin; i++){
		cout << borderChar << string(width-2, ' ') << borderChar << endl;
	}

	//used to add menu options correctly
	stringstream ss;
	for(unsigned int i = 0; i < functions.size(); i++){
		string line(leftMargin, ' ');
		ss.str("");
		ss << i+1 << " - ";
		unsigned int widthLeft = width - (1 + leftMargin + ss.str().length() + functions[i].first.length());
		cout << borderChar << line
				<< ss.str() << functions[i].first
				<< string(widthLeft-1, ' ') << borderChar << endl;
	}

	//fills the rest of the menu with empty lines, with border
	for (unsigned int i = functions.size(); i < height-(2+topMargin); i++){
		cout << borderChar << string(width-2, ' ') << borderChar << endl;
	}

	//last line
	for(unsigned int i = 0; i < width; i++)
		cout << borderChar;

	cout << endl;
}

void OptionMenu::addOption(string name, void(*function)(AdData* adData)){
	functions.push_back(pair<string, void(*)(AdData*)>(name, function));
}

void OptionMenu::createMenu(){
	unsigned int input;
	print();
	cin >> input;
	while (input <= 0 || input > functions.size()){
		cout << "Please introduce a valid option.\n";
		cin >> input;
	}


}
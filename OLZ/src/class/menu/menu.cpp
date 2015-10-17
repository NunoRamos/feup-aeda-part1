#include"menu.h"
#include<iostream>
#include<string>
#include<sstream>


Menu::Menu(unsigned int height, unsigned int width) : Menu(height, width, '#'){

}

Menu::Menu(unsigned int height, unsigned int width, char borderChar){
	this->height = height;
	this->width = width;
	this->borderChar = borderChar;
	topMargin = 1;
	leftMargin = 1;
}

void Menu::setBorderChar(char borderChar){
	this->borderChar = borderChar;
}

char Menu::getBorderChar(){
	return borderChar;
}

void Menu::print(){
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
		ss << i+1;
		unsigned int widthLeft = width - (1 + leftMargin + ss.str().length() + 3 + functions[i].first.length());
		cout << borderChar << line
				<< i+1 << " - " << functions[i].first
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

void Menu::createMenu(){
	unsigned int input;
	bool showMsg = false;
	print();
	cin >> input;
	while (input <= 0 || input > functions.size()){
		cout << "Please introduce a valid option.\n";
		cin >> input;
	}

	functions[input-1].second();
}

void Menu::addOption(string name, void(*function)()){
	functions.push_back(pair<string, void(*)()>(name, function));
}


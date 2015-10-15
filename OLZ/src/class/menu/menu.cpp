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
	for(unsigned int i = 0; i < width; i++)
		cout << borderChar;

	cout << endl;

	for (unsigned int i = 0; i < topMargin; i++){
		cout << borderChar << string(width-2, ' ') << borderChar << endl;
	}

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

	for (unsigned int i = functions.size(); i < height-(2+topMargin); i++){
			cout << borderChar << string(width-2, ' ') << borderChar << endl;
		}

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


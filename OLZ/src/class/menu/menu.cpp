#include"menu.h"
#include<iostream>
#include<string>
#include<sstream>

template <class T>
Menu<T>::Menu(T* info, unsigned int height, unsigned int width) : Menu(info, height, width, '#'){

}

template <class T>
Menu<T>::Menu(T* info, unsigned int height, unsigned int width, char borderChar){
	this->height = height;
	this->width = width;
	this->borderChar = borderChar;
	this->info = info;
	topMargin = 1;
	leftMargin = 1;
}

template <class T>
void Menu<T>::setBorderChar(char borderChar){
	this->borderChar = borderChar;
}

template <class T>
char Menu<T>::getBorderChar(){
	return borderChar;
}

template <class T>
void Menu<T>::print(){
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

template <class T>
void Menu<T>::createMenu(){
	unsigned int input;
	bool showMsg = false;
	print();
	cin >> input;
	while (input <= 0 || input > functions.size()){
		cout << "Please introduce a valid option.\n";
		cin >> input;
	}

	functions[input-1].second(info);
}

template <class T>
void Menu<T>::addOption(string name, void(*function)(AdData* adData)){
	//may get an error below, still need to test
	functions.push_back(pair<string, void(*)(AdData*)>(name, function));
}

template class Menu<AdData>; //needed because of c++ and template class issues
//more info:
//http://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor

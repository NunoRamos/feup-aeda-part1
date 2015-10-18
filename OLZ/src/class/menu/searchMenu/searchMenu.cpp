#include "searchMenu.h"
#include <iostream>
#include <sstream>
#include <math.h>

SearchMenu::SearchMenu(AdData* adData, unsigned int height, unsigned int width, vector<Advertisement*> results) :
	Menu(height, width){
	this->adData = adData;
	this->results = results;
	page = 0;
	adsPerPage = 7;
}

SearchMenu::SearchMenu(AdData* adData, unsigned int height, unsigned int width, char borderChar,
		vector<Advertisement*> results) :
	Menu(height, width, borderChar){
	this->adData = adData;
	this->results = results;
	page = 0;
	adsPerPage = 7;
}

void SearchMenu::setAdsPerPage(unsigned int adsPerPage){
	this->adsPerPage = adsPerPage;
}

unsigned int SearchMenu::getAdsPerPage(){
		return adsPerPage;
}

void SearchMenu::print(){
	//first line, only borderChar
		for(unsigned int i = 0; i < width; i++)
			cout << borderChar;

		cout << endl;

		//includes top margin with is a line full of spaces, with borderChar on either side
		for (unsigned int i = 0; i < topMargin; i++){
			cout << borderChar << string(width-2, ' ') << borderChar << endl;
		}

		//calculates how many ads in page
		unsigned int adLimit = adsPerPage;
		if(trunc(static_cast<double> (results.size() / adsPerPage)) == page)
			adLimit = results.size() % adsPerPage;

		//used to add menu options correctly
		stringstream ss;
		for(unsigned int i = 0; i < adLimit; i++){
			string line(leftMargin, ' ');
			ss.str("");
			ss << i+1 << " - ";
			unsigned int widthLeft = width -
					(1 + leftMargin + ss.str().length() + results[page*adsPerPage+i]->getTitle().length());
			cout << borderChar << line
					<< ss.str() << results[page*adsPerPage+i]->getTitle()
					<< string(widthLeft-1, ' ') << borderChar << endl;
		}

		//fills the rest of the menu with empty lines, with border
		for (unsigned int i = adLimit; i < height-(2+topMargin); i++){
				cout << borderChar << string(width-2, ' ') << borderChar << endl;
			}

		//last line
		for(unsigned int i = 0; i < width; i++)
				cout << borderChar;

		cout << endl;
}

void SearchMenu::createMenu(){
	unsigned int input;
	unsigned int adLimit = adsPerPage;
	if(trunc(static_cast<double> (results.size() / adsPerPage)) == page)
	adLimit = results.size() % adsPerPage;
	print();
	cin >> input;
	while (input <= 0 || input > adLimit){
		cout << "Please introduce a valid option.\n";
		cin >> input;
	}

}

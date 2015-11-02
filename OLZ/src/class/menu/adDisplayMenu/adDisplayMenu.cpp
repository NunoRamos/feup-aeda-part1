#include "../../../menus.h"
#include "adDisplayMenu.h"
#include <sstream>
#include <iostream>

AdDisplayMenu::AdDisplayMenu(Data* data, Advertisement* ad, unsigned int height,
		unsigned int width, char borderChar) :
		Menu(data, height, width, borderChar) {
	this->ad = ad;
	ad->incrementViews();
}

void AdDisplayMenu::print() {
	//first line, only borderChar
	for (unsigned int i = 0; i < width; i++)
		cout << borderChar;

	cout << endl;

	//includes top margin with is a line full of spaces, with borderChar on either side
	for (unsigned int i = 0; i < topMargin; i++)
		emptyLine();

	//display title
	string title = ad->getTitle();
	cout << borderChar << " " << title
			<< string(width - 3 - title.length(), ' ') << borderChar << endl;

	//a white line between title and description
	for (unsigned int i = 0; i < topMargin; i++)
		emptyLine();

	//used to add menu options correctly
	string description = ad->getDescription();

	cout << borderChar << " " << description
			<< string(width - 3 - description.length(), ' ') << borderChar
			<< endl;

	//a white line between description and contacts
	for (unsigned int i = 0; i < topMargin; i++)
		emptyLine();

	bool showEmail = ad->getOwner()->getShowEmail();
	bool showName = ad->getOwner()->getShowName();
	bool showPhoneNumber = ad->getOwner()->getShowPhoneNumber();

	if (showEmail || showName || showPhoneNumber) {
		if (showEmail) {
			string email = ad->getOwner()->getEmail();
			cout << borderChar << " Email: " << email
					<< string(width - 2 - 8 - email.length(), ' ') << borderChar
					<< endl;
		}

		if (showName) {
			string name = ad->getOwner()->getName();
			cout << borderChar << " Name: " << name
					<< string(width - 2 - 7 - name.length(), ' ') << borderChar
					<< endl;
		}

		if (showPhoneNumber) {
			string phoneNumber = ad->getOwner()->getPhoneNumber();
			cout << borderChar << " Phone Number: " << phoneNumber
					<< string(width - 2 - 15 - phoneNumber.length(), ' ')
					<< borderChar << endl;
		}
		emptyLine();
	}
	stringstream ss;
	ss << ad->getViews();
	cout << borderChar << " Views: " << ss.str() << string(width-2-8-ss.str().length(), ' ') << borderChar << endl;
	emptyLine();

	//im interested
	string imInterested = " 1 - I'm interested";
	string exit = " 2 - Exit";
	cout << borderChar << imInterested
			<< string(width - imInterested.length() - 2, ' ') << borderChar
			<< endl;
	cout << borderChar << exit << string(width - exit.length() - 2, ' ')
			<< borderChar << endl;

	emptyLine();

	//last line
	for (unsigned int i = 0; i < width; i++)
		cout << borderChar;

	cout << endl;
}

void AdDisplayMenu::createMenu() {
	clearScreen();
	AdDisplayMenu::print();
	int input;
	unsigned int i = 0;
	cout << "What option would you like to choose?" << endl;
	do {
		if (i > 0)
			cout << "Please introduce a valid option." << endl;
		cin >> input;
		cin.ignore();
		cin.clear();
		i++;
	} while (input < 1 || input > 2);

	if (input == 1)
		interested(ad->getOwner());
}


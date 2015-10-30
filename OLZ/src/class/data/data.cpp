#include "data.h"
#include "../../sequentialSearch.h"
#include "../advertisement/purchase/purchase.h"

#include<fstream>
#include <iostream>
#include <sstream>

Data::Data() {
	signedInUser = NULL;
}

Data::~Data() {
	int i;
	//	saveUsers();
	for (int i = 0; i < advertisements.size(); i++) {
		delete advertisements[i];
	}
	cin >> i;
}

bool Data::signIn(const string &email, const string &password) {
	if (users.size() == 0)
		return false;

	User tmp;
	tmp.setEmail(email);
	int user = sequentialSearch(users, tmp);

	if (user == -1)
		return false;

	if (users[user].signIn(password)) {
		signedInUser = &users[user];
		return true;
	}
	return false;
}

bool Data::signUp(User user) { //may add a condition to see if a user with the same email already exists
	int i = -1; //sequentialSearch(users);
	if (i != -1)
		cout << "Client is already created\n";
	else
		users.push_back(user);
	return true;
}

bool Data::loadUsers() {
	ifstream userFile;
	int numberOfFiles;
	stringstream ss;

	userFile.open((path + "info.txt").c_str());
	if (!userFile.is_open())
		return false;

	userFile >> numberOfFiles;
	userFile.close();

	User temp;

	for (unsigned int i = 0; i < numberOfFiles; i++) {
		ss << "user" << i << ".txt";
		userFile.open((path + ss.str()).c_str());
		if (userFile.is_open()) {
			userFile >> temp;
			users.push_back(temp);
			cout << users[i].getName() << endl;
		}
		userFile.close();
		ss.str("");
	}

	return true;
}

bool Data::saveUsers() {
	char separationChar = '\n';
	ofstream userFile;
	stringstream ss;

	userFile.open((path + "info.txt").c_str()); //ofstream::out | ofstream::trunc
	if (!userFile.is_open())
		return false;

	userFile << users.size();
	userFile.close();

	for (unsigned int i = 0; i < users.size(); i++) {
		ss << "user" << users[i].getId() << ".txt";
		userFile.open((path + ss.str()).c_str());
		if (userFile.is_open()) {
			userFile << users[i];
			userFile.close();
		}
		ss.str("");
	}
	return true;
}

void Data::removeAdvertisement(Advertisement* ad) {
	ad->getOwner()->removeAdvertisement(ad);
	int adIndex = sequentialSearch(advertisements, ad);

	if (adIndex == -1)
		return;

	delete advertisements[adIndex];
	advertisements.erase(advertisements.begin() + adIndex);
}

void Data::addAdvertisement(Advertisement* ad) {
	advertisements.push_back(ad);
	ad->getOwner()->addAdvertisement(ad);
}

vector<Advertisement*> Data::searchForAds(string text) {
	vector<Advertisement*> results;

	for (unsigned int i = 0; i < advertisements.size(); i++) {
		if (advertisements[i]->searchForText(text))
			results.push_back(advertisements[i]);
	}

	return results;
}

void Data::signOut() {
	signedInUser == NULL;
}

User* Data::getSignedInUser() const {
	return signedInUser;
}

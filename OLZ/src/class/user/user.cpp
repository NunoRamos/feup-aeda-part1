#include "user.h"
#include "../../sequentialSearch.h"
#include "../advertisement/purchase/purchase.h"
#include <iostream>

//unsigned int User::nextId = 0;

User::User() {
	showEmail = true;
	showName = true;
	showPhoneNumber = true;
}

User::User(string email, string password, string name, string phoneNumber, Location location) : User() {
	this->email = email;
	this->password = password;
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->location = location;
}

User::User(string email, string password, string name, string phoneNumber, string location) : User(email, password, name, phoneNumber, Location(location)) { }

bool User::signIn(string password) const {
	if (this->password == password)
		return true;
	return false;
}

string User::getEmail() const {
	return email;
}

string User::getPassword() const {
	return password;
}

string User::getName() const {
	return name;
}

string User::getPhoneNumber() const {
	return phoneNumber;
}

Location User::getLocation() const {
	return location;
}

string User::getLocationString() const {
	return location.toString();
}

void User::setEmail(string email) {
	this->email = email;
}

istream& operator>>(istream& in, User &user) {
	/*char separationChar = '\n';
	string line;
	in >> line;

	int cursor = line.find(separationChar);
		user.email = line.substr(0, cursor);

	 line = line.substr(cursor + 1);
	 cursor = line.find(separationChar);
	 user.password = line.substr(0, cursor);

	 line = line.substr(cursor + 1);
	 cursor = line.find(separationChar);
	 user.name = line.substr(0, cursor);

	 line = line.substr(cursor + 1);
	 cursor = line.find(separationChar);
	 user.phoneNumber = line.substr(0, cursor);

	 line = line.substr(cursor + 1);
	 cursor = line.find(separationChar);
	 user.location = Location(line);*/
	string loc;
	getline(in, user.email);
	getline(in, user.password);
	getline(in, user.name);
	getline(in, user.phoneNumber);
	getline(in, loc);
	user.location = Location(loc);

	for (unsigned int i = 0; i < user.advertisements.size(); i++) {
			in >> *user.advertisements[i];
		}

	return in;
}

void User::removeAdvertisement(Advertisement* ad) {
	int adIndex = sequentialSearch(advertisements, ad);
	if (adIndex != -1) {
		advertisements.erase(advertisements.begin() + adIndex);
	}
}

void User::addAdvertisement(Advertisement *newAdvertisement) {
	advertisements.push_back(newAdvertisement);
}

bool User::operator==(const User & u1) const{
	return (this->email == u1.email);
}

ostream& operator<<(ostream& out, const User &user) {
	char separationChar = '\n';

	out << user.email << separationChar << user.password << separationChar
			<< user.name << separationChar << user.phoneNumber << separationChar
			<< user.location <<separationChar;

	for (unsigned int i = 0; i < user.advertisements.size(); i++) {
		out << *user.advertisements[i];
	}

	return out;
}

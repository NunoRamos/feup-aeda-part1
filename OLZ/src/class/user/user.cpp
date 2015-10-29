#include "user.h"

unsigned int User::nextId=0;

User::User() {
	id=nextId;
	nextId++;

}

User::User(string email, string password, string name, string phoneNumber,
		Date signUpDate, Location location) {
	this->email = email;
	this->password = password;
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->location = location;
	this->signUpDate = signUpDate;
	id=nextId;
	nextId++;
}

User::User(string email, string password, string name, string phoneNumber,
		Date signUpDate, string location) {
	this->email = email;
	this->password = password;
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->location = Location(location);
	this->signUpDate = signUpDate;
	id=nextId;
	nextId++;
}

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
	return location.getString();
}

unsigned int User::getId() const{

	return id;
}
istream& operator>>(istream& in, User user) {
	char separationChar = '\n';
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
	user.location = Location(line);

	return in;
}

void User::removeAdvertisement(unsigned int id) {
	unsigned int i;

	for (i = 0; i < advertisements.size(); i++) {
		if (advertisements[i]->getId() == id)
			break;
	}

	if (i != advertisements.size()) {
		advertisements.erase(advertisements.begin() + i);
	}
}

void User::addAdvertisement(Advertisement *newAdvertisment){

	advertisements.push_back(newAdvertisment);

}

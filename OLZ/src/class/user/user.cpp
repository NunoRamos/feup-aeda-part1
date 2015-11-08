#include "user.h"
#include "../../sequentialSearch.h"
#include "../advertisement/purchase/purchase.h"
#include "../advertisement/sale/sale.h"
#include <iostream>
#include<sstream>

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

bool User::getShowEmail() const{
	return showEmail;
}

bool User::getShowName() const{
	return showName;
}

bool User::getShowPhoneNumber() const{
	return showPhoneNumber;
}

void User::setEmail(string email) {
	this->email = email;
}

void User::setShowEmail(bool show){
	this->showEmail = show;
}

void User::setShowName(bool show){
	this->showName = show;
}

void User::setShowPhoneNumber(bool show){
	this->showPhoneNumber = show;
}

vector<string> User::fillWithTitles() const{
	vector<string> titles;
	for(int i=0;i<advertisements.size();i++){
		titles.push_back(advertisements[i]->getTitle());
	}
	return titles;
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
	int numberOfAds;
	unsigned int views;
	float price;
	bool negotiable;
	Category category;
	string temp,title,description;
	stringstream ss;
	Date creationDate;
	char type;

	getline(in, user.email);
	getline(in, user.password);
	getline(in, user.name);
	getline(in, user.phoneNumber);
	getline(in, temp);
	user.location = Location(temp);
	getline(in,temp);
	ss<<temp;
	ss>>numberOfAds;
	ss.str("");
	for (unsigned int i = 0; i < numberOfAds; i++) {
		ss.str("");
		getline(in,temp);
		ss<<temp;
		ss>>type;
		ss.str("");
		getline(in,title);
		getline(in,temp);
		ss<<temp;
		ss>>views;
		ss.str("");
		getline(in,temp);
		category=stringToCategory(temp);
		getline(in,description);
		getline(in,temp);
		Date date(temp);
		creationDate=date;
		getline(in,temp);
		ss<<temp;
		ss>>price;
		ss.str("");
		getline(in,temp);
		if(temp=="1")
			negotiable=true;
		else negotiable=false;

		if(type=='P'){
			Advertisement* ad=new Purchase(&user,title,category,description,price);
			ad->setNegotiable(negotiable);
			ad->setCreationDate(creationDate);
			cout<<"Name: "<<ad->getOwner()->getName();
			user.advertisements.push_back(ad);
		}
		else {
			Advertisement* ad=new Sale(&user,title,category,description,New,price);
			ad->setNegotiable(negotiable);
			ad->setCreationDate(creationDate);
			user.advertisements.push_back(ad);
		}
		//in >> *user.advertisements[i];

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
			<< user.location <<separationChar<<user.advertisements.size()<<separationChar;

	for (unsigned int i = 0; i < user.advertisements.size(); i++) {
		out << *user.advertisements[i];
	}
	return out;
}

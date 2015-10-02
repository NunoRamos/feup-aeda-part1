#include"User.h"

string separationChar = "|";

User::User(){

}

User::User(string email, string name, string phoneNumber, Date signUpDate, Location location){
	this->email = email;
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->location = location;
}

string User::getEmail() const{
	return email;
}

string User::getName() const{
	return name;
}

string User::getPhoneNumber() const{
	return phoneNumber;
}


Location User::getLocation() const{
	return location;
}

string User::getLocationString() const{
	return location.getString();
}

istream& operator>>(istream& in, User user){
	string line;
	in >> line;

	int cursor = line.find(separationChar);
	user.login = line.substr(0, cursor);

	line = line.substr(cursor+1);
	cursor = line.find(separationChar);
	user.name = line.substr(0, cursor);

	line = line.substr(cursor+1);
	cursor = line.find(separationChar);
	user.email = line.substr(0, cursor);

	line = line.substr(cursor+1);
	cursor = line.find(separationChar);
	user.phoneNumber = line.substr(0, cursor);

	line = line.substr(cursor+1);
	cursor = line.find(separationChar);
	user.signUpDate = new Date(line);

	return in;
}

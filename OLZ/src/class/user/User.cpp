#include"User.h"

string separationChar = "|";

User::User(){

}

User::User(string &login, string &name, string &email, string phoneNumber, Date signUpDate){
	this->login = login;
	this->name = name;
	this->email = email;
	this->phoneNumber = phoneNumber;
	this->signUpDate = signUpDate;
}

string User::getLogin() const{
	return login;
}

string User::getName() const{
	return name;
}

string User::getEmail() const{
	return email;
}

string User::getPhoneNumber() const{
	return phoneNumber;
}

string User::getDate() const{
	return signUpDate.getDate();
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

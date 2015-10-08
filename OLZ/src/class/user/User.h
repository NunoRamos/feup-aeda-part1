#ifndef USER_H
#define USER_H

#include<string>
#include"../date/Date.h"
#include"../location/Location.h"

using namespace std;

class User{
public:
	User();
	User(string email, string name, string phoneNumber, Date signUpDate, Location location);
	User(string email, string name, string phoneNumber, Date signUpDate, string location);
	string getEmail() const;
	string getName() const;
	string getPhoneNumber() const;
	Location getLocation() const;
	string getLocationString() const;
	friend istream& operator>>(istream& in, User user);
protected:
	string email, name, phoneNumber;
	Location location;
private:
	static string separationChar;
};

#endif

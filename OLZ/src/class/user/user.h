#ifndef USER_H
#define USER_H

#include<string>
#include<vector>

#include "../advertisement/advertisement.h"
#include "../date/date.h"
#include "../location/location.h"

using namespace std;

class Advertisement;//add to do this to allow cyclic calling of class

class User{
public:
	User();
	User(string email, string password, string name, string phoneNumber, Date signUpDate, Location location);
	User(string email, string password, string name, string phoneNumber, Date signUpDate, string location);
	bool signIn(string password) const;
	string getEmail() const;
	string getName() const;
	string getPhoneNumber() const;
	Location getLocation() const;
	string getLocationString() const;
	friend istream& operator>>(istream& in, User user);
	void removeAdvertisement(unsigned int id);
protected:
	vector<Advertisement*> advertisements;
	string email, password, name, phoneNumber;
	Date signUpDate;
	Location location;
};

#endif

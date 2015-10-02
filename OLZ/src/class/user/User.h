#IFNDEF USER_H
#DEFINE USER_H

#include<string>
#include"../date/Date.h"

using namespace std;

class User{
public:
	User();
	User(string &login, string &name, string &email, string phoneNumber, Date signUpDate);
	string getLogin() const;
	string getName() const;
	string getEmail() const;
	string getPhoneNumber() const;
	string getDate() const;
	friend istream& operator>>(istream& in, User user);
private:
	string login, name, email, phoneNumber;
	Date signUpDate;
};

#ENDIF

#ifndef DATA_H
#define DATA_H

#include<vector>

#include "../user/user.h"

using namespace std;

class Data{
public:
	Data();
	bool login(string email, string password);
	bool addUser(User user);
	bool loadUsers(); ///< Loads user data from specified file
	bool saveUsers(); ///< Saves user data to specified file
	void removeAdvertisement(unsigned int id);
	void addAdvertisement(Advertisement* ad);
	vector<Advertisement*> searchForAds(string text); //still not sure what type of data to return
private:
	vector<Advertisement*> advertisements;
	vector<User> users;
	User* signedInUser;
	const string path = "../../../data/users.txt"; //used to save and load users. still not fully implemented
};

//Better option may be writing to a binary file and end every input with \n

#endif

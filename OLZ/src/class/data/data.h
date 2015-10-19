#ifndef DATA_H
#define DATA_H

#include<vector>

#include "../user/user.h"

using namespace std;

class Data{
public:
	Data();
	Data(string path);
	bool loadUsers(); ///< Loads user data from specified file
	bool saveUsers(); ///< Saves user data to specified file
	void removeAdvertisement(unsigned int id);
	void addAdvertisement(Advertisement* ad);
	vector<Advertisement*> searchForAds(string text); //still not sure what type of data to return
private:
	vector<Advertisement*> advertisements;
	vector<User> users;
	const string path = "../../../data/users.txt";
};

//TODO move separationChar to a constants file
//Better option may be writing to a binary file and end every input with \n

#endif

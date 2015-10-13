#ifndef UserData_H
#define UserData_H

#include<vector>
#include"../user/User.h"

using namespace std;

class UserData{
public:
	UserData(string path);
	bool loadUsers(); ///< Loads user data from specified file
	bool saveUsers(); ///< Saves user data to specified file
private:
	vector<User> users;
	const string path = "../../../data/users.txt";
};

//TODO move separationChar to a constants file
//Better option may be writing to a binary file and end every input with \n

#endif

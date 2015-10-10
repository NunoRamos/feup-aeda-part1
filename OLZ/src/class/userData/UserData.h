#ifndef UserData_H
#define UserData_H

#include<vector>
#include"../user/User.h"

using namespace std;

class UserData{
public:
	UserData(string path);
	bool loadUsers();
	bool saveUsers();
private:
	vector<User> users;
	const string path = "../../../data/users.txt";
	static string separationChar;
};

//TODO move separationChar to a constants file
//Better option may be writing to a binary file and end every input with \n

#endif

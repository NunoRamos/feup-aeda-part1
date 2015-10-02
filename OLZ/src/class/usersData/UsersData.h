#IFNDEF USERSDATA_H
#DEFINE USERSDATA_H

#include<vector>
#include"../user/User.h"

using namespace std;

class UsersData{
public:
	UsersData(string path);
	bool loadUsers();
	bool saveUsers();
private:
	vector<User> users;
	const string path = "../../../data/users.txt";
};

#ENDIF

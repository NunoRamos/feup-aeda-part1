#include "UserData.h"

#include<fstream>

string UserData::separationChar = "|";

UserData::UserData(string path) : path(path){

}

bool UserData::loadUsers(){
	ifstream userFile;
	userFile.open(path.c_str(), ofstream::in);

	if(!userFile.is_open())
		return false;

	while(!userFile.eof()){
		User user;
		//userFile >> user;
		users.push_back(user);
	}
	return true;
}

bool UserData::saveUsers(){
	ofstream userFile;
	userFile.open(path.c_str(), ofstream::out | ofstream::trunc);

	if(!userFile.is_open())
		return false;

	for(unsigned int i = 0; i < users.size(); i++){
		userFile << users[i].getEmail() << separationChar << users[i].getName() << separationChar
				<< users[i].getPhoneNumber() << separationChar << users[i].getLocationString() << separationChar;
	}
	return true;
}

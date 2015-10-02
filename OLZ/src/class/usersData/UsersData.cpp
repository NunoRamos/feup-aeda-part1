#include"UsersData.h"
#include<fstream>

string separationChar = "|";

UsersData::UsersData(string path) : this->path(path){

}

bool UsersData::loadUsers(){
	ifstream userFile;
	userFile.open(path.c_str(), ofstream::in);

	if(!userFile.is_open())
		return false;

	while(!userFile.eof()){
		User user();
		userFile >> user;
		users.push_back(user);
	}
}

bool UsersData::saveUsers(){
	ofstream userFile;
	userFile.open(path.c_str(), ofstream::out | ofstream::trunc);

	if(!userFile.is_open())
		return false;

	for(unsigned int i = 0; i < users.size(); i++){
		userFile << users[i].getLogin() << separationChar << users[i].getName() << separationChar
				<< users[i].getEmail() << separationChar << users[i].getPhoneNumber() << separationChar
				<< users[i].getDate << endl;
	}

}

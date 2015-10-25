#include "data.h"

#include<fstream>

Data::Data(){
	signedInUser = NULL;
}

bool Data::login(string email, string password){
	if(users.size() == 0)
		return false;

	unsigned int i;
	for(i = 0; i < users.size(); i++){
		if(users[i].getEmail() == email)
			break;
	}

	if(users[i].login(password)){
		signedInUser = &users[i];
		return true;
	}
	return false;
}

bool Data::addUser(User user){//may add a condition to see if a user with the same email already exists
	users.push_back(user);
	return true;
}

bool Data::loadUsers(){
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

bool Data::saveUsers(){
	char separationChar = '\n';
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

void Data::removeAdvertisement(unsigned int id)
{
	unsigned int i;
	for(i=0; i < advertisements.size(); i++)
		if (advertisements[i]->getId() == id)
			break;

	if(i != advertisements.size()){
		delete advertisements[i];
		advertisements.erase(advertisements.begin() + i);
	}
}

void Data::addAdvertisement(Advertisement* ad){
	advertisements.push_back(ad);
}

vector<Advertisement*> Data::searchForAds(string text){
	vector<Advertisement*> results;

	for(unsigned int i = 0; i < advertisements.size(); i++){
		if(advertisements[i]->searchForText(text))
			results.push_back(advertisements[i]);
	}

	return results;
}


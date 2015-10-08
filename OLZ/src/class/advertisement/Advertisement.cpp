#include"Advertisement.h"
#include<ctime>
#include<chrono>

unsigned int Advertisement::id = 0;

Advertisement::Advertisement(string title, Category category){
	this->title = title;
	this->category = category;
	showName = true;
	showEmail = true;
	showPhoneNumber = true;
	id++;
	//TODO: get time and save as creationDate
}

Advertisement::Advertisement(string title, Category category, string description){
	//c++98 does not let us call a constructor in this constructor,
	//so we have to repeat code
	this->title = title;
	this->category = category;
	this->description = description;
	showName = true;
	showEmail = true;
	showPhoneNumber = true;
	id++;
}

unsigned int Advertisement::getId() const{
	return id;
}

string Advertisement::getTitle() const{
	return title;
}

Category Advertisement::getCategory() const{
	return category;
}

string Advertisement::getDescription() const{
	return description;
}

string Advertisement::getImageAt(unsigned int index) const{
	return imagesPath[index];
}

void Advertisement::addImage(string path){
	imagesPath.push_back(path);
}

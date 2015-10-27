#include "advertisement.h"
#include "../menu/adDisplayMenu/adDisplayMenu.h"

#include<ctime>
#include<chrono>

unsigned int Advertisement::id = 0;


Advertisement::Advertisement(User* owner, string title, Category category){
	this->owner = owner;
	this->title = title;
	this->category = category;
	showName = true;
	showEmail = true;
	showPhoneNumber = true;
	id++;
	views=0;
	//TODO: get time and save as creationDate
}

Advertisement::Advertisement(User* owner, string title, Category category, string description)
: Advertisement(owner, title, category){
	this->description = description;
}

Advertisement::~Advertisement(){
	id--;
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

void Advertisement::incrementViews()
{
	views++;
}

bool Advertisement::searchForText(string text) const{
	if(title.find(text, 0) != -1)
		return true;

	if(description.find(text, 0) != -1)
		return true;

	return false;
}


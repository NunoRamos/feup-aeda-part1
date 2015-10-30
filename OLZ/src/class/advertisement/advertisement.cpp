#include "advertisement.h"
#include "../menu/adDisplayMenu/adDisplayMenu.h"


#include<ctime>
#include<chrono>
#include<iostream>

unsigned int Advertisement::nextId = 0;

Advertisement::Advertisement(User* owner, string title){
	this->title=title;
	this->owner=owner;
}

Advertisement::Advertisement(User* owner, string title, Category category){
	this->owner = owner;
	this->title = title;
	this->category = category;
	showName = true;
	showEmail = true;
	showPhoneNumber = true;
	id = nextId;
	nextId++;
	views=0;
	//TODO: get time and save as creationDate
}

Advertisement::Advertisement(User* owner, string title, Category category, string description)
: Advertisement(owner, title, category){
	this->description = description;
}

Advertisement::~Advertisement(){
	nextId--;
}

unsigned int Advertisement::getId() const{
	return id;
}

User* Advertisement::getOwner() const{
	return owner;
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

bool Advertisement::operator==(Advertisement* ad) const{
	return (this->title == ad->title);
}

ostream& operator<<(ostream& out, const Advertisement &ad){
	char separationChar = '\n';
//TODO print category to file, not sure how.
	out << ad.id << separationChar
			<< ad.title << separationChar
			<< ad.views << separationChar
			<< ad.category << separationChar
			<< ad.description << separationChar
			<< ad.creationDate << separationChar;

	return out;
}

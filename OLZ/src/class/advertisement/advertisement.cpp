#include "advertisement.h"
#include "../menu/adDisplayMenu/adDisplayMenu.h"
#include<iostream>
#include<sstream>

unsigned int Advertisement::nextId = 0;

Advertisement::Advertisement(User* owner, string title, Category category, string description, float price){
	this->owner = owner;
	this->title = title;
	this->category = category;
	this->description = description;
	this->price = price;
	negotiable = true;
	id = nextId;
	nextId++;
	views=0;
	//TODO: get time and save as creationDate

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

unsigned int Advertisement::getViews() const{
	return views;
}

float Advertisement::getPrice() const{
	return price;
}

bool Advertisement::isPriceNegotiable() const{
	return negotiable;
}

void Advertisement::setNegotiable(bool negotiable){
	this->negotiable = negotiable;
}

void Advertisement::setTitle(string newTitle){
	this->title=newTitle;
}

void Advertisement::setDescription(string newDescription){
	this->description=newDescription;
}

void Advertisement::setPrice(float newPrice){
	this->price=newPrice;
}

void Advertisement::setCategory(Category newCategory){
	this->category=newCategory;
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
	return (this->id == ad->id);
}

ostream& operator<<(ostream& out, const Advertisement &ad){
	char separationChar = '\n';
	//TODO print category to file, not sure how.
	//does not print id
	out << ad.title << separationChar
			<< ad.views << separationChar
			<< ad.category << separationChar
			<< ad.description << separationChar
			<< ad.creationDate << separationChar;

	return out;
}


istream& operator>>(istream& in, Advertisement &ad){
	stringstream ss;
	string temp;
	//TODO print category from file to variable, not sure how.

	getline(in,ad.title);
	getline(in,temp);
	ss<<temp;
	ss>>ad.views;
	getline(in,ad.title);
	getline(in,temp);   //learn how to read to variable category
	/*ss<<temp;
		ss>>ad.category;*/
	ad.category=Job;
	getline(in,ad.description);
	getline(in,temp);
	Date d1(temp);
	ad.creationDate=d1;

	return in;
}



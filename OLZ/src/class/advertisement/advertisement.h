#ifndef ADVERTISEMENT_H
#define ADVERTISEMENT_H

#include<string>
#include<vector>

#include "../../category.h"
#include "../date/date.h"
#include "../user/user.h"

using namespace std;

class User;//add to do this to allow cyclic calling of class

class Advertisement{
public:
	Advertisement(User* owner, string title, Category category);
	Advertisement(User* owner, string title, Category category, string description);
	unsigned int getId() const;
	string getTitle() const;
	Category getCategory() const;
	string getDescription() const;
	string getImageAt(unsigned int index) const;
	void addImage(string path);
private:
	static unsigned int id;
	string title;
	Category category;
	string description;
	Date creationDate;
	bool showName, showEmail, showPhoneNumber;
	vector<string> imagesPath;
	User* owner;
};



#endif

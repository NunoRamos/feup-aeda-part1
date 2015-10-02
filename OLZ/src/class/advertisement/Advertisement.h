#ifndef SRC_CLASS_ADVERTISEMENT_ADVERTISEMENT_H_
#define SRC_CLASS_ADVERTISEMENT_ADVERTISEMENT_H_

#include<string>
#include<vector>
#include"../../Category.h"

using namespace std;

class Advertisement{
public:
	Advertisement(string title, Category category);
	Advertisement(string title, Category category, string description);
	string getTitle() const;
	Category getCategory() const;
	string getDescription() const;
	string getImageAt(unsigned int index) const;
	void addImage(string path);
private:
	string title;
	Category category;
	string description;
	Date creationDate;
	bool showName, showEmail, showPhoneNumber;
	vector<string> imagesPath;
};



#endif

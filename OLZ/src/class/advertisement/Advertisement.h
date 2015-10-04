#ifndef SRC_CLASS_ADVERTISEMENT_ADVERTISEMENT_H_
#define SRC_CLASS_ADVERTISEMENT_ADVERTISEMENT_H_

#include<string>
#include<vector>
#include"../../Category.h"
#include"../date/Date.h"

using namespace std;

class Advertisement{
public:
	Advertisement(string title, Category category);
	Advertisement(string title, Category category, string description);
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
};



#endif

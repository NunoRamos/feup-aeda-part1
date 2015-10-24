/**
* @file advertisement.h
*
* @brief Header file for class Advertisement*/

/**
* @file advertisement.cpp
*
* @brief Code for class Advertisement*/


#ifndef ADVERTISEMENT_H
#define ADVERTISEMENT_H

#include<string>
#include<vector>

#include "../../enums.h"
#include "../date/date.h"
#include "../user/user.h"

using namespace std;
using namespace enums;

class User;//add to do this to allow cyclic calling of class

/**
 * @brief Advertisement class
 */
class Advertisement{
private:
	unsigned int views; //< Number of times the advertisement has been seen
	static unsigned int id; //< Advertisement identification number
	string title; //< Advertisement title
	Category category; //< Advertisement category
	string description; //< Advertisement description
	Date creationDate; //< Advertisement date of creation
	bool showName, showEmail, showPhoneNumber; //temporary
	vector<string> imagesPath; // temporary
	User* owner; //< Pointer to owner of advertisement
	//float price;
public:
	/**
	 * @brief Constructor for class Advertisement
	 *
	 * @param owner Pointer to advertisement owner
	 * @param title Advertisement title
	 * @param category Advertisement category
	 */
	Advertisement(User* owner, string title, Category category);

	/**
	 * @brief Constructor for class Advertisement
	 *
	 * @param owner Pointer to advertisement owner
	 * @param title Advertisement title
	 * @param category Advertisement category
	 * @param description Advertisement description
	 */
	Advertisement(User* owner, string title, Category category, string description);

	/**
	 * @brief Gets advertisement ID
	 *
	 * @return Returns advertisement ID
	 */
	unsigned int getId() const;

	/**
	 * @brief Gets advertisement title
	 *
	 * @return Returns advertisement title
	 */
	string getTitle() const;

	/**
	 * @brief Gets advertisement category
	 *
	 * @return Returns advertisement category
	 */
	Category getCategory() const;

	/**
	 * @brief Gets advertisement description
	 *
	 * @return Returns advertisement description
	 */
	string getDescription() const;

	string getImageAt(unsigned int index) const;//still to decide what to do with this
	void addImage(string path);

	/**
	 * @brief Increments advertisement views
	 */
	void incrementViews();

	/**
	 * @brief Searches for text in advertisement
	 *
	 * @param text String to be search for in advertisement title and description
	 *
	 * @return Returns true if the text being searched for has been found. Returns false otherwise.
	 */
	bool searchForText(string text) const;

	/**
		 * @brief Displays ad
		 *
		 * @param height Height of menu to be printed
		 * @param width Width of menu to be printed
		 * @param borderChar Border character of menu to be printed
		 */
	virtual void displayAd(unsigned int height, unsigned int width, char borderChar) = 0;

};



#endif

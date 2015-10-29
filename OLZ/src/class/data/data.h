/**
 * @file data.h
 *
 * @brief Header file for class Data*/

/**
 * @file data.cpp
 *
 * @brief Code for class Data*/


#ifndef DATA_H
#define DATA_H

#include<vector>

#include "../user/user.h"

using namespace std;

/**
 * @brief User and Advertisement data class
 */
class Data{
private:
	vector<Advertisement*> advertisements; //< Vector of pointers to all advertisements
	vector<User> users; //< Vector of all users
	User* signedInUser; //< Pointer to user that is currently signed in
	const string path = "../../../data/"; //< used to save and load users. still not fully implemented
public:
	/**
	 * @brief Constructor for class Data
	 */
	Data();

	~Data();
	/**
	 * @brief Sign user in
	 *
	 * @param email Email of user to try to sign in
	 * @param password Password of user to try to sign in
	 *
	 * @return Returns true if the user has successfully signed in
	 */
	bool signIn(string email, string password);

	/**
	 * @brief Add user to User vector
	 *
	 * @param user User to be added in
	 *
	 * @return Returns true if the user has been successfully added
	 */
	bool addUser(User user);

	/**
	 * @brief Loads users to user vector from path
	 *
	 * @return Returns true if the users have been successfully loaded
	 */
	bool loadUsers();

	/**
	 * @brief Save users to path from user vector
	 *
	 * @return Returns true if the users have been successfully saved
	 */
	bool saveUsers();

	/**
	 * @brief Removes advertisement from advertisement vector
	 */
	void removeAdvertisement(unsigned int id);
	/**
	 * @brief Added advertisement to advertisement vector
	 */
	void addAdvertisement(Advertisement* ad);

	/**
	 * @brief Searches for ads with text in it.
	 *
	 * @return Returns vector of pointers to Advertisement with ads that have text either in their title or their description
	 */
	vector<Advertisement*> searchForAds(string text);
};

//Better option may be writing to a binary file and end every input with \n

#endif

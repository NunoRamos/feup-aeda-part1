/**
 * @file user.h
 *
 * @brief Header file for class User*/

/**
 * @file user.cpp
 *
 * @brief Code for class User*/

#ifndef USER_H
#define USER_H

#include<string>
#include<vector>

#include "../advertisement/advertisement.h"
#include "../date/date.h"
#include "../location/location.h"

using namespace std;

class Advertisement;//had to do this to allow cyclic calling of class

/**
 * @brief Date class
 */
class User{
protected:
	vector<Advertisement*> advertisements; //< Advertisements owned by the user
	string email; //< User email
	string password; //< User password
	string name; //< User name
	string phoneNumber; //< User phone number
	Date signUpDate; //< User sign up date
	Location location; //< User location
public:
	/**
	 * @brief User default constructor
	 */
	User();

	/**
	 * @brief User constructor
	 *
	 * @param email User email
	 * @param password User Password
	 * @param name User name
	 * @param phoneNumber User phone number
	 * @param signUpDate User sign up date
	 * @param location User location
	 */
	User(string email, string password, string name, string phoneNumber, Date signUpDate, Location location);

	/**
	 * @brief User constructor
	 *
	 * @param email User email
	 * @param password User Password
	 * @param name User name
	 * @param phoneNumber User phone number
	 * @param signUpDate User sign up date
	 * @param location User location as string
	 */
	User(string email, string password, string name, string phoneNumber, Date signUpDate, string location);

	/**
	 * @brief Gets user email
	 *
	 * @return Returns user email
	 */
	string getEmail() const;

	/**
	 * @brief Gets user name
	 *
	 * @return Returns user name
	 */
	string getName() const;

	/**
	 * @brief Gets user phone number
	 *
	 * @return Returns user phone number
	 */
	string getPhoneNumber() const;

	/**
	 * @brief Gets user location
	 *
	 * @return Returns user location
	 */
	Location getLocation() const;

	/**
	 * @brief Gets user location as string
	 *
	 * @return Returns user location as string
	 */
	string getLocationString() const;

	/**
	 * @brief Signs in user
	 *
	 * @param password User password
	 *
	 * @return Returns if the user has successfully signed in
	 */
	bool signIn(string password) const;

	/**
	 * @brief User >> operator
	 *
	 * @return Returns input stream
	 */
	friend istream& operator>>(istream& in, User user);

	/**
	 * @brief Removes advertisement from advertisements the user owns.
	 *
	 * @param id Advertisement identification number
	 */
	void removeAdvertisement(unsigned int id);
};

#endif

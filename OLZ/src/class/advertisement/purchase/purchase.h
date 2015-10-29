/**
 * @file purchase.h
 *
 * @brief Header file for class Purchase*/

/**
 * @file purchase.cpp
 *
 * @brief Code for class Purchase*/

#ifndef PURCHASE_H
#define PURCHASE_H

#include "../advertisement.h"

/**
 * @brief Purchase class
 */
class Purchase : public Advertisement{
private:

public:
	/**
	 * @brief Purchase constructor
	 *
	 * @param owner Pointer to advertisement owner
	 * @param title Advertisement title
	 */
	Purchase(User* owner, string title);

	/**
	 * @brief Purchase constructor
	 *
	 * @param owner Pointer to advertisement owner
	 * @param title Advertisement title
	 * @param category Advertisement category
	 * @param description Advertisement description
	 */
	Purchase(User* owner, string title, Category category, string description);

	/**
	 * @brief Purchase destructor
	 */
	~Purchase();
	void displayAd(unsigned int height, unsigned int width, char borderChar);
};

#endif

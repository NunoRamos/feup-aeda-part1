/**
 * @file sale.h
 *
 * @brief Header file for class Sale*/

/**
 * @file sale.cpp
 *
 * @brief Code for class Sale*/

#ifndef SALE_H
#define SALE_H

#include"../../../enums.h"
#include "../advertisement.h"

using namespace enums;

/**
 * @brief Sale class
 */
class Sale : public Advertisement{
private:
	Condition productCondition; //< Condition of product being sold
public:
	/**
	 * @brief Sale constructor
	 *
	 * @param owner Pointer to advertisement owner
	 * @param title Advertisement title
	 */
	Sale(User* owner, string title);
	/**
	 * @brief Sale constructor
	 *
	 * @param owner Pointer to advertisement owner
	 * @param title Advertisement title
	 * @param category Advertisement category
	 * @param description Advertisement description
	 * @param productCondition Product condition
	 */
	Sale(User* owner, string title, Category category, string description, Condition productCondition);

	/**
	 * @brief Sale destructor
	 */
	~Sale();

	void displayAd(unsigned int height, unsigned int width, char borderChar);
};


#endif

#ifndef SALE_H
#define SALE_H

#include"../../../enums.h"
#include "../advertisement.h"

using namespace enums;

class Sale : public Advertisement{
public:
	Sale(User* owner, string title, Category category, string description, Condition productCondition);
private:
	Condition productCondition;
	void displayAd(unsigned int height, unsigned int width, char borderChar);
	void displayAd(unsigned int height, unsigned int width);
};


#endif

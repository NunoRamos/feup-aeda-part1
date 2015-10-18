#ifndef PURCHASE_H
#define PURCHASE_H

#include "../advertisement.h"

class Purchase : public Advertisement{
public:
	void displayAd(unsigned int height, unsigned int width, char borderChar);
	void displayAd(unsigned int height, unsigned int width);
};

#endif

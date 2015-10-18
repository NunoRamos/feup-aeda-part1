#include "purchase.h"
#include "../advertisement.h"
#include "../../menu/adDisplayMenu/adDisplayMenu.h"

void Purchase::displayAd(unsigned int height, unsigned int width, char borderChar){
	AdDisplayMenu display(height, width, borderChar, this);
	display.print();
}
void Purchase::displayAd(unsigned int height, unsigned int width){
	displayAd(height, width, '#');
}

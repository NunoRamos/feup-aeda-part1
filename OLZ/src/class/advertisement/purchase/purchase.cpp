#include "purchase.h"
#include "../advertisement.h"

Purchase::Purchase(User* owner, string title, Category category, string description):
	Advertisement(owner, title, category, description){

}

Purchase::~Purchase(){ }

void Purchase::displayAd(unsigned int height, unsigned int width, char borderChar){

}

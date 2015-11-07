#include "purchase.h"
#include "../advertisement.h"

Purchase::Purchase(User* owner, string title, Category category, string description, float price):
	Advertisement(owner, title, category, description, price){}

Purchase::~Purchase(){ }

void Purchase::displayAd(unsigned int height, unsigned int width, char borderChar){

}

char Purchase::getType() const{
	return 'P';
}

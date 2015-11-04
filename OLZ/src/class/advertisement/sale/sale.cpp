#include "sale.h"
#include "../../menu/adDisplayMenu/adDisplayMenu.h"

Sale::Sale(User* owner, string title, Category category, string description, Condition productCondition, float price) :
Advertisement(owner, title, category, description, price){
	this->productCondition = productCondition;
}

Sale::~Sale(){ }

void Sale::displayAd(unsigned int height, unsigned int width, char borderChar){

}



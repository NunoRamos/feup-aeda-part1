#include "sale.h"


Sale::Sale(User* owner, string title, Category category, string description, Condition productCondition) :
	Advertisement(owner, title, category, description){
	this->productCondition = productCondition;
}

#ifndef ADDISPLAYMENU_H
#define ADDISPLAYMENU_H

#include "../menu.h"
#include "../../advertisement/advertisement.h"

using namespace std;
using namespace enums;

class AdDisplayMenu : public Menu{
public:
	AdDisplayMenu(Data* data, Advertisement* ad, unsigned int height = 20, unsigned int width = 50, char borderChar = '#');
	void print();
	void createMenu();
private:
	Advertisement* ad;
};

#endif

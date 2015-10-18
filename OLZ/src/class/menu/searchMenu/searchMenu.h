#ifndef SEARCHMENU_H
#define SEARCHMENU_H

#include"../menu.h"

using namespace std;

class SearchMenu : public Menu{
public:
	SearchMenu(AdData* adData, unsigned int height, unsigned int width, vector<Advertisement*> results);
	SearchMenu(AdData* adData, unsigned int height, unsigned int width, char borderChar, vector<Advertisement* > results);
	void setAdsPerPage(unsigned int adsPerPage);
	unsigned int getAdsPerPage();
	void print();
	void createMenu();
private:
	AdData* adData;
	vector<Advertisement* > results;
	unsigned int page, adsPerPage;
};

#endif

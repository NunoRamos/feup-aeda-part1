#ifndef SEARCHMENU_H
#define SEARCHMENU_H

#include"../menu.h"

using namespace std;

class SearchMenu : public Menu{
public:
	SearchMenu(Data* data, vector<Advertisement* > &results, unsigned int height = 20, unsigned int width = 75, char borderChar = '#');
	void setAdsPerPage(unsigned int adsPerPage);
	unsigned int getAdsPerPage();
	void print();
	void createMenu();
private:
	vector<Advertisement* > results;
	unsigned int page, pageMax, adsPerPage;
};

#endif

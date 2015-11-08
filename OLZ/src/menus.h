#ifndef MAINMENU_H
#define MAINMENU_H

#include "class/data/data.h"

void clearScreen();
void mainMenu(Data* data);
void search(Data* data);
void searchByCategory(Data* data);
void searchByLocation(Data* data);
void sameCity(Data* data);
void sameCounty(Data* data);
void sameDistrict(Data* data);
void searchByPrice(Data* data);
void searchByKeyword(Data* data);
void saleOrPurchase(vector<Advertisement*> &results, Data* data);
void signIn(Data* data);
void signUp(Data* data);
void exitApp(Data* data);
void signedInMenu(Data* data);
void manageAds(Data* data);
void createAd(Data* ad);
void createSellingAd(Data* data);
void createBuyingAd(Data* data);
void editAd(Data* data);
void removeAd(Data* data);
void signOut(Data* data);
void interested(User* user);
void viewMyAds(Data* data);

#endif

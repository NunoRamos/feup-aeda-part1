#ifndef MAINMENU_H
#define MAINMENU_H

#include "class/data/data.h"

void clearScreen();
void mainMenu(Data* data);
void search(Data* data);
void signIn(Data* data);
void signUp(Data* data);
void exitApp(Data* data);
void signedInMenu(Data* data);
void manageAds(Data* data);
void createSellingAd(Data* data);
void createBuyingAd(Data* data);
void editAd(Data* data);
void removeAd(Data* data);
void signOut(Data* data);
void interested(User* user);

#endif

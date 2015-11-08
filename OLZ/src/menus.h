#ifndef MAINMENU_H
#define MAINMENU_H

#include "class/data/data.h"

/**
 * @brief Clear the screen by printing 50 blank lines.
 */
void clearScreen();

/**
 * @brief Main menu
 *
 * @param data Data
 */
void mainMenu(Data* data);

/**
 * @brief Search Menu
 *
 * @param data Data
 */
void search(Data* data);

/**
 * @brief Search by category menu
 *
 * @param data Data
 */
void searchByCategory(Data* data);

/**
 * @brief Search by location menu
 *
 * @param data Data
 */
void searchByLocation(Data* data);

/**
 * @brief Shows ads within the same city
 *
 * @param data Data
 */
void sameCity(Data* data);

/**
 * @brief Shows ads within the same county
 *
 * @param data Data
 */
void sameCounty(Data* data);

/**
 * @brief Shows ads within the same district
 *
 * @param data Data
 */
void sameDistrict(Data* data);

/**
 * @brief Search by price menu
 *
 * @param data Data
 */
void searchByPrice(Data* data);

/**
 * @brief Search by keyword menu
 *
 * @param data Data
 */
void searchByKeyword(Data* data);

/**
 * @brief
 *
 * @param data Data
 */
void saleOrPurchase(vector<Advertisement*> &results, Data* data); // n sei o que faz

/**
 * @brief Signs the user in
 *
 * @param data Data
 */
void signIn(Data* data);

/**
 * @brief Signs the user up
 *
 * @param data Data
 */
void signUp(Data* data);

/**
 * @brief Exits application
 *
 * @param data Data
 */
void exitApp(Data* data);

/**
 * @brief Sign in menu
 *
 * @param data Data
 */
void signedInMenu(Data* data);

/**
 * @brief Creates sale ad
 *
 * @param data Data
 */
void createSellingAd(Data* data);

/**
 * @brief Creates purchase ad
 *
 * @param data Data
 */
void createBuyingAd(Data* data);

/**
 * @brief Edit ad menu
 *
 * @param data Data
 */
void editAd(Data* data);

/**
 * @brief Signs user out
 *
 * @param data Data
 */
void signOut(Data* data);

/**
 * @brief Simulates a sent email to user
 *
 * @param user User to send the email to
 */
void interested(User* user);

/**
 * @brief Shows the user ads
 *
 * @param data Data
 */
void viewMyAds(Data* data);

#endif

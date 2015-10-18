#include"../../class/menu/menu.h"
#include"../../class/advertisement/advertisement.h"
#include"../../class/adData/adData.h"
#include<iostream>

/*Menu Presentation
 *
 * 1 - Search
 * 2 - Sign In
 * 3 - Sign Up
 * 4 - Exit
 */

void search(AdData* adData){
	string search;
	cout << "\nInsert what you would like to search for: ";
	getline(cin, search);
	vector<Advertisement* > results;
	results = adData->searchForAds(search);

}

void signIn(AdData* adData){

}

void signUp(AdData* adData){

}

#include"../../class/menu/menu.h"
#include"../../class/advertisement/advertisement.h"
#include"../../class/data/data.h"
#include"../../class/menu/searchMenu/searchMenu.h"
#include<iostream>

/*Menu Presentation
 *
 * 1 - Search
 * 2 - Sign In
 * 3 - Sign Up
 * 4 - Exit
 */

void search(Data* data){
	string search;
	cout << "\nInsert what you would like to search for: ";
	getline(cin, search);
	vector<Advertisement* > results;
	results = data->searchForAds(search);
	SearchMenu menu(data,20,20,results);
	menu.createMenu();


}

void signIn(Data* data){

}

void signUp(Data* data){

}

#include"../../class/menu/menu.h"
#include"../../class/advertisement/advertisement.h"
#include"../../class/data/data.h"
#include"../../class/menu/searchMenu/searchMenu.h"
#include<iostream>
#include<stdlib.h>

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
	string email, password;

	cout << "Email: ";
	getline(cin, email);

	cout << "\nPassword: ";
	getline(cin, password);

	cout << endl;

	if(data->signIn(email, password))
		cout << "Logged in.";
	else
		cout << "Wrong email and password combination.";
}

void signUp(Data* data){
	string name, email, passwordOne = " ", passwordTwo = "", phoneNumber, location;

	cout << "\nWhat is your name?\n";
	getline(cin, name);

	unsigned int i = 0;
	do{
		if(i > 0)
			cout << "\nPlease introduce a valid email.";
		cout << "\nWhat is your email?\n";
		getline(cin, email);
		i++;
	}while(email.find("@") == -1 || email.find_last_of(".") == -1 || email.find("@") > email.find_last_of("."));

	i = 0;
	do{
		if(i > 0)
			cout << "\nYour passwords do not match.";
		cout << "\nWhat is your password?\n";
		getline(cin, passwordOne);
		cout << "\nPlease, repeat your password.\n";
		getline(cin, passwordTwo);
		i++;
	}while(passwordOne != passwordTwo);

	cout << "\nWhat is your phone number?\n";
	getline(cin, phoneNumber);

	cout << "\nWhere are you from? (City, county, district)\n";
	getline(cin, location);
	Location loc(location);

	Date signUpDate(25,10,2015);//still have to get date as of now

	data->addUser(User(email, name, passwordOne, phoneNumber, signUpDate, loc));
	cout << loc;
	cout << "\nYour profile has been created. You may now sign in.\n";
}

void exitApp(Data* data){
	exit(0);
}

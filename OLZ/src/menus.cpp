#include "menus.h"

#include"class/menu/menu.h"
#include"class/advertisement/advertisement.h"
#include"class/advertisement/sale/sale.h"
#include"class/advertisement/purchase/purchase.h"
#include"class/data/data.h"
#include"class/menu/searchMenu/searchMenu.h"
#include"class/menu/adDisplayMenu/adDisplayMenu.h"
#include<iostream>
#include<stdlib.h>
#include"class/menu/optionMenu/optionMenu.h"
#include <ctime>

/*Menu Presentation
 *
 * 1 - Search
 * 2 - Sign In
 * 3 - Sign Up
 * 4 - Exit
 */

void clearScreen(){
	for(unsigned int i = 0; i < 50; i++)
		cout << endl;
}

void mainMenu(Data* data){
	clearScreen();
	OptionMenu menu(data);
	menu.addOption("Search For Ads", &search);
	menu.addOption("Sign In", &signIn);
	menu.addOption("Sign Up", &signUp);
	menu.addOption("Exit", &exitApp);
	menu.createMenu();
}

void search(Data* data){
	clearScreen();
	OptionMenu menu(data);
	menu.addOption("Search By Category", searchByCategory);
	menu.addOption("Search By Location", searchByLocation);
	menu.addOption("Search For Approximate Price", searchByPrice);
	menu.addOption("Search By Keyword", searchByKeyword);
	if(data->getSignedInUser() != NULL)
		menu.addOption("Return",&signedInMenu);
	else
		menu.addOption("Return",&mainMenu);
	menu.addOption("Exit",&exitApp);
	menu.createMenu();

}


void searchByCategory(Data* data){
	clearScreen();
	string answer;
	cout << "\nInsert what category you would like to search for\n"
			"( Agriculture, Animals, BabyAndChildren, Fashion, Home, Job, Leisure,\n"
			"PhonesAndTablets, RealEstate, Services, Sports, Technology, Vehicles,\n"
			"Others ) : ";
	getline(cin, answer);
	vector<Advertisement* > results;
	if (validCategory(answer)){
		Category searchCategory=stringToCategory(answer);
		results=data->searchForAdsCategory(searchCategory);
		saleOrPurchase(results,data);
		SearchMenu menu(data, results);
		menu.createMenu();
	}
	else {
		cout<<"Invalid Category\n"
				"Do you want to search again?(Y/N)?\n";
		getline(cin, answer);
		if (answer=="y"||answer=="Y")
			searchByCategory(data);
		else if(data->getSignedInUser() != NULL)
			signedInMenu(data);
		else
			mainMenu(data);
	}

	if(data->getSignedInUser() != NULL)
		signedInMenu(data);
	else
		mainMenu(data);
}

void searchByLocation(Data* data){//TODO berninhas dá tudo com a localização
	clearScreen();
	if(data->getSignedInUser() != NULL)
		signedInMenu(data);
	else
		mainMenu(data);
}

void searchByPrice(Data* data){
	clearScreen();
	string answer;
	float lowerPrice, higherPrice;
	cout << "\nWhat price range do you want to spend?From: ";
	cin>>lowerPrice;
	cin.ignore(10000,'\n');
	cout << "\nTo: ";
	cin>>higherPrice;
	cin.ignore(10000,'\n');
	vector<Advertisement* > results;
	results = data->searchForAdsPrice(lowerPrice,higherPrice);
	saleOrPurchase(results,data);
	SearchMenu menu(data, results);
	menu.createMenu();
	if(data->getSignedInUser() != NULL)
		signedInMenu(data);
	else
		mainMenu(data);

}

void searchByKeyword(Data* data){
	clearScreen();
	string answer;
	cout << "\nInsert what you would like to search for: ";
	getline(cin, answer);
	vector<Advertisement* > results;
	results = data->searchForAds(answer);
	saleOrPurchase(results,data);
	SearchMenu menu(data, results);
	menu.createMenu();
	if(data->getSignedInUser() != NULL)
		signedInMenu(data);
	else
		mainMenu(data);
}

void saleOrPurchase(vector<Advertisement*> &results, Data* data){
	string answer;
	cout<<"Do you want sale or purchase ads(S/P)?\n";
	getline(cin, answer);
	if (answer=="s"||answer=="S")
		results=data->vectorOfSaleOrPurchase(results,'S');
	else if (answer=="p"||answer=="P")
		results=data->vectorOfSaleOrPurchase(results,'P');
	else search(data);
}

void signIn(Data* data){
	clearScreen();
	string email, password,input;


	cout << "\nEmail: ";
	getline(cin, email);

	cout << "\nPassword: ";
	getline(cin, password);

	cout << endl;

	if(data->signIn(email, password))
		signedInMenu(data);
	else{
		cout << "Wrong email and password combination.\n";
		cout << "Try Again? (Y/N)"<<endl;
		cin>>input;
		if (input=="y"||input=="Y")
		{
			cin.ignore();
			cin.clear();
			signIn(data);
		}
		else mainMenu(data);
	}
}

void signUp(Data* data){
	clearScreen();
	string name, email, passwordOne = " ", passwordTwo = "", phoneNumber, location;

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

	cout << "\nWhat is your name?\n";
	getline(cin, name);

	cout << "\nWhat is your phone number?\n";
	getline(cin, phoneNumber);

	cout << "\nWhere are you from? (City, county, district)\n";
	getline(cin, location);
	location = "Maia, Maia, Porto"; //TODO temporary until there is a checking function
	Location loc(location);

	User u1(email, passwordOne, name, phoneNumber, loc);

	//showEmail
	string answer;
	cout << "\nWould you like to show your email in your advertisements? (Y/N)\n";
	i = 0;
	do{
		if(i > 0)
			cout << "Please introduce a valid option. (Y/N)\n";
		getline(cin,answer);
		if(answer == "N" || answer == "n")
			u1.setShowEmail(false);
		i++;
	}while(answer != "Y" && answer != "y" && answer != "N" && answer != "n");

	//showName
	cout << "\nWould you like show your name in your advertisements? (Y/N)\n";
	i = 0;
	do{
		if(i > 0)
			cout << "Please introduce a valid option. (Y/N)\n";
		getline(cin,answer);
		if(answer == "N" || answer == "n")
			u1.setShowName(false);
		i++;
	}while(answer != "Y" && answer != "y" && answer != "N" && answer != "n");


	//showPhoneNumber
	cout << "\nWould you like to show your phone number in your advertisements? (Y/N)\n";
	i = 0;
	do{
		if(i > 0)
			cout << "Please introduce a valid option. (Y/N)\n";
		getline(cin,answer);
		if(answer == "N" || answer == "n")
			u1.setShowPhoneNumber(false);
		i++;
	}while(answer != "Y" && answer != "y" && answer != "N" && answer != "n");

	data->signUp(u1);
	cout << loc;
	cout << "\nYour profile has been created. You may now sign in.\n";
	mainMenu(data);
}

void exitApp(Data* data){
	if(!data->saveUsers())
		exit(1);
	exit(0);
}

void signedInMenu(Data* data){
	clearScreen();
	OptionMenu menu(data);
	menu.addOption("Search", &search);
	menu.addOption("Create buying advertisement", &createBuyingAd);
	menu.addOption("Create selling advertisement", &createSellingAd);
	menu.addOption("View my advertisements", &viewMyAds);
	menu.addOption("Delete advertisement", &removeAd);
	menu.addOption("Sign out", &signOut);
	menu.addOption("Exit", &exitApp);
	menu.createMenu();
}

void createSellingAd(Data* data){
	clearScreen();
	string title, description = "", tmp = "", category, condition;
	float price;

	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	int year=now->tm_year + 1900;
	int month=now->tm_mon + 1 ;
	int day= now->tm_mday;

	Date creationDate(day,month,year);


	cout << "Title: ";
	getline(cin, title);

	cout << "\nCategory: \n ( Agriculture, Animals, BabyAndChildren, Fashion, Home, Job, Leisure,\n"
			"PhonesAndTablets, RealEstate, Services, Sports, Technology, Vehicles,\n"
			"Others ) : ";

	getline(cin,category);
	while (!validCategory(category))
	{
		cout<<"\nWrite a valid Category: ";
		getline(cin,category);
	}
	Category cat = stringToCategory(category);

	cout << "\nDescription: ";
	getline(cin, description);

	cin.clear();

	cout << "\nPrice: ";
	cin >> price;
	cin.ignore();
	cin.clear();

	cout << "\nProduct condition (New, UsedAsNew, Functional, ForParts): ";
	getline(cin,condition);
	while (!validCondition(condition))
	{
		cout<<"\nWrite a valid Condition: ";
		getline(cin,condition);
	}
	Condition cond = stringToCondition(condition);

	Advertisement* ad = new Sale(data->getSignedInUser(), title, cat, description, cond, price);
	ad->setCreationDate(creationDate);

	cout << "\nIs the price negotiable? (Y/N)\n";
	string answer;
	unsigned int i = 0;
	do{
		if(i > 0)
			cout << "Please introduce a valid option. (Y/N)\n";
		getline(cin,answer);
		if(answer == "N" || answer == "n")
			ad->setNegotiable(false);
		i++;
	}while(answer != "Y" && answer != "y" && answer != "N" && answer != "n");

	data->addAdvertisement(ad);
	cout << "Ad has been successfully created";
	signedInMenu(data);
}

void createBuyingAd(Data* data){
	clearScreen();
	string title, description = "", tmp = "", category, condition;
	float price;

	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	int year=now->tm_year + 1900;
	int month=now->tm_mon + 1 ;
	int day= now->tm_mday;

	Date creationDate(day,month,year);

	cout << "\nTitle: ";
	getline(cin, title);

	cout << "\nCategory: \n ( Agriculture, Animals, BabyAndChildren, Fashion, Home, Job, Leisure,\n"
			"PhonesAndTablets, RealEstate, Services, Sports, Technology, Vehicles,\n"
			"Others ) : ";
	getline(cin,category);
	while (!validCategory(category))
	{
		cout<<"\nWrite a valid Category: ";
		getline(cin,category);
	}
	Category cat = stringToCategory(category);

	cout << "\nDescription: ";
	getline(cin, description);

	cout << "\nPrice: ";
	cin >> price;
	cin.ignore();
	cin.clear();

	Advertisement* ad = new Purchase(data->getSignedInUser(), title, cat, description, price);
	ad->setCreationDate(creationDate);

	cout << "\nIs the price negotiable? (Y/N)\n";
	string answer;
	unsigned int i = 0;
	do{
		if(i > 0)
			cout << "Please introduce a valid option. (Y/N)\n";
		getline(cin,answer);
		if(answer == "N" || answer == "n")
			ad->setNegotiable(false);
		i++;
	}while(answer != "Y" && answer != "y" && answer != "N" && answer != "n");


	data->addAdvertisement(ad);
	cout << "Ad has been successfully created\n";
	signedInMenu(data);
}

void editAd(Data* data){
	clearScreen();
	//TODO implement function
	signedInMenu(data);
}

void removeAd(Data* data){
	clearScreen();
	//temporary. will create a menu afterwards.
	string title;
	cout << "Insert the title of the advertisement you want to delete.\n";
	//data->removeAdvertisement(title);
	cout << "WIP. Ad has been successfully removed.\n";
	signedInMenu(data);
}

void signOut(Data* data){
	data->signOut();
	mainMenu(data);
}

void interested(User* user){
	clearScreen();
	string contact, message;
	cout << "\nPlease enter your contact: ";
	getline(cin, contact);
	cout << "\nPlease enter a message to the announcer.\n";
	getline(cin, message);
	//sendEmail(user->getEmail(), contact, message);
	cout << "Message sent.\n";
}

void viewMyAds(Data* data){
	clearScreen();
	vector<Advertisement* > results=data->getSignedInUser()->getAdvertisement();
	SearchMenu menu(data, results);
	menu.createMenu();
	signedInMenu(data);
}


void chooseAds(Data* data){
	clearScreen();
	vector<string> titles=data->getSignedInUser()->fillWithTitles();
	OptionMenu menu(data);
	for(unsigned int i=0;i<titles.size();i++){
		menu.addOption(titles[i], &viewAd);
	}
	menu.addOption("Exit", &signedInMenu);
	menu.createMenu();

}

void viewAd(Data* data){
	clearScreen();
	int i=data->getIndice();
	AdDisplayMenu menu(data,data->getSignedInUser()->getAdvertisement()[i]);
	menu.print();
	menu.createMenu();
	signedInMenu(data);
}


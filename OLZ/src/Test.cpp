#include "../cute/cute.h"
#include "../cute/ide_listener.h"
#include "../cute/xml_listener.h"
#include "../cute/cute_runner.h"
#include <stdexcept>
#include "class/menu/menu.h"
#include "class/menu/optionMenu/optionMenu.h"
#include "menus.h"
#include "class/date/date.h"
#include "class/location/location.h"
#include "class/advertisement/advertisement.h"
#include "class/data/data.h"
#include "enums.h"


using namespace std;

///Advertisement Class Test
/*void advertisementTest(){
	Location l1("Maia", "Maia", "Porto");
	Date d1(15,10,2015);
	User u1("nunoramos@gmail.com", "Nuno","916530681", d1,l1);
	Advertisement ad(&u1,"Vendo telemovel!", PhonesAndTablets);
	ASSERT_EQUAL("Vendo telemovel!", ad.getTitle());
}*/

///Advertisement Class Test
void saleTest(){

}

///Advertisement Class Test
void purchaseTest(){

}

///Advertisement Class Test
void userTest(){

}

///UserData Class Test
void userDataTest() {

}

///Location Class Test
void locationTest(){
	Location l1("Maia", "Maia", "Porto");
	Location l2("Maia, Maia, Porto");
	Location l3 = l1;
	ASSERT_EQUAL("Maia, Maia, Porto", l1.toString());
	ASSERT_EQUAL("Maia, Maia, Porto", l2.toString());
	ASSERT_EQUAL("Maia, Maia, Porto", l3.toString());

}

///Date Class Test
void dateTest() {
	Date d1;
	try{
		Date d2(32,14,1904);
	}
	catch(out_of_range &e){
		ASSERT_EQUALM(e.what(), true, true);
	}

	Date d3("1/12/2015");
	ASSERT_EQUAL("1/1/1900", d1.toString());
	ASSERT_EQUAL("1/12/2015", d3.toString());


	ASSERT_EQUALM("1800 should not be a leap year.", false, Date::isLeapYear(1800));
	ASSERT_EQUALM("1903 should not be a leap year.", false, Date::isLeapYear(1903));
	ASSERT_EQUALM("1904 should be a leap year.", true, Date::isLeapYear(1904));
	ASSERT_EQUALM("2000 should be a leap year.", true, Date::isLeapYear(2000));
}

///Menu Class Test
void menuTest(){
	Data* data = new Data();

	data->loadUsers();

	User u1("nunoramos@gmail.com", "oi" , "nuno","91","Maia, Maia, Porto");
	data->signUp(u1);
	User u2("a@b.c", "oi" , "nuno","91","Maia, Maia, Porto");
	data->signUp(u2);
	OptionMenu menu(data);
	menu.addOption("Search", &search);
	menu.addOption("Sign In", &signIn);
	menu.addOption("Sign Up", &signUp);
	menu.addOption("Exit", &exitApp);
	menu.createMenu();

	data->saveUsers();
	int n;
	cin>>n;
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(dateTest));
	s.push_back(CUTE(locationTest));
	s.push_back(CUTE(userTest));
	s.push_back(CUTE(userDataTest));
	//s.push_back(CUTE(advertisementTest));
	s.push_back(CUTE(saleTest));
	s.push_back(CUTE(purchaseTest));
	s.push_back(CUTE(menuTest));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
	//runAllTests(argc,argv);
	menuTest();
	return 0;
}




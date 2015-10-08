#include "../cute/cute.h"
#include "../cute/ide_listener.h"
#include "../cute/xml_listener.h"
#include "../cute/cute_runner.h"
#include "class/date/Date.h"
#include "class/location/Location.h"

void advertisementTest(){

}

void saleTest(){

}

void purchaseTest(){

}

void userTest(){

}

void usersDataTest() {

}

void locationTest(){
	Location l1("Maia", "Maia", "Porto");
	Location l2("Maia, Maia, Porto");
	Location l3 = l1;
	ASSERT_EQUAL("Maia, Maia, Porto", l1.getString());
	ASSERT_EQUAL("Maia, Maia, Porto", l2.getString());
	ASSERT_EQUAL("Maia, Maia, Porto", l3.getString());

}

void dateTest() {
	ASSERT_EQUALM("1800 should not be a leap year.", Date::isLeapYear(1800), false);
	ASSERT_EQUALM("1903 should not be a leap year.", Date::isLeapYear(1903), false);
	ASSERT_EQUALM("1904 should be a leap year.", Date::isLeapYear(1904), true);
	ASSERT_EQUALM("2000 should be a leap year.", Date::isLeapYear(2000), true);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(dateTest));
	s.push_back(CUTE(locationTest));
	s.push_back(CUTE(userTest));
	s.push_back(CUTE(usersDataTest));
	s.push_back(CUTE(advertisementTest));
	s.push_back(CUTE(saleTest));
	s.push_back(CUTE(purchaseTest));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
	runAllTests(argc,argv);
    return 0;
}




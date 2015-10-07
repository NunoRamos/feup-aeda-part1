#include "Location.h"


Location::Location(){

}

Location::Location(string city, string county, string district){
	this->city = city;
	this->county = county;
	this->district = district;
}

Location::Location(string location){
	string county = location.substr(location.find(","));
	this->city = location.substr(0, location.find(","));
	this->county = county.substr(0, county.find(","));
	this->district = county.substr(county.find(","));
}

string Location::getString() const{
	return city + ", " + county + ", " + district;
}

string Location::getCity() const{
	return city;
}

string Location::getCounty() const{
	return county;
}

string Location::getDistrict() const{
	return district;
}

Location& Location::operator=(const Location& rhs){
	this->city = rhs.city;
	this->county = rhs.county;
	this->district = rhs.district;
	return *this;
}






#include "Location.h"


Location::Location(string city, string county, string district){
	this->city = city;
	this->county = county;
	this->district = district;
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

Location& Location::operator=(Location rhs){
	this->city = rhs.city;
	this->county = rhs.county;
	this->district = rhs.district;
	return this;
}






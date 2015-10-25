#include "location.h"


Location::Location(){

}

Location::Location(string city, string county, string district){
	this->city = city;
	this->county = county;
	this->district = district;
}

Location::Location(string location){
	string temp = location.substr(location.find(",")+2);
	this->city = location.substr(0, location.find(","));
	this->county = temp.substr(0, temp.find(","));
	this->district = temp.substr(temp.find(",")+2);
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

ostream& operator<<(ostream & os, Location location){
	os << location.getString();
	return os;
}






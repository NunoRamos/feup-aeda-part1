#ifndef LOCATION_H_
#define LOCATION_H_

#include<string>

using namespace std;


class Location{
public:
	Location();
	Location(string city, string county, string district);
	Location(string location);
	string getString() const;
	string getCity() const;
	string getCounty() const;
	string getDistrict() const;
	Location& operator=(const Location &rhs);
	friend ostream& operator<<(ostream & os, Location location);
protected:
	string city, county, district;
};



#endif

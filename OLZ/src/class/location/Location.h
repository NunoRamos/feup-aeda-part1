#ifndef LOCATION_H_
#define LOCATION_H_

#include<string>

using namespace std;


class Location{
public:
	Location(string city, string county, string district);
	string getString() const;
	string getCity() const;
	string getCounty() const;
	string getDistrict() const;
	Location& operator=(Location rhs);
private:
	string city, county, district;
};



#endif

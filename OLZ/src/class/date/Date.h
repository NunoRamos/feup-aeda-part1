#ifndef DATE_H
#define DATE_H

#include<string>

using namespace std;

class Date{
public:
	Date();
	Date(unsigned int day, unsigned int month, unsigned int year);
	Date(string date);
	bool setDay(unsigned int day);
	bool setMonth(unsigned int month);
	bool setYear(unsigned int year);
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;
	string getString() const;
	Date& operator=(Date rhs);
	static bool isDateValid(unsigned int day, unsigned int month, unsigned int year);
	static bool isLeapYear(unsigned int year);
private:
	unsigned int day, month, year;
};

#endif

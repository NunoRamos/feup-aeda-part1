#IFNDEF DATE_H
#DEFINE DATE_H

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
	Date& operator=(Date lhs, Date rhs);
private:
	bool isLeapYear(unsigned int year);
	bool isDateValid(unsigned int day, unsigned int month, unsigned int year);
	unsigned int day, month, year;
};

#ENDIF

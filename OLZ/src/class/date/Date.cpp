#include "Date.h"
#include <sstream>

Date::Date(){
	day = 1;
	month = 1;
	year = 1900;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year){
	if(isDateValid(day,month,year)){
		this->day = day;
		this->month = month;
		this->year = year;
	}
}

Date::Date(string date){
	stringstream ss;
	ss.str(date);
	ss >> day >> month >> year;
}

bool Date::setDay(unsigned int day){
	if(isDateValid(day,month,year)){
		this->day = day;
		return true;
	}
	return false;
}

bool Date::setMonth(unsigned int month){
	if(isDateValid(day,month,year)){
			this->month = month;
			return true;
		}
		return false;
}

bool Date::setYear(unsigned int year){
	if(isDateValid(day,month,year)){
			this->year = year;
			return true;
		}
		return false;
}

unsigned int Date::getDay() const{
	return day;
}

unsigned int Date::getMonth() const{
	return month;
}

unsigned int Date::getYear() const{
	return year;
}

string Date::getString() const{
	return day + "/" + month + "/" + year;
}

bool Date::isLeapYear(unsigned int year){

	if(year % 400 == 0)
		return true;
	else
		if(year % 100 == 0)
			return false;
		else
			if(year % 4 == 0)
				return true;

	return false;
}

bool Date::isDateValid(unsigned int day, unsigned int month, unsigned int year){

	if(day < 1 || day > 31 || month < 1 || month > 12)
		return false;

	switch(month){
	case 4:
	case 6:
	case 9:
	case 11:
		if(day > 30)
			return false;
		break;
	case 2:
		if(isLeapYear(year)){
			if(day > 29)
				return false;
		}
		else{
			if(day > 28)
				return false;
		}
		break;
	}

	return true;
}

Date& Date::operator=(Date lhs, Date rhs){
	lhs.day = rhs.day;
	lhs.month = rhs.month;
	lhs.year = rhs.year;

	return lhs;
}


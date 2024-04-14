#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include "class.h"
Date::Date()
{
	std::time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	day = ltm.tm_mday;
	month = ltm.tm_mon + 1;
	year = ltm.tm_year + 1900;
}
Date::Date(int dayT, int monthT, int yearT)
{
	if (day < 1 || day > 31 || month < 1 || month > 12) {
		std::cout << "Неверная дата";
		day = 1;
		month = 1;
		year = 2000;
	}
	else {
		day = dayT;
		month = monthT;
		year = yearT;
	}
}
Date::Date(const std::string& date) {
	if (date.length() == 10) { // 01.01.2000
		day = stoi(date.substr(0, 2));
		month = stoi(date.substr(3, 2));
		year = stoi(date.substr(6, 4));
	}
	else if (date.length() == 8) { // 01.01.00
		day = stoi(date.substr(0, 2));
		month = stoi(date.substr(3, 2));
		year = stoi(date.substr(6, 2));
	}
	else {
		std::cout << "Неверный формат";
		day = 1;
		month = 1;
		year = 2000;
	}
	if (year < 2000) year += 2000;
	if (day < 1 || day > 31 || month < 1 || month > 12) std::cout << "Неверная дата";
}
std::string Date::toString() const {
	return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}
int Date::daysTo(const Date& d) const {
	int days = 0;
	if (year < d.year) {
		days += (d.year - year - 1) * 365;
		for (int i = year; i < d.year - 1; i++) {
			if (isLeapYear(i)) {
				days++;
			}
		}
		days += 365 - day + d.day;
		if (isLeapYear(d.year) && d.month < 3) {
			days--;
		}
	}
	else if (year > d.year) {
		days += (year - d.year - 1) * 365;
		for (int i = d.year; i < year - 1; i++) {
			if (isLeapYear(i)) {
				days++;
			}
		}
		days += day - d.day;
		if (isLeapYear(year) && month < 3) {
			days++;
		}
	}
	else {
		days = day - d.day;
	}
	return days;
}
bool Date::isLeapYear(int year) const {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
#pragma once
class Date {
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	Date();
	Date(int dayT, int monthT, int yearT);
	Date(const std::string& date);
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	void setDay(int dayT) { day = dayT; }
	void setMonth(int monthT) { month = monthT; }
	void setYear(int yearT) { year = yearT; }
	std::string toString() const;
	bool operator==(const Date& d) const { return (day == d.day && month == d.month && year == d.year); }
	int daysTo(const Date& d) const;
	bool isLeapYear(int year) const;
};
#include <ctime>
#include <iostream>
#include "class.h"

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	Date dateString("10.10.2009");
	Date dateA;
	std::cout << dateA.toString() << std::endl;
	Date dateInt(10, 13, 20);
	std::cout << dateString.daysTo(dateA) << std::endl;
	std::cout << (dateString == dateA);
}
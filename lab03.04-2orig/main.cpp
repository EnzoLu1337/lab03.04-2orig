#include <ctime>
#include <iostream>
#include "class.h"

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	Date dateString("10.10.2009");
	std::cout << dateString.toString() << std::endl;
	Date dateA;
	std::cout << dateA.toString() << std::endl;
	Date dateInt(10, 13, 20);
	std::cout << dateInt.toString() << std::endl;
}
#include <iostream>
#include "BubbleSort.h"

void menu();

int main() {
	menu();
	system("PAUSE");
	return 0;
}


void menu() {
	std::cout << "Witaj! Ile elementow ma miec tablic?\n>";
	int n = 0;
	std::cin >> n;
	std::cout << "\n0 - sortowanie tablicy z rozkladu jednostajnego\n"
		<< "1 - sortowanie tablicy z rozkladu normalnego\n"
		<< "2 - sortowanie tablicy z rozkladu Poissona\n>";
	int rozklad = 0;
	std::cin >> rozklad;
	std::cout << "\n0 - sortowanie tablicy nieuporzadkowanej\n"
		<< "1 - sortowanie tablicy z 10% uporzadkowanymi elementami\n"
		<< "2 - sortowanie tablicy z 50% uporzadkowanymi elementami\n"
		<< "3 - sortowanie tablicy z 90% uporzadkowanymi elementami\n>";
	int uporzadkowanie = 0;
	std::cin >> uporzadkowanie;
	BubbleSort BS(n,rozklad,uporzadkowanie);
}


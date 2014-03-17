#include <iostream>
#include "Stos.h"
#include "Lista.h"
#include "menu.h"

using namespace std;

int main()
{
	int wybor;

	do{
		cout << "\n\n\n******* Menu *******" << endl
			<< "1. Praca na klasie STOS" << endl
			<< "2. Praca na klasie LISTA" << endl
			<< "0. Wyjscie" << endl
			<< "Twoj wybor:   ";
		cin >> wybor;

		switch (wybor){

		case 1: menu_stos();
			break;
			
		case 2: menu_lista();
			break;
		}

	} while (wybor != 0);

	system("PAUSE");
	return 0;
}
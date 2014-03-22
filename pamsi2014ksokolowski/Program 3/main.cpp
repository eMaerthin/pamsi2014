#include <iostream>
#include "funkcje_menu.h"
#include <conio.h> //dla textcolor()

using namespace std;

int main()
{
	menu_stos();
	cout << "\n\n\n\n";
	menu_kopiec();
	cout << "\n\n\n\n";
	menu_kolejka();
	cout << "\n\n\n\n";


	system("PAUSE");
	return 0;
}
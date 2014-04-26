#include <iostream>
#include "funkcje.h"
#include "Tablica.h"

using namespace std;

int main()
{
	char wybor;

	while (true){
		cout << "\n\nMenu" << endl
			<< "1. Menu sortowania." << endl
			<< "2. Eksperyment." << endl
			<< "0. Wyjscie z programu";
		wybor = _getch();
		if (wybor < '0' || wybor > '2'){
			continue;
		}
		switch (wybor){
		case '1': menu_sortowania();
			break;
		case '2': eksperyment();
			break;
		case '0': return 0;
		}
	}

	system("PAUSE");
	return 0;
}
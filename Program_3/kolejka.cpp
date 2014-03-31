#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue <int> lista;
	queue <int> lista_2;
	queue <int> lista_3;
	int i = 0, k, j;
	while (i != 1)
	{
		cout << "\n******************M E N U**************\n";
		cout << "1. Poloz na poczatek\n2. Sciagnij z poczatku\n3. Wyswietl dlugosc kolejki\n4. Koniec\n";
		cout << "\n***************************************\n";
		cout << "\nWybierz opcje ";
		cin >> k;
		switch (k)
		{
		case 1:
			cout << "Podaj liczbe: " << endl;
			cin >> i;
			lista.push(i);
			break;
		case 2: lista.pop();
			break;
		case 3:
			j = 0;
			lista_3 = lista;
			while (lista_3.empty() == false)
			{
				lista_3.pop();
				j++;
			}
			cout << "Dlugosc twojwj kolejki to: " << j << endl;
			break;
		case 4: i = 1;
			break;
		default: cout << "\n------- Zla opcja -------\n";
			break;
		}
	} return 0;
}

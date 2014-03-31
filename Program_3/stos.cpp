#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack <int> Stos;
	stack <int> stos_2;
	stack <int> stos_3;
	int top = 0;
	int i = 0 , k;
	int rozmiar, cyfra, szukana, poziom;
	while (i != 1)
	{
		cout << "\n******************M E N U**************\n";
		cout << "1. Poloz\n2. Sciagnij\n3. Wyswietl\n4. Szukaj elementu\n5. Koniec\n";
		cout << "\n***************************************\n";
		cout << "\n Wybierz opcje ";
		cin >> k;
		switch (k)
		{
		case 1:

			cout << "Ile liczb chcesz miec na stosie: " << endl;
			cin >> rozmiar;
			for (i = 0; i < rozmiar; i++)
			{
				cout << "Wprowadz liczbe  " << i+1 << endl;
				cin >> cyfra;
				Stos.push(cyfra);
				cout << endl;
			}
			break;
		case 2:

			if (rozmiar == 0)
				cout << "\n Stos jest pusty!" << endl;
			else Stos.pop();
			cout << "\n Element sciagniety ze stosu" << endl;
			rozmiar--;
			break;

		case 3:
			stos_2 = Stos;
			cout << "Twoj stos:  ";
			for (i = rozmiar; i > 0; i--)
			{
				cout << stos_2.top() << "  ";
				stos_2.pop();
				rozmiar--;
				if (rozmiar == 0) cout << endl;
			}
			break;

		case 4: 
			poziom = rozmiar;
			stos_3 = Stos;
			cout << "Jaki element chcesz znalezc? " << endl;
			cin >> szukana;
			
			for (i = poziom; i > 0; i--)
			{
				if (stos_3.top() == szukana) cout << "Twoja liczba jest na stosie: " << stos_3.top() << endl;
				if (stos_3.top() != szukana)
				{
					stos_3.pop();
					poziom--;
				}
				if (poziom == 0) cout << "Twojej liczby nie ma na stosie! " << endl;
			}
			break;

		case 5: i = 1;
			break;
		default: cout << "\n------- Zla opcja -------\n";
			break;
		}
	} return 0;
}
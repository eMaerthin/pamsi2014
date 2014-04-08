#include <iostream>
#include <queue>

using namespace std;

class Kolejka : public queue<int>
{
	public:
		void wypelnij()
		{
			cout << "Ile chcesz dodac elementow?: ";
			int ile;
			cin >> ile;
			for(int i = 0; i < ile; i++)
			{
				cout<<i<<": ";
				int k;
				cin >> k;
				this->push(k);
			}
		}
		void wyswietlRozmiar()
		{
			cout << "Rozmiar kolejki: " << this->size() << endl;
		}
		
		int usunPierwszy()
		{
			if(!this->empty())
			{
				int result;
				result = this->front();
				this->pop();
				return result;
			}
			else
				return 0;
		}
};



int main()
{
	Kolejka * kolejka = new Kolejka();
	
	int opcja;
	do
	{
		cout << endl << "Menu" << endl;
		cout << "1. Wczytaj kolejke" << endl;
		cout << "2. Wyswietl rozmiar kolejki" << endl;
		cout << "3. Zwroc i usun pierwszy element kolejki" << endl;
		cout << "0. Wyjdz" << endl;
		cout << " "<< endl;
		cout << "Wybierz co chcesz zrobic" << endl;
		cout << " " << endl;
		cin >> opcja;
	
		switch (opcja)
		{
			case 1:
				kolejka->wypelnij();
				break;
		
			case 2:
				kolejka->wyswietlRozmiar();
				break;
		
			case 3:
				cout<<kolejka->usunPierwszy();
				break;
		}
	} while(opcja != 0);
	
	return 0;
}

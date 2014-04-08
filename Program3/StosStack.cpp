#include <iostream>
#include <stack>

using namespace std;
class Stos : public stack<int>
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
	
	void wyswietl()
	{
		Stos * stos = new Stos();
		while(!this->empty())
		{
			stos->push(this->top());
			cout<< this->top() << ", ";
			this->pop();
		}
		while(!stos->empty())
		{
			this->push(stos->top());
			stos->pop();
		}
	}
	
	bool wyszukajElement(int el)
	{
		bool result = false;
		Stos * stos = new Stos();
		while(!this->empty() && !result)
		{
			if(el == this->top())
				result = true;
			stos->push(this->top());
			this->pop();
		}
		while(!stos->empty())
		{
			this->push(stos->top());
			stos->pop();
		}
		return result;
	}
	
	void usunElementy(int ile)
	{
		while(!this->empty() && ile-- > 0)
			this->pop();
	}
};

int main()
{
	Stos * stos = new Stos();
	int opcja;
	do
	{
		cout << endl << "Menu" << endl;
		cout << "1. Wczytaj stos" << endl;
		cout << "2. Wyswietl zawartosc stosu" << endl;
		cout << "3. Wyszukaj element na stosie" << endl;
		cout << "4. Usun element ze stosu" << endl;
		cout << "0. Wyjdz" << endl;
		cout << " "<< endl;
		cout << "Wybierz co chcesz zrobic" << endl;
		cout << " " << endl;
		cin >> opcja;
	
		switch (opcja)
		{
			case 1:
				stos->wypelnij();
				break;
		
			case 2:
				stos->wyswietl();
				break;
		
			case 3:
				{
					cout<<"Podaj element do wyszukania: ";
					int el;
					cin >> el;
					if(stos->wyszukajElement(el))
						cout << "Znaleziono" << endl;
					else
						cout << "Nie znaleziono" << endl;
					break;
				}
				
			case 4:
				{
					cout<<"Ile elementow chcesz usunac? " << endl;
					int ile;
					cin >> ile;
					stos->usunElementy(ile);
					break;
				}
		}
	} while(opcja != 0);
	
	return 0;
}

//autor: Marcin Ochocki 200330

#include <iostream>
#include <stack>
using namespace std;

//Deklaracja klasy stos:
class stos {
      stack <int> lista;
      public:
      void Dodaj(int & dana); //dodaje element na stos
      void Zdejmij(); //zdejmuje element ze stosu
      void Wyswietl(); //wyswietla stos
};

void stos::Dodaj(int & dana) {
      lista.push(dana);
}

void stos::Zdejmij() {
	int rozmiar=lista.size();
	if(rozmiar==0)	{
		cout << "Stos jest pusty" << endl;
	}
	else {
		lista.pop();
		cout << "Zdjeto ze stosu" << endl;
	}
}

void stos::Wyswietl() {
	int rozmiar=lista.size();
	if(rozmiar==0) {
		cout << "Stos jest pusty" << endl;
    }
    else {
		cout << "Na stosie jest " << rozmiar << " elementow:" << endl;
		stack <int> tmp = lista;
		int wartosc;
		while(!tmp.empty()) {
		    wartosc = tmp.top();
		    cout << wartosc << " ";
		    tmp.pop();
		}
		cout << endl;
	}
}

int main() {
    char opcja;
    int liczba;
    stos dana;
    cout << "+ - Dodaj na stos" << endl 
         << "- - Zdejmij ze stosu" << endl
         << "w - Wyswietl stos" << endl
         << "q - Koniec" << endl << endl;
    do {
        cout << endl << "Twoj wybor: ";
        cin >> opcja;
        switch(opcja) {
             case '+':
                  cout << "Podaj liczbe calkowita: ";
                  cin >> liczba;
                  dana.Dodaj(liczba);
                  cout << "Dodano na stos" << endl;
                  break;
             case '-':
                  dana.Zdejmij();
                  break;
             case 'w':
                  dana.Wyswietl();
                  break;
             case 'q':
                  cout << "Koniec";
                  break;
        	 default:
				  cout << "Zla komenda!" << endl;
				  break;
        }
    } while(opcja!='q');
    return 0;
}

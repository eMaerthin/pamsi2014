//autor: Marcin Ochocki 200330

#include <iostream>
#include <queue>
using namespace std;

class kolejka {
	queue <int> q;
	public:
	int DodajNaKoniec(int & dana);
	void UsunPoczatek();
	void Wyswietl();
};

int kolejka::DodajNaKoniec(int & dana) {
	q.push(dana);
	return dana;
}

void kolejka::UsunPoczatek() {
	int rozmiar=q.size();
	if(rozmiar==0) {
		cout << "Kolejka nie istnieje!" << endl;
    }
    else {
		q.pop();
		cout << "Usunieto poczatek kolejki" << endl;
    }
}

void kolejka::Wyswietl() {
	int rozmiar=q.size();
    if(rozmiar==0) {
		cout << "Kolejka nie istnieje" << endl;
    }
    else {
		cout << "W kolejce jest " << rozmiar << " elementow:" << endl;
		queue <int> tmp = q;
		int wartosc;
		while(!tmp.empty()) {
		    wartosc = tmp.front();
		    cout << wartosc << " ";
		    tmp.pop();
		}
	    cout << endl;
    }
}

int main() {
	char opcja;
    int liczba;
    kolejka dana;
    cout << "+ - Dodaj na koniec kolejki" << endl 
         << "- - Usun poczatek kolejki" << endl
         << "w - Wyswietl kolejke" << endl
         << "q - Koniec" << endl;
    do {
        cout << endl << "Twoj wybor: ";
        cin >> opcja;
        switch(opcja) {
             case '+':
                  cout << "Podaj liczbe calkowita: ";
                  cin >> liczba;
                  dana.DodajNaKoniec(liczba);
                  cout << "Dodano na koniec kolejki" << endl;
                  break;
             case '-':
                  dana.UsunPoczatek();
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



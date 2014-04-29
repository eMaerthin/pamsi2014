//autor: Marcin Ochocki 200330

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class kopiec {
	vector<int>tab;
	char rodzaj;
	public:
	int StworzWektor(int & ile);
	void Dodaj();
	void UsunMax();
	void Sortuj();
	void StworzKopiec();
	void Wyswietl();
};

int kopiec::StworzWektor(int & ile) {
	int pi[]={3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6};
	for(int i=0; i<ile; i++) {
		tab.push_back(pi[i]);
	}
	rodzaj='a';
	return ile;
}

void kopiec::Dodaj() {
	int rozmiar=tab.size();
	int pi[]={3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6};
	if(rozmiar!=21) {
		tab.push_back(pi[rozmiar]);
		cout << "Dodano do wektora" << endl << endl;
		rodzaj='a';
	}
	else {
		cout << "Wektor moze miec max 21 elementow!" << endl << endl;
	}
}

void kopiec::UsunMax() {
	int rozmiar=tab.size();
	if(rozmiar>0) {
		if(rodzaj!='c') {
			make_heap(tab.begin(),tab.end());
		}
		pop_heap(tab.begin(),tab.end());
		cout << "Usunieto maksymalna wartosc" << endl << endl;
		tab.pop_back();
		StworzKopiec();
	}
	else {
		cout << "Kopiec nie istnieje!" << endl << endl;
	}
}

void kopiec::Sortuj() {
	sort_heap(tab.begin(),tab.end());
	rodzaj='b';
}

void kopiec::StworzKopiec() {
    make_heap(tab.begin(),tab.end());
    rodzaj='c';
}

void kopiec::Wyswietl() {
	vector<int>::iterator it;
	int rozmiar=tab.size();
	if(rozmiar>0) {
		if(rodzaj=='a') {
			cout << "Nieposortowane: ";
		}
		if(rodzaj=='b') {
			cout << "Posortowane: ";
		}
		if(rodzaj=='c') {
			cout << "Kopiec: ";
		}
		for(it=tab.begin(); it!=tab.end(); ++it) {
			cout << *it << " ";
		}
	}
	else {
		cout << "Kopiec nie istnieje";
	}
	cout << endl << endl;
}

int main() {
	char opcja;
	int ile;
	kopiec k;
	cout << "Podaj rozmiar kopca (max 21): ";
	cin >> ile;
	cout << endl;
	k.StworzWektor(ile);
	k.Wyswietl();
	cout << "+ - Dodaj element do kopca" << endl 
         << "- - Zdejmij najwiekszy element z kopca" << endl
         << "s - Sortuj elementy kopca" << endl
         << "k - Przywroc wlasnosci kopca" << endl
         << "w - Wyswietl elementy" << endl
         << "q - Koniec" << endl << endl;
	do {
        cout << "Twoj wybor: ";
        cin >> opcja;
        switch(opcja) {
            case '+':
                k.Dodaj();
                break;
            case '-':
                k.UsunMax();
                break;
        	case 's':
				k.Sortuj();
				break;
			case 'k':
				k.StworzKopiec();
				break;
            case 'w':
                k.Wyswietl();
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



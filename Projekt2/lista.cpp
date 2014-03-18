//autor: Marcin Ochocki 200330

#include <iostream>
using namespace std;

//Deklaracja klasy elementu listy
class elementy {
	public:
	elementy * nastepny, * poprzedni; //wskazuje nastepny i poprzedni element listy
	int wartosc; //przechowuje wartosc elementu
};

//Deklaracja klasy listy
class lista {
	private:
		elementy * pierwszy, * ostatni; //przechowuje adres pierwszego i ostatniego elementu
		int rozmiar; //przechowuje wartosc listy
	public:
		lista(); //konstruktor listy
		elementy * DodajNaPoczatek(elementy * dana); //dodaje element na poczatek listy
		elementy * DodajNaKoniec(elementy * dana); //dodaje element na koniec listy
		void UsunPierwszy(); //usuwa pierwszy element listy
		void UsunOstatni(); //usuwa ostatni element listy
		void Wyswietl(); //wyswietla cala liste
};

lista::lista() {
	pierwszy = NULL;
	ostatni = NULL;
	rozmiar=0;
}

elementy * lista::DodajNaPoczatek(elementy * dana) {
	dana->nastepny=pierwszy; //element ustawiamy na pierwszej pozycji
	dana->poprzedni=NULL; //poprzedni element zerujemy
	if(pierwszy) { //jesli lista ma juz pierwszy element
		pierwszy->poprzedni=dana; //wtedy poprzednik okreslamy wartoscia biezacej danej
	}
	pierwszy=dana; //poczatek listy przyjmuje wartosc biezacej danej
	if(!ostatni) { //jesli nie ma ostatniego elementu (czyli lista ma 1 element)
		ostatni=pierwszy; //wtedy ostatni element ma taka sama wartosc jak pierwszy
	}
	rozmiar++; //zwiekszamy rozmiar listy o 1
	return pierwszy;
}

elementy * lista::DodajNaKoniec(elementy * dana) {
	if(ostatni) { //jesli lista ma juz ostatni element
		ostatni->nastepny = dana; //wtedy nastepnik okreslamy wartoscia biezacej danej
	}
    dana->nastepny=NULL; //nastepny element zerujemy
	dana->poprzedni=ostatni; //element ustawiamy na ostatniej pozycji
    ostatni = dana; //ostatni element listy przyjmuje wartosc biezacej danej
    if(!pierwszy) { //jesli nie ma pierwszego elementu (czyli lista ma 1 element)
		pierwszy=ostatni; //wtedy pierwszy element ma taka sama wartosc jak ostatni
    }
    rozmiar++; //zwiekszamy rozmiar listy o 1
    return ostatni;
}

void lista::UsunPierwszy() {
    elementy * dana;
    if(pierwszy) {
    	dana=pierwszy; //biezaca dana przyjmuje wartosc pierwszego elementu listy
        pierwszy=pierwszy->nastepny; //pierwszy element listy przyjmuje wartosc nastepnika
        if(!pierwszy) { //jesli nie ma pierwszego elementu (lista ma 1 element)
			ostatni = NULL; //ostatni element zerujemy
        }
        else {
			pierwszy->poprzedni = NULL; //poprzednik zerujemy
        }
        rozmiar--; //zmniejszamy rozmiar listy o 1
        cout << "Usunieto pierwszy element" << endl;
    }
    else {
		cout << "Lista jest pusta" << endl;
    }
}

void lista::UsunOstatni() {
    elementy * dana;
    if(ostatni) {
    	dana=ostatni; //biezaca dana przyjmuje wartosc pierwszego elementu listy
       	if(dana==pierwszy) { //jesli to ten sam element co pierwszy
			pierwszy=NULL; ostatni=NULL; //zerujemy te dwa elementy
       	}
       	else {
			ostatni=ostatni->poprzedni; //ostatni element staje sie poprzednikiem
			ostatni->nastepny=NULL; //nastepnik biezacego ostatniego elementu zerujemy
       	}
        rozmiar--; //zmniejszamy rozmiar listy o 1
        cout << "Usunieto ostatni element" << endl;
    }
    else {
		cout << "Lista jest pusta" << endl;
    }
}

void lista::Wyswietl() {
    elementy * dana;
    if(!pierwszy) {
		cout << "Lista jest pusta" << endl;
    }
    else {
        dana=pierwszy; //biezaca dana przyjmuje wartosc pierwszego elementu
        cout << "Na liscie jest " << rozmiar << " elementow:" << endl;
        while(dana) { //jesli sa jeszcze dane na liscie
          cout << dana->wartosc << " ";
          dana=dana->nastepny; //dana przyjmuje wartosc nastepnego elementu
        }
        cout << endl;
    }
}

int main() {
	int opcja, liczba;
	elementy * dana;
	lista l;
    cout << "1 - Dodaj na poczatek" << endl 
         << "2 - Dodaj na koniec" << endl
         << "3 - Usun pierwszy element" << endl
         << "4 - Usun ostatni element" << endl 
		 << "5 - Wyswietl liste" << endl
		 << "0 - Koniec" << endl;
    do {
        cout << endl << "Twoj wybor: ";
        cin >> opcja;
        switch(opcja) {
			case 1:
            	cout << "Podaj liczbe calkowita: ";
                cin >> liczba;
                dana = new elementy; //tworzy nowy element
                dana->wartosc=liczba; //zapisuje wartosc podanej liczby
                l.DodajNaPoczatek(dana);
                cout << "Dodano na poczatek listy" << endl;
                break;
            case 2:
                cout << "Podaj liczbe calkowita: ";
                cin >> liczba;
                dana = new elementy; //tworzy nowy element
                dana->wartosc=liczba; //zapisuje wartosc podanej liczby
                l.DodajNaKoniec(dana);
                cout << "Dodano na koniec listy" << endl;
                break;
            case 3:
                l.UsunPierwszy();
                break;
            case 4:
				l.UsunOstatni();
                break;
            case 5:
				l.Wyswietl();
				break;
			case 0:
				cout << "Koniec";
				break;
            default:
				cout << "Zla komenda!" << endl;
				break;
		}
	} while(opcja!=0);
	return 0;             
}

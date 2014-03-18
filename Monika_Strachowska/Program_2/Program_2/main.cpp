#include <iostream>

using namespace std;

template <class T>
class Element {
public:
	Element(): wartosc(NULL), kolejny(NULL), poprzedni(NULL), flaga(0) {};
	~Element();
	T wartosc;
	Element *kolejny;
	Element *poprzedni;
	bool flaga;
}; 

template <class T>
class  Stos {
private:
	Element <T> *pierwszyAdres;			//adres pierwszego elementu w liscie
	Element <T> *zmiennyElementGlowny;	//pierwszy utworzony obiekt klasy Element, ktory powstaje razem z utworzeniem obiektu Stos
	int rozmiarStosu;
public:
	Stos(): pierwszyAdres(NULL), zmiennyElementGlowny(new Element <T>), rozmiarStosu(0) {};
	~Stos();
	void dodanie(T el);
	void wyswietlanie();
	void rozmiar() {
		if(rozmiarStosu > 0)
			cout << "Rozmiar stosu to: " << rozmiarStosu << endl;
		else cout << "Stos jest pusty\n";
	};
	void usuniecie();
};

template <class T>
void Stos<T>::dodanie(T el) {
	if (pierwszyAdres == NULL) {
		zmiennyElementGlowny->wartosc = el;				//zapisuje do obiektu klasy Element w pole wartosc el
		Element <T> *elementTmp = new Element <T>;		//utworzenie tymczasowego obiektu klasy Element
		zmiennyElementGlowny->kolejny = elementTmp;		//wpisanie do obiektu klasy Element adresu tymczasowego obiektu Element
		pierwszyAdres = zmiennyElementGlowny;			//zmiana wartosci pierwszyAdres na adres pierwszego utworzonego obiektu klasy Element
		zmiennyElementGlowny = elementTmp;				//zastapienie zmiennej globalnej obiektu klasy Element obiektem tymczasowym
		rozmiarStosu++;
	}
	else {
		zmiennyElementGlowny->wartosc = el;				//zapisuje wartosc el do obiektu klasy Element
		Element <T> *elementTmp = new Element <T>;		//utworzenie tymczasowego obiektu klasy Element
		zmiennyElementGlowny->kolejny = elementTmp;		//wpisanie do obiektu klasy Element adresu tymczasowego obiektu Element
		zmiennyElementGlowny = elementTmp;				//zastapienie zmiennej globalnej obiektu klasy Element obiektem tymczasowym
		rozmiarStosu++;									//zwiekszenie rozmiaru stosu (listy)
	}
}

template <class T>
void Stos <T>::wyswietlanie() {
	Element <T> * elementTmp;			//lokalny obiekt klasy Element
	elementTmp = pierwszyAdres;			//przypisanie do lokalnego obiektu adresu pierwszego powstalego obiektu w ramach klasy Stos
	for(int i = 0; i < rozmiarStosu; i++) {
		cout << elementTmp->wartosc << endl;	//wyswietlenie wartosci lokalnego obiektu klasy Element
		elementTmp = elementTmp->kolejny;		//wpisanie do lokalnego obiektu adresu kolejnego utworzonego obiektu klasy Element
	}
}

template <class T>
void Stos <T>::usuniecie() {
	if(rozmiarStosu > 0) {
		Element <T> * elementTmp;
		rozmiarStosu--;
		elementTmp = pierwszyAdres;			//przypisanie do lokalnego obiektu adresu pierwszego powstalego obiektu w ramach klasy Stos
		for(int i = 0; i < rozmiarStosu; i++) {
			elementTmp = elementTmp->kolejny;		//wpisanie do lokalnego obiektu adresu kolejnego utworzonego obiektu klasy Element
		}
		zmiennyElementGlowny = elementTmp;
	}
	else cerr << "Stos jest pusty\n";
}

template <class T>
class Lista{
private:
	Element <T> *zmiennyElementPoczatek;//pierwszy utworzony obiekt klasy Element, ktory powstaje razem z utworzeniem obiektu Stos
	Element <T> *zmiennyElementKoniec;	//ostatni utworzony obiekt klasy Element, ktory powstaje razem z utworzeniem obiektu Stos
	int rozmiarListy;
public:
	Lista(): zmiennyElementPoczatek(NULL), zmiennyElementKoniec(NULL), rozmiarListy(0) {};
	~Lista();
	void dodanieNaPoczatku(T el);
	void dodanieNaKoncu(T el);
	void wyswietlanie();
	void usuwanieZPoczatku();
	void usuwanieZKonca();
	void rozmiar() {
		if(rozmiarListy > 0)
			cout << "Rozmiar listy: " << rozmiarListy << endl;
		else cout << "Lista jest pusta\n";
	};
};

template <class T>
void Lista <T>::dodanieNaPoczatku(T el) {
	if (rozmiarListy == 0) {
		zmiennyElementKoniec = new Element <T>;
		zmiennyElementPoczatek = new Element <T>;
		Element <T> * elementTmp = new Element <T>;
		elementTmp->wartosc = el;
		elementTmp->kolejny = zmiennyElementKoniec;
		zmiennyElementKoniec->poprzedni = elementTmp;
		elementTmp->poprzedni = NULL;
		zmiennyElementPoczatek = elementTmp;
		zmiennyElementPoczatek->flaga = 1;
		rozmiarListy++;
	}
	else if(zmiennyElementPoczatek->flaga == 1){
		Element <T> * elementTmp = new Element <T>;
		elementTmp->wartosc = el;
		elementTmp->kolejny = zmiennyElementPoczatek;
		zmiennyElementPoczatek->poprzedni = elementTmp;
		elementTmp->poprzedni = NULL;
		zmiennyElementPoczatek = elementTmp;
		zmiennyElementPoczatek->flaga = 1;
		rozmiarListy++;
	}
	else if(zmiennyElementPoczatek->flaga == 0){
		zmiennyElementPoczatek->wartosc = el;
		zmiennyElementPoczatek->poprzedni = NULL;
		zmiennyElementPoczatek->flaga = 1;
		rozmiarListy++;
	}
}

template <class T>
void Lista <T>::dodanieNaKoncu(T el) {
	if (rozmiarListy == 0) {
		zmiennyElementKoniec = new Element <T>;
		zmiennyElementPoczatek = new Element <T>;
		Element <T> * elementTmp = new Element <T>;
		elementTmp->wartosc = el;
		elementTmp->poprzedni = zmiennyElementPoczatek;
		zmiennyElementPoczatek->kolejny = elementTmp;
		elementTmp->kolejny = NULL;
		zmiennyElementKoniec = elementTmp;
		zmiennyElementKoniec->flaga = 1;
		rozmiarListy++;
	}
	else if(zmiennyElementKoniec->flaga == 1){
		Element <T> * elementTmp = new Element <T>;
		elementTmp->wartosc = el;
		elementTmp->poprzedni = zmiennyElementKoniec;
		zmiennyElementKoniec->kolejny = elementTmp;
		elementTmp->kolejny = NULL;
		zmiennyElementKoniec = elementTmp;
		zmiennyElementKoniec->flaga = 1;
		rozmiarListy++;
	}
	else if(zmiennyElementKoniec->flaga == 0){
		zmiennyElementKoniec->wartosc = el;
		zmiennyElementKoniec->kolejny = NULL;
		zmiennyElementKoniec->flaga = 1;
		rozmiarListy++;
	}
}

template <class T>
void Lista <T>::wyswietlanie() {
	Element <T> * elementTmp;	
	elementTmp = zmiennyElementPoczatek;
	for(int i = 0; i < rozmiarListy; i++) {
		cout << elementTmp->wartosc << endl;
		elementTmp = elementTmp->kolejny;
	}
}

template <class T>
void Lista <T>::usuwanieZKonca() {
	if(rozmiarListy > 0) {
		zmiennyElementKoniec->kolejny = NULL;
		zmiennyElementKoniec->flaga = 0;
		rozmiarListy--;
	}
	else cerr << "Lista jest pusta\n";
}

template <class T>
void Lista <T>::usuwanieZPoczatku() {
	if(rozmiarListy > 1) {
		Element <T> * elementTmp = new Element <T>;
		elementTmp = zmiennyElementPoczatek->kolejny;
		elementTmp->poprzedni = NULL;
		zmiennyElementPoczatek = elementTmp;
		rozmiarListy--;
	}
	else if(rozmiarListy == 1) {
		zmiennyElementKoniec = NULL;
		zmiennyElementPoczatek = NULL;
		rozmiarListy--;
	}
	else  cerr << "Lista jest pusta\n";
}

int main() {
	cout << "Ponizej stos\n\n";
	Stos <float>*s = new Stos <float>;
	s->dodanie(4);
	s->dodanie(6);
	s->dodanie(58);
	s->wyswietlanie();
	s->rozmiar();
	s->usuniecie();
	s->wyswietlanie();
	s->dodanie(14);
	s->wyswietlanie();
	s->dodanie(777);
	s->rozmiar();
	s->wyswietlanie();
	s->usuniecie();s->usuniecie();s->usuniecie();s->usuniecie();
	s->usuniecie();s->usuniecie();s->usuniecie();s->usuniecie();
	s->rozmiar();
	s->wyswietlanie();


	cout << endl;
	cout << "Ponizej lista\n\n";
	Lista <int> *l = new Lista <int>;
	l->dodanieNaKoncu(-1);
	l->dodanieNaPoczatku(14);
	l->usuwanieZPoczatku();
	l->dodanieNaKoncu(1);
	l->usuwanieZPoczatku();
	l->dodanieNaKoncu(2);
	l->dodanieNaKoncu(3);
	l->dodanieNaPoczatku(13);
	l->usuwanieZPoczatku();
	l->usuwanieZPoczatku();
	l->usuwanieZPoczatku();
	l->usuwanieZPoczatku();
	l->usuwanieZPoczatku();
	l->usuwanieZPoczatku();
	l->rozmiar();
	l->usuwanieZPoczatku();
	l->usuwanieZKonca();
	l->usuwanieZKonca();
	l->dodanieNaKoncu(3);
	l->dodanieNaPoczatku(13);
	l->rozmiar();
	l->wyswietlanie();
	system("PAUSE");
	return 0;
}
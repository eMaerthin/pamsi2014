#include <iostream>

using namespace std;

template <class T>
class Element {
public:
	Element(): wartosc(NULL), kolejny(NULL), poprzedni(NULL) {};
	~Element();
	T wartosc;
	Element *kolejny;
	Element *poprzedni;
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
		if(rozmiarStosu != 0)
			cout << "Rozmiar wpisanej listy to: " << rozmiarStosu << endl;
		else cout << "Lista jest pusta\n";
	};
	void usuniecie();
};

template <class T>
void Stos<T>::dodanie(T el) {
	if (pierwszyAdres == NULL) {
		cout << "tak pierwszy element listy\n";
		zmiennyElementGlowny->wartosc = el;				//zapisuje do obiektu klasy Element w pole wartosc el
		Element <T> *elementTmp = new Element <T>;		//utworzenie tymczasowego obiektu klasy Element
		zmiennyElementGlowny->kolejny = elementTmp;		//wpisanie do obiektu klasy Element adresu tymczasowego obiektu Element
		pierwszyAdres = zmiennyElementGlowny;			//zmiana wartosci pierwszyAdres na adres pierwszego utworzonego obiektu klasy Element
		cout << "aktualny adres " << zmiennyElementGlowny << "\twartosc: " << zmiennyElementGlowny->wartosc << " kolejny adres: " << zmiennyElementGlowny->kolejny << endl;
		zmiennyElementGlowny = elementTmp;				//zastapienie zmiennej globalnej obiektu klasy Element obiektem tymczasowym
		rozmiarStosu++;
	}
	else {
		cout << "nie, kolejny element, pierwszy to: " << pierwszyAdres << "\n"; 
		zmiennyElementGlowny->wartosc = el;				//zapisuje wartosc el do obiektu klasy Element
		Element <T> *elementTmp = new Element <T>;		//utworzenie tymczasowego obiektu klasy Element
		zmiennyElementGlowny->kolejny = elementTmp;		//wpisanie do obiektu klasy Element adresu tymczasowego obiektu Element
		cout << "aktualny adres " << zmiennyElementGlowny << "\twartosc: " << zmiennyElementGlowny->wartosc << " kolejny adres: " << zmiennyElementGlowny->kolejny << endl;
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
	Element <T> * elementTmp;
	rozmiarStosu--;
	elementTmp = pierwszyAdres;			//przypisanie do lokalnego obiektu adresu pierwszego powstalego obiektu w ramach klasy Stos
	for(int i = 0; i < rozmiarStosu; i++) {
		elementTmp = elementTmp->kolejny;		//wpisanie do lokalnego obiektu adresu kolejnego utworzonego obiektu klasy Element
	}
	zmiennyElementGlowny = elementTmp;
}

template <class T>
class Lista : public Stos <T> {
public:
	Lista();
	~Lista();
};

int main() {
	Stos <float>*s = new Stos <float>;
	s->dodanie(4);
	cout << endl;
	s->dodanie(6);
	cout << endl;
	s->dodanie(58);
	cout << endl;
	s->wyswietlanie();
	cout << endl;
	s->rozmiar();
	s->usuniecie();
	cout << endl;
	s->wyswietlanie();
	cout << endl;
	s->dodanie(14);
	s->wyswietlanie();
	s->dodanie(777);
	s->rozmiar();
	cout << endl;
	s->wyswietlanie();
	cout << endl;
	s->usuniecie();s->usuniecie();s->usuniecie();s->usuniecie();
	s->rozmiar();
	cout << endl;
	s->wyswietlanie();
	cout << endl;
	system("PAUSE");
	return 0;
}
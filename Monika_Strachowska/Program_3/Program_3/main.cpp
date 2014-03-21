#include <iostream>
#include <stack>
#include <array>
#include <queue>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

template <class T>
T rozwinieciePi(int ktory, int precyzja) {
	long double pi = 0;
	long double tmp = 0;
	int n = 0;
	do {
		tmp = pow((long double)-1,(long double)n)/(2*n+1);
		pi = pi + tmp;
		n++;
	} while (n < 5000);
	pi = pi * 4;
	char* tablica = new char[precyzja + 1]; //bo wpisywana jest kropka
	gcvt(pi, precyzja, tablica);
	//cout.precision(precyzja);
	//cout << "\t" << pi << endl;
	if(ktory >= 1)
		return (int)tablica[ktory + 1] - 48;
	else if(ktory == 0)
		return (int)tablica[ktory] - 48;
}
/**
*	Klasa Stosu
*/
template <class T> //kostruktor i desktruktor
class Stos {
private:
	stack <T> stos;
public:
	void dodawanieElementow();
	void wyswietlanie();
	bool wyszukiwanieElementow();
	void usuwanieElementow();
};

template <class T>
void Stos <T>::dodawanieElementow() {
	T el;
	cout << "Jaki element chcesz wprowadzic?\n";
	cin >> el;
	stos.push(el);
}

template <class T>
void Stos <T>::wyswietlanie() {			//DA SIE PEWNIE LADNIEJ
	cout << "\nZawartosc stosu:\n";
	stack <T> tmp;
	T tmpel;
	while(!stos.empty()) {
		cout << stos.top() << endl;
		tmpel = stos.top();
		stos.pop();
		tmp.push(tmpel);
	}
	while(!tmp.empty()){
		tmpel = tmp.top();
		tmp.pop();
		stos.push(tmpel);
	}
}

template <class T>
void Stos <T>::usuwanieElementow() {
	stos.pop();
}

template <class T>
bool Stos <T>::wyszukiwanieElementow() {
	T el;
	cout << "Jaki element wyszukac?\n";
	cin >> el;
	for(int i = 0; i < stos.size(); i++) {
		if((stos.top() - i) == el) {
			cout << "Element znajduje sie w stosie"
				<< "\njest to " << i << " element od gory\n";
			return true;
		}
	}
	cout << "Nie ma takiego elementu na stosie\n";
	return false;
}

/**
*	Klasa Kopca
*/
template <class T>
class Kopiec {
private:
	int rozmiar;
	int poziomy;
	T* kopiec;
public:
	Kopiec(): rozmiar(0), poziomy(0) {};
	Kopiec(int rozm): rozmiar(rozm), poziomy(sqrt((double)rozm) + 1) {
		kopiec = new T [rozmiar];
	};
	~Kopiec();
	void deklaracjaTablicy();
	void przywracanieKopca();
	void wyswietlanieKopca();
	void usuwanieSzczytu();
	void kopcowanie(T a);
};

template <class T>
void Kopiec <T>::deklaracjaTablicy() {
	T random;
	for(int i = 0; i < rozmiar; i++) {
		kopiec[i] = rozwinieciePi <T> (i,rozmiar);
	}
	for(int i = 0; i < rozmiar; i++) {
		cout << kopiec[i] << "  ";
	}
	cout << endl;cout << endl;
}

///kopiec mozna zapisac w tablicy i wtedy:
// rodzic [i]
// dzieci [2i+1] oraz [2i+2]
template <class T>
void Kopiec <T>::wyswietlanieKopca() {
	int poziom = 0;
	int stala = 1;
	int wysrodkowanie = -1;
	for(int i = 0; i < rozmiar; i++) {
		if(i == stala) {
			poziom++;
			stala = stala + pow(2,(double)poziom);
			cout << endl;
		}
	cout << kopiec[i] << " ";
	}
	/*//Druga opcja to z przesuwaniem bitowym:
	cout << "\n\n";
	int spr = 1;
	int n = rozmiar;
	for(int i = 0; i < poziom + 1; i++) {
		spr = 1 << i;
		for(int k = 0; k < pow((double)2, (double)i); k++) {
			spr += k;
			cout << kopiec[rozmiar - n] << "\t";
			n--;
			if(n == 0) break;
		}
		cout << endl;
	}*/
}

template <class T>
void Kopiec <T>::przywracanieKopca() {
	for(int k = 0; k < poziomy; k++)
		for(int i = 0; i < rozmiar; i++)
			kopcowanie(i);
}

template <class T>
void Kopiec <T>::kopcowanie(T a) {
	int lewy, prawy, rodzic;
	if(a != 0) {
		lewy = 2 * a + 1;
		prawy = 2 * a + 2;
		rodzic = a;
	}
	else {
		lewy = 1;
		prawy = 2;
		rodzic = a;
	}
	if (lewy <= rozmiar && kopiec[lewy] > kopiec[rodzic]) {
		rodzic = lewy;
	}
	if(prawy <= rozmiar && kopiec[prawy] > kopiec[rodzic]) {
		rodzic = prawy;
	}
	if(rodzic != a) {
		T tmp = kopiec[a];
		kopiec[a] = kopiec[rodzic];
		kopiec[rodzic] = tmp;
		kopcowanie(rodzic);
	}
}

template <class T>				//O CO CHODZI? CZY O TO?
void Kopiec <T>::usuwanieSzczytu(){			
	rozmiar--;
	for(int i = 0; i < rozmiar; i++) {
		kopiec[i] = kopiec[i+1];
	}
	poziomy = sqrt((double)rozmiar) + 1;
	przywracanieKopca();
}

template <class T>
class Kolejka {
	queue <T> kolejka;
public:
	//Kolejka();
	//~Kolejka();
	void dodawanie(T el);		//elementow na koniec kolejki
	T pobieranie();				//elementow z poczatku kolejki(usuwanie)
	void wyswietlanieDlugosci();//kolejki
	void wyswietlanie();		//zawartosci kolejki
};

template <class T>
void Kolejka <T>::dodawanie(T el) {
	kolejka.push(el);
}

template <class T>
void Kolejka <T>::wyswietlanie() {
	cout << "\nZawartosc kolejki:\n";
	queue <T> tmp;
	T tmpel;
	while(!kolejka.empty()) {
		cout << kolejka.front() << endl;
		tmpel = kolejka.front();
		kolejka.pop();
		tmp.push(tmpel);
	}
	while(!tmp.empty()){
		tmpel = tmp.front();
		tmp.pop();
		kolejka.push(tmpel);
	}
}

template <class T>
void Kolejka <T>::wyswietlanieDlugosci() {
	cout << "\nDlugosc kolejki: " << kolejka.size() << endl;
}

template <class T>				//Ma usuwac tez pierwszy? Czy tylko wyswietlac?
T Kolejka <T>::pobieranie() {
	T el = kolejka.front();
	kolejka.pop();
	return el;
}

int main() {
	cout << "STOS\n\n";

	Stos <float> *s = new Stos <float>;
	s->dodawanieElementow();
	s->dodawanieElementow();
	s->dodawanieElementow();
	s->wyswietlanie();
	s->wyszukiwanieElementow();
	s->wyswietlanie();
	

	cout << "\n\nKOPIEC\n\n";
	int rozmiar = 0;
	cout << "Podaj ile elementow ma miec tablica\n";
	cin >> rozmiar;
	Kopiec <int> *p = new Kopiec <int>(rozmiar);
	p->deklaracjaTablicy();
	p->wyswietlanieKopca();
	p->przywracanieKopca();
	cout << endl << endl;
	p->wyswietlanieKopca();
	p->usuwanieSzczytu();
	cout << endl << endl;
	p->wyswietlanieKopca();

	cout << "\n\nKOLEJKA\n\n";
	Kolejka <int> *k = new Kolejka <int>;
	k->dodawanie(3);
	k->dodawanie(4);
	k->dodawanie(31);
	k->dodawanie(14);
	k->wyswietlanie();
	k->wyswietlanieDlugosci();
	k->pobieranie();
	k->wyswietlanie();
	k->wyswietlanieDlugosci();

	cout << endl;
	system("PAUSE");
	return 0;
}
#include <iostream>
#include <stack>
#include <array>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

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

template <class T>
class Kopiec {
private:
	int rozmiar;
	T* kopiec;
public:
	Kopiec(): rozmiar(0) {};
	Kopiec(int rozm): rozmiar(rozm) {
		kopiec = new T [rozmiar];
	};
	~Kopiec();
	void deklaracjaTablicy();
	void przywracanieKopca();
	void wyswietlanieKopca();
	void usuwanieSzczytu();
};

template <class T>
void Kopiec <T>::deklaracjaTablicy() {
	int dolny(0), gorny(0);
	srand((T)(time(NULL)));
	cout << "Podaj zakres\t dolny i gory\n";
	cin >> dolny >> gorny;
	cout << endl;
	T random;
	for(int i = 0; i < rozmiar; i++) {
		random = rand() % gorny + dolny;
		kopiec[i] = random;
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
		cout << kopiec[i] << "  ";
	}
}

int main() {
	/*Stos <float> *s = new Stos <float>;
	s->dodawanieElementow();
	s->dodawanieElementow();
	s->dodawanieElementow();
	s->wyswietlanie();
	s->wyszukiwanieElementow();
	s->wyswietlanie();*/

	int rozmiar = 0;
	cout << "Podaj ile elementow ma miec tablica\n";
	cin >> rozmiar;
	Kopiec <int> *k = new Kopiec <int>(rozmiar);
	k->deklaracjaTablicy();
	k->wyswietlanieKopca();

	cout << endl;
	system("PAUSE");
	return 0;
}
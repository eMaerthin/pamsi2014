#include<iostream>
#include<algorithm>
#include<vector>
#include<Windows.h>
#include<string>
#include<fstream>
#include<random>
#include<stdlib.h>
#include<time.h>
using namespace std;

template<class Typ>
class Tablica{
	int rozmiar;
	Typ *tab;
	void buble();
	void heap();
	void quick(Typ *first, Typ *last);
	void get_rozmiar(int x);
public:
	void Usun();
	bool Wczytaj(string name);
	bool Zapisz(string name);
	bool Wczytaj(string name, int x);
	__int64 bublesort();
	__int64 heapsort();
	__int64 quick();
	void Los(int typ_los);
	void sort_czesci(int x);
	void przepisz(Tablica<Typ> Z);
	void startowa(int size, int typ_los, int posortowanie);
	void Dodaj(Tablica<Typ> Posortowana, Tablica<Typ> Nieposortowana);
};

template<class Typ>
void Tablica<Typ>::Dodaj(Tablica<Typ> Posortowana, Tablica<Typ> Nieposortowana){
	get_rozmiar(Posortowana.rozmiar+Nieposortowana.rozmiar);							//Utworzenie tablicy
	int i;
	int j=0;
	for(i=0; i<Posortowana.rozmiar; i++){
		tab[i]=Posortowana.tab[i];														//Przepisanie czêœci posortowanej
	}
	for(i=i; i<rozmiar; i++){
		tab[i]=Nieposortowana.tab[j];													//Dopisanie do czêœci posortowanej czêœci nie posortowanej
		j++;
	}
}

template<class Typ>
void Tablica<Typ>::Usun(){
	delete[] tab;
}

template<class Typ>
void Tablica<Typ>::startowa(int size, int typ_los, int posortowanie){
	int y;
	y=0;
	Tablica<Typ> Posortowana;
	Tablica<Typ> Nieposortowana;
	switch(posortowanie){
	case 0:{
		y=0;
		get_rozmiar(size);														//utworzenie tablicy
		Los(typ_los);															//Losowanie elementów( rodzaj losowania okreœla zmienna typ_los
		break;
		   }
	case 1:{
		y=size/10;																//iloœæ posortowanych elementów
		Posortowana.get_rozmiar(y);												//Czêœæ posorotwana
		Nieposortowana.get_rozmiar(size-y);										//Czêœæ nieposortowana
		Posortowana.Los(typ_los);												//Losowanie elementów do czêœci posortowanej
		Nieposortowana.Los(typ_los);											//Losowanie elementów do czêœci nieposortowanej
		Posortowana.quick();													//Sortowanie czêœci posortowanej
		Dodaj(Posortowana, Nieposortowana);										//Z³o¿enie tablicy
		break;
		   }
	case 2:{
		y=size/2;
		Posortowana.get_rozmiar(y);
		Nieposortowana.get_rozmiar(size-y);
		Posortowana.Los(typ_los);
		Nieposortowana.Los(typ_los);
		Posortowana.quick();
		Dodaj(Posortowana, Nieposortowana);
		break;
		   }
	case 3:{
		y=(size-size/10);
		Posortowana.get_rozmiar(y);
		Nieposortowana.get_rozmiar(size-y);
		Posortowana.Los(typ_los);
		Nieposortowana.Los(typ_los);
		Posortowana.quick();
		Dodaj(Posortowana, Nieposortowana);
		break;
		   }
	default:{
		break;
			}
	}
}
//Losowanie elementów
template<class Typ>
void Tablica<Typ>::Los(int typ_los){
	int i;
	int x;
	srand(time(NULL));												//U¿yte by funkcja random nnie losoa³a ci¹gle tych samych liczb
	x=rand()%100+1;
	switch(typ_los){
	case 0:{
		default_random_engine generator;
		uniform_int_distribution<double> distribution(0,x);
		for(i=0; i<rozmiar; i++){
			tab[i]=distribution(generator);							//Wype³nianie tablicy losowymi liczbami z rozk³adu jednostkowego
		}
		break;
		}
	case 1:{
		default_random_engine generator;
		normal_distribution<double> distribution(100, x);
		for(i=0; i<rozmiar; i++){
			tab[i]=distribution(generator);							//Wype³nianie tablicy losowymi liczbami z rozk³adu normalnego
		}
		break;
		}
	case 2:{
		default_random_engine generator;
		poisson_distribution<double> distribution(x+0.1);
		for(i=0; i<rozmiar; i++){
		tab[i]=distribution(generator);							//Wype³nianie tablicy losowymi liczbami z rozk³adu Poisson'a
		}
		break;
		}
	default:{
		break;
		}
	}
}
//Funkacja przepisuje elementy jednej tablicy do drugiej
template<class Typ>
void Tablica<Typ>::przepisz(Tablica<Typ> Z){
	int i;
	get_rozmiar(Z.rozmiar);
	for(i=0; i<rozmiar; i++){
		tab[i]=Z.tab[i];
	}
}
//funkcja zmienia rozmiar tablicy tab na zadany.
template<class Typ>
void Tablica<Typ>::get_rozmiar(int x){
	rozmiar=x;
	tab=new Typ[rozmiar];
}
//Funkcja wczytuje tablice z wybranego pliku.
template<class Typ>
bool Tablica<Typ>::Wczytaj(string name){
	ifstream plik;
	int x;
	string tekst;

	plik.open(name);
	if(plik.is_open()){
		plik>>tekst;
		plik>>x;
		get_rozmiar(x);
		for(int i=0; i<rozmiar; i++){
			plik>>tab[i];
		}
		plik.close();
		cout<<"Tablica zostala wczytana pomyslnie"<<endl;
		return true;
	} else {
		plik.close();
		cout<<"Plik nie zostal poprawnie otwarty"<<endl;
		return false;
	}
}
//Funkcja wczytuje tablice z wybranego pliku. Wczytuje pierwsze x elementów
template<class Typ>
bool Tablica<Typ>::Wczytaj(string name, int x){
	ifstream plik;
	int j;
	string tekst;
	plik.open("tablica.txt");
	if(plik.is_open()){
		plik>>tekst;
		plik>>j;
		get_rozmiar(x);
		for(int i=0; i<rozmiar; i++){
			plik>>tab[i];
		}
		plik.close();
		cout<<"Tablica zostala wczytana pomyslnie"<<endl;
		return true;
	} else {
		plik.close();
		cout<<"Plik nie zostal poprawnie otwarty"<<endl;
		return false;
	}
}

template<class Typ>
bool Tablica<Typ>::Zapisz(string name){
	ofstream plik;

	plik.open(name);
	if(plik.is_open()){
		plik<<"rozmiar: "<<rozmiar<<endl;
		for(int i=0; i<rozmiar; i++){
			plik<<tab[i]<<endl;
		}
		plik.close();
		return true;
	} else {
		plik.close();
		cout<<"Plik nie zostal poprawnie zapisana"<<endl;
		return false;
	}
}

template<class Typ>
void Tablica<Typ>::buble(){
	int i;
	Typ zastap;
	bool koniec=false;

	while(!koniec){										
		koniec=true;								//warunek zakonczenia petli ustawiamy na prawde
		for(i=1; i<rozmiar; i++){					//zwiekszajac zmienna i otrzymujemy coraz dalszy od konca indeks tablicy
			if(tab[rozmiar-i]>tab[rozmiar-(i+1)]){	//sprawdzamy czy element jest wiekszy od elementu poprzedzajacego go
				zastap=tab[rozmiar-i];				//zapisujemy element do zmiennej pomocniczej
				tab[rozmiar-i]=tab[rozmiar-(i+1)];	//zamisujemy do elementu element poprzedzajacy go
				tab[rozmiar-(i+1)]=zastap;			//wpisujemy elemenet do indeksu poprzedajacego go
				koniec=false;						//wykonanie funkcji oznacza ze zostala wykonana przynajmniej jedna operacja zamiany wiec tablica nie jest jeszcze posortowana
			}
		}
	}
}

template<class Typ>
void Tablica<Typ>::heap(){
	for(int i=0; i<rozmiar-1; i++){			//dla i mniejszych od rozmiaru tablicy
		make_heap(tab+i, tab+rozmiar);		//zmniejszaj¹c zakres tablicy wywolujemy metode kopca ktora przesuwa najwiekszy element na poczatek zakresu
	}
}

template<class Typ>
__int64 Tablica<Typ>::quick(){
	__int64 s, k;
	QueryPerformanceCounter((LARGE_INTEGER*) &s);
	quick(tab, tab+(rozmiar-1));									//Wywoluje funkcje sortowania szybkiego dla zakresu calej tablicy
	QueryPerformanceCounter((LARGE_INTEGER*) &k);
	return k-s;
}

template<class Typ>
__int64 Tablica<Typ>::bublesort(){
	__int64 s, k;
	QueryPerformanceCounter((LARGE_INTEGER*) &s);
	buble();
	QueryPerformanceCounter((LARGE_INTEGER*) &k);
	return k-s;
}

template<class Typ>
__int64 Tablica<Typ>::heapsort(){
	__int64 s, k;
	QueryPerformanceCounter((LARGE_INTEGER*) &s);
	heap();
	QueryPerformanceCounter((LARGE_INTEGER*) &k);
	return k-s;
}

template<class Typ>
void Tablica<Typ>::quick(Typ *first, Typ *last){
	Typ *first1;
	Typ *last1;
	Typ *first2;
	Typ *last2;
	Typ *j, *i;
	Typ x;
	if(first!=last){
		j=first;									//Ustawienie wskaznika j na pierwszy element tablicy
		for(i=first; i<last; i++){
			if(*i>*last){							//ostatnia liczba jest piwotem
				x=*i;								
				*i=*j;								//przypisanie liczby wiêkszej od piwotu w miesce wskaznika j
				*j=x;
				j++;
			}
		}
		x=*last;									// Po skoñczeniu porz¹dkowania piwot jest wstawiany na miejsce wskaznika j
		*last=*j;
		*j=x;

		first1=first;								//Podzia³ zakresów do nowego wywo³ania funkcji
		last1=j-1;
		first2=j+1;
		last2=last;
		if(first1!=j){								//Wywo³ania rekurencyjne
		quick(first1, last1);
		}
		if(last2!=j){
		quick(first2, last2);
		}
	}
}
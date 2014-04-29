/*
Zrobiæ sprawozdanie.
*/
#include<cstdlib>
#include<fstream>
#include<iostream>
#include"Tablica.h"
#include"Stos.h"
#include<random>
using namespace std;


Tablica<double> szybko(int size, int ktory, int uporzadkowanie){
	Tablica<double> T;
		T.startowa(size, ktory, uporzadkowanie);
		return T;
}
//Funkcja s³u¿y do szybkiego uzyskania wyników dla 3 algorytmów przy wszystkich mo¿liwoœciach do 10000 elementów.
void Test(){
	Tablica<double> T, B, K, Q;
	Stos B1, K1, Q1;
	int y, z;
	unsigned int x=100;
	__int64 b, k, q;
	ofstream plik;

	plik.open("dane2.txt");
	if(plik.is_open()){
	
		while(x<10001){
		cout<<"Iloœc elementów: "<<x<<endl;
		plik<<"iloœæ elementow: "<<x<<endl;
		for(y=0; y<3; y++){
			cout<<"rozklad: "<<y<<endl;
			plik<<"rozklad: "<<y<<endl;
			for(z=0; z<4; z++){
					cout<<"ilosc posortowanych elementow: "<<z<<endl;
					plik<<"ilosc posortowanych elementow: "<<z<<endl;
				for(int i=0; i<100; i++){
					b=0;
					k=0;
					q=0;
					T.przepisz(szybko(x,y,z));
					if(x<10001){
						B.przepisz(T);
						K.przepisz(T);
					
					}
					Q.przepisz(T);
					T.Usun();
					if(x<10001){
						b=B.bublesort();
						B1.push(b);
						B.Usun();
						k=K.heapsort();
						K1.push(k);
						K.Usun();
					}
					q=Q.quick();
					Q1.push(q);
					Q.Usun();
					cout<<i<<" ";
				}
				cout<<endl;
				q=Q1.srednia();
			if(x<10001){
				b=B1.srednia();
				k=K1.srednia();
				cout<<"Sortowanie Babelkowe: "<<b<<endl;
				plik<<"Sortowanie Babelkowe: "<<b<<endl;
				cout<<"Sortowanie przez Kopcowanie: "<<k<<endl;
				plik<<"Sortowanie przez Kopcowanie: "<<k<<endl;
			}
				cout<<"Sortowanie Szybkie: "<<q<<endl;
				plik<<"Sortowanie Szybkie: "<<q<<endl;
				plik<<endl;
				cout<<endl;
			}
			plik<<endl;
			cout<<endl;
		}
		plik<<endl;
			x=x*10;
		}
	}
	
	plik.close();
}

Tablica<double> menu(){
	Tablica<double> T;
	int size;
	int ktory;
	int uporzadkowanie;
	bool koniec=false;

	cout<<"Podaj rozmiar tablicy: ";
	cin>>size;
	cout<<size<<endl;
	while(!koniec){
		cout<<"0 - sortowanie tablicy z rozkladu jednostajnego"<<endl;
		cout<<"1 - sortowanie tablicy z rozkladu normalnego"<<endl;
		cout<<"2 - sortowanie tablicy z rozkladu Poissona"<<endl;
		cin>>ktory;
		if(ktory==0 || ktory==1 || ktory==2){
			koniec=true;
		} else {
			cout<<"nie ma takiej opcji"<<endl<<endl;
		}
	}
	koniec=false;
	while(!koniec){
		cout<<"0 - sortowanie nieuporzadkowanej tablicy"<<endl;
		cout<<"1 - sortowanie tablicy z 10% uporzadkowanymi elementami"<<endl;
		cout<<"2 - sortowanie tablicy z 50% uporzadkowanymi elementami"<<endl;
		cout<<"3 - sortowanie tablicy z 90% uporzadkowanymi elementami"<<endl;
		cin>>uporzadkowanie;
		if(ktory==0 || ktory==1 || ktory==2 || ktory==3){
			koniec=true;
		} else {
			cout<<"nie ma takiej opcji"<<endl<<endl;
		}
	}
	T.startowa(size, ktory, uporzadkowanie);
	return T;
}

int main(){
	Tablica<double> T, B, K, Q;
	char zeta;
	bool koniec=false;
	int y, z;
	unsigned int x=100000;
	__int64 b, k, q;
	Stos Q1;
	ofstream plik;
	int licz=0;
	int j;
	string ilosc[5]={"100", "1000", "10000", "100000", "1000000"};
/*
	while(!koniec){
		T.przepisz(menu());
		T.quick();
		T.Zapisz("tab.txt");
		cout<<"Czy powtorzyc badanie?(0-jesli nie): ";
		cin>>zeta;
		if(zeta=='0'){
			koniec=true;
			}
	}
*/
	plik.open("qucksort100000.txt");
	while(x<1000001){
		cout<<"Iloœc elementów: "<<x<<endl;
		plik<<"iloœæ elementow: "<<x<<endl;
		for(y=0; y<3; y++){
			cout<<"rozklad: "<<y<<endl;
			plik<<"rozklad: "<<y<<endl;
			for(z=0; z<4; z++){
					cout<<"ilosc posortowanych elementow: "<<z<<endl;
					plik<<"ilosc posortowanych elementow: "<<z<<endl;
					Q.przepisz(szybko(x, y, z));
					q=Q.quick();
				cout<<"Sortowanie Szybkie: "<<q<<endl;
				plik<<"Sortowanie Szybkie: "<<q<<endl;
			}
				plik<<endl;
				cout<<endl;
				plik<<endl;
			cout<<endl;
			}
			
		plik<<endl;
			x=x*10;
	}
	plik.close();
		system("Pause");
}
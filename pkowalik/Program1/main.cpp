#include<iostream>
#include "Tablica.h"
using namespace std;

/*
*Funkacja wypisujaca tekst menu glownego.
*/
void menu(){
	cout << "1.Wczytanie tablicy z konsoli"<<endl;
	cout << "2.Wyswietlenie tablicy"<<endl;
	cout << "3.Wczytywanie z pliku tekstowego"<<endl;
	cout << "4.Zapisywanie do pliku tekstowego"<<endl;
	cout << "5.Wczytywanie z pliku binarnego"<<endl;
	cout << "6.Zapisywanie do pliku binarnego"<<endl;
	cout << "7.Wypelnianie tablicy"<<endl;
	cout << "8.Oproznij tablice"<<endl;
	cout << "$.Zapisz do schowka"<<endl;
	cout << "&.Poka¿ schowek"<<endl;
	cout << "#.Oproznij tablice"<<endl;
	cout << "0.Koniec"<<endl;
	cout << "Wybierz opcjê: ";
}


int main() {
	Tablica<int> A;			//Wektor g³owny
	Tablica<int> B;			//Wektor schowka
	char wybor;				//Wybor uzytkownika
	bool koniec=false;		//Warunek zakonczenia petli(konca programu)

	do {
		menu();
		cin>>wybor;
		switch(wybor) {
		case '0':{
			koniec=true;
			break;
			   }
		case '1':{
			cin>>A;		         //Wpisanie z konsoli
			break;
			   }
		case '2':{
			cout<<A;			//Wypisanie na konsole
			break;
			   }
		case '3':{
			A.Wpisz_z_txt();	//Wypisanie z pliku tekstowego
			break;
			   }
		case '4':{
			A.Wpisz_do_txt();   //Wpisanie do pliku tekstowego
			break;
			   }
		case '5':{
			A.Wpisz_z_bin();	//Wypisanie z pliku binarnego
			break;
			   }
		case '6':{
			A.Wpisz_do_bin();	//Wpisanie do pliku binarnego
			break;
			   }
		case '7':{
			A.Random();			//Losowanie liczb losow
			break;
			   }
		case '8':{
			A.clear();			//Czyszczenie tablicy
			break;
			   }
		case '$': {
			B=A;				//Przypisanie do tablicy schowka
			break;
				  }
		case '&': {
			cout<<B;			//Sprawdzenie tablicy schowka
			break;
				  }
		case '#': {
			A=B;				//Przypisanie ze schowka
			break;
				  }
		default:{
			cout<<"Nie ma takiej funkcji"<<endl;
			break;
				}
		}
		cout<<endl<<endl;
	}while(koniec!=true);
}
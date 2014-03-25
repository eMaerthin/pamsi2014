#include<iostream>
#include"Stos.h"
#include"Kopiec.h"
#include"Kolejka.h"
using namespace std;

/*
int menu() {
	int x;
	cout<<"MENU:"<<endl;
	cout<<"1.Dodaj na stos"<<endl;
	cout<<"2.Sciagnij ze stosu"<<endl;
	cout<<"3.Sprawdz czy jest liczba"<<endl;
	cout<<"4.Wyczysc stos"<<endl;
	cout<<"5.Wyswietl stos"<<endl;
	cout<<"0.Zakoncz program"<<endl;
	cin>>x;
	return x;
}
*/

int main() {
	Kopiec A;
	cout<<"Wypisanie Kopca z 7-toma losowymi liczbami:"<<endl;
	A.Wypelnij(31);
	cout<<"Kopiec: ";
	A.Wyswietl();
	cout<<endl<<endl;
	A.WypiszKopiec();
	cout<<endl;
	cout<<endl;
	cout<<endl;

	Stos B;
	B.push(1);
	B.push(2);
	B.push(3);
	B.push(4);
	B.push(5);
	cout<<"Stos zawiera "<< B.size()<<" elementow:"<<endl;
	B.Wypisz();
	cout<<endl;
	cout<<endl;
	B.pop();
	cout<<"Po zdjeciu jednej liczby Stos zawiera "<< B.size()<<" elementow:"<<endl;
	B.Wypisz();
	cout<<endl;
	cout<<endl;
	cout<<"Szukamy liczby 3"<<endl;
	B.Znajdz(3);
	cout<<"Szkuamy liczby 7"<<endl;
	B.Znajdz(7);
	cout<<endl;
	cout<<endl;
	cout<<endl;

	Kolejka C;
	int D;
	C.push(1);
	C.push(2);
	C.push(3);
	C.push(4);
	C.push(5);
	cout<<"Kolejka zawiera "<< C.size()<<" elementow:"<<endl;
	C.Wyswietl();
	cout<<endl;
	cout<<endl;
	D=C.pop();
	cout<<"Po zdjeciu jednej liczby Kolejka zawiera "<< C.size()<<" elementow:"<<endl;
	C.Wyswietl();
	cout<<endl;
	cout<<endl;
	cout<<endl;

	system("Pause");
}
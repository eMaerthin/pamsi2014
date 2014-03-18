#include<iostream>
#include"Stos.h"
#include"Lista.h"
using namespace std;

int main() {
	Stos S;
	Lista L, L2;

	cout<<"Stos"<<endl;
	S.push(5);
	S.push(4);
	S.push(3);
	S.push(2);
	S.push(1);
	S.Wypisz();
	cout<<endl;
	S.Wypisz_odwrotnie();
	cout<<endl<<endl;

	cout<<"Lista1"<<endl;
	L.push_front(5);
	L.push_back(4);
	L.push_front(3);
	L.push_back(2);
	L.push_front(1);
	L.Wypisz();
	cout<<endl;
}

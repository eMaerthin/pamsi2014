#ifndef STOS_H
#define STOS_H

#include<iostream>
#include"Element.h"
using namespace std;

class Stos {
	int rozmiar;
	Element* elem;
	
public:
	Stos();
	Element* Elem();
	void push(int x);
	void pop();
	bool empty();
	int size();
	void Wypisz();
	void Wypisz_odwrotnie();
	bool Zdejmij();
};
#endif
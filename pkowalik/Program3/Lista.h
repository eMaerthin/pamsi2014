#ifndef LISTA_H
#define LISTA_H

#include<iostream>
#include"ElementListy.h"
using namespace std;

class Lista {
	int rozmiar;
	ElementListy* elem;
	ElementListy* last;
	ElementListy* first;
	void push_el0(int x);
	
public:
	Lista();
	ElementListy* Elem();
	void push_back(int x);
	void push_front(int x);
	void pop_back();
	void pop_front();
	bool empty();
	int size();
	void Wypisz();
	bool Zdejmij_tyl();
	bool Zdejmij_przod();
};
#endif

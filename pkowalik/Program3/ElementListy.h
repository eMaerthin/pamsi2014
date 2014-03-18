#ifndef ELEMENTLISTY_H
#define ELEMENTLISTY_H

#include<iostream>
using namespace std;

struct ElementListy {
	ElementListy* prev;
	int liczba;
	ElementListy* next;

	ElementListy();
};

#endif

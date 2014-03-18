#ifndef ELEMENT_H
#define ELEMENT_H
#include<iostream>
using namespace std;

struct Element {
	int liczba;
	Element* next;

	Element();
};
#endif
#include<iostream>
using namespace std;

template<class typ>
struct Elem{
	unsigned int w2;
	typ waga;
	Elem();
};

template<class typ>
Elem<typ>::Elem(){
	w2=0;
}
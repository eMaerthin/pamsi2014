#ifndef ELEMENT_H
#define ELEMENT_H
#include<iostream>
#include<vector>
using namespace std;

template<class typ>
class Element{
	unsigned int wierzcholek1;
	unsigned int wierzcholek2;
	typ _waga;
public:
	unsigned int w1();
	unsigned int w2();
	typ waga();
	unsigned int Wiekszy();
	bool porownaj(Element<typ> y);
	void Utworz(unsigned int wierzcholek1, unsigned int wierzcholek2, typ waga);
	void Utworz(Element<typ>);
	bool porownaj_wagi(Element<typ> y);
	bool PorownajElementy(Element<typ> El);
};

template<class typ>
unsigned int Element<typ>::w1(){
	return wierzcholek1;
}

template<class typ>
unsigned int Element<typ>::w2(){
	return wierzcholek2;
}

template<class typ>
typ Element<typ>::waga(){
	return _waga;
}

template<class typ>
void Element<typ>::Utworz(unsigned int x1, int unsigned x2, typ x){
	wierzcholek1=x1;
	wierzcholek2=x2;
	_waga=x;
}

template<class typ>
void Element<typ>::Utworz(Element<typ> El){
	wierzcholek1=El.w1();
	wierzcholek2=El.w2();
	_waga=El.waga();
}

template<class typ>
bool Element<typ>::porownaj(Element<typ> y){
	if(wierzcholek1<y.wierzcholek1){
		return true;
	} else {
		return false;
	}
}

template<class typ>
bool Element<typ>::porownaj_wagi(Element<typ> y){
	if(_waga<y._waga){
		return true;
	} else {
		return false;
	}
}

template<class typ>
unsigned int Element<typ>::Wiekszy(){
	if(wierzcholek1>wierzcholek2){
		return wierzcholek1;
	}else{
		return wierzcholek2;
	}
}

template<class typ>
bool Element<typ>::PorownajElementy(Element<typ> El1){
	bool rowne=false;
	if(El1.w1()==w1() && El1.w2()==w2() && El1.waga()==waga()){
		rowne=true;
	}
	return rowne;
}
#endif
#ifndef LISTAELEM_H
#define LISTAELEM_H
#include<iostream>
#include<vector>
#include<fstream>
#include"Element.h"
using namespace std;

template<class typ>
class ListaElem{
	vector<Element<typ>> K;

public:
	ListaElem();
	unsigned int rozmiar();
	void push(Element<typ> x);
	unsigned int size();
	unsigned int rozpientosc();
	Element<typ> & operator[](unsigned int i);
	void Wypisz();
	void push_waga(Element<typ> x);
};

template<class typ>
ListaElem<typ>::ListaElem(){
	K.clear();
}

template<class typ>
Element<typ> & ListaElem<typ>::operator[](unsigned int i){
	return K[i];
}

template<class typ>
unsigned int ListaElem<typ>::rozmiar(){
	return K.size();
}

template<class typ>
void ListaElem<typ>::push(Element<typ> x){
	unsigned int i;
	bool wlozony=false;
	for(i=0; i<K.size(); i++){
		if(x.porownaj(K[i])){
			K.insert(K.begin()+i, x);
			wlozony=true;
			break;
		}
	}
	if(wlozony!=true){
		K.push_back(x);
	}
}

template<class typ>
void ListaElem<typ>::push_waga(Element<typ> x){
	unsigned int i;
	bool wlozony=false;
	
	for(i=0; i<K.size(); i++){
		if(x.porownaj_wagi(K[i])){
			K.insert(K.begin()+i, x);
			wlozony=true;
			break;
		}
	}
	if(wlozony!=true){
		K.push_back(x);
	}
}


template<class typ>
unsigned int ListaElem<typ>::size(){
	return K.size();
}

template<class typ>
unsigned int ListaElem<typ>::rozpientosc(){
	unsigned int maks=K[0].w1();
	if(K.size()>1){
		for(unsigned int i=1; i<K.size(); i++){
			if(K[i-1].Wiekszy()<K[i].Wiekszy()){
				maks=K[i].Wiekszy();
			}
		}
	}
	return maks;
}

template<class typ>
void ListaElem<typ>::Wypisz(){
	for(int i=0; i<K.size(); i++){
		cout<<K[i].w1()<<"  "<<K[i].w2()<<"      "<<K[i].waga()<<endl;
	}
}

#endif
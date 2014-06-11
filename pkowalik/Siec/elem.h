#include<iostream>
using namespace std;

template<class typ>
class elem{
	unsigned int _w1;
	typ _max;
public:
	elem();
	elem(const elem<typ> & El);
	elem<typ> & operator=(const elem<typ> & El);
	elem<typ> get(unsigned int x1, typ xmax);
	unsigned int w1();
	typ max();
};

template<class typ>
elem<typ>::elem(){
	_w1=0;
	_max=0;
}

template<class typ>
elem<typ>::elem(const elem<typ> & El){
	_w1=El._w1;
	_max=El._max;
}

template<class typ>
elem<typ> & elem<typ>::operator=(const elem<typ> & El){
	_w1=El._w1;
	_max=El._max;
	return *this;
}

template<class typ>
elem<typ> elem<typ>::get(unsigned int x1, typ xmax){
	_w1=x1;
	_max=xmax;
	return *this;
}

template<class typ>
unsigned int elem<typ>::w1(){
	return _w1;
}

template<class typ>
typ elem<typ>::max(){
	return _max;
}
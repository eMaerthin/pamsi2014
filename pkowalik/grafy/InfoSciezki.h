#include<iostream>
using namespace std;

template<class typ>
struct InfoSciezki{
	unsigned int w1;
	typ wagaPolaczenia;
	typ wagaSciezki;

	void get(unsigned int w1, typ wagaPolaczenia, typ wagaSciezki);
};

template<class typ>
void InfoSciezki<typ>::get(unsigned int _w1, typ _wagaPolaczenia, typ _wagaSciezki){
	w1=_w1;
	wagaPolaczenia=_wagaPolaczenia;
	wagaSciezki=_wagaSciezki;
}
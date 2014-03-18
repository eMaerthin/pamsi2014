#include"Stos.h"
using namespace std;

Stos::Stos(){
	rozmiar=0;
	elem=new Element;
}

Element* Stos::Elem(){
	return elem;
}

bool Stos::empty(){
	if(elem->next==NULL) {
		return true;
	} else {
		return false;
	}
}

int Stos::size(){
	return rozmiar;
}

void Stos::push(int x){
	Element* i= new Element;
		i->liczba=x;
		i->next=elem;
		elem=i;
		rozmiar++;
}

bool Stos::Zdejmij(){
	if(!empty()){
		Element *i=new Element;
		i=elem->next;
		elem=i;
		rozmiar--;
		return true;
	} else {
		return false;
	}
}

void Stos::pop() {
	if(!Zdejmij()) {
		cout<<"Nie mozna wykonac tej sytuacji poniewaz stos jest pusty"<<endl;
	}
}

void Stos::Wypisz() {
	Stos wypis;
	Stos help;
	cout<<"Rozmiar Stosu:"<<rozmiar<<endl;
	cout<<"Elementy Stosu:"<<endl;
	if(!empty()){
			wypis.elem=elem;
			wypis.rozmiar=rozmiar;
		while(!wypis.empty()) {
			cout<<wypis.Elem()->liczba<<' ';
			wypis.pop();
		}
	} else {
		cout<<"Stos jest pusty."<<endl;
	}
}


void Stos::Wypisz_odwrotnie() {
	Stos wypis;
	Stos help;
	cout<<"Rozmiar Stosu:"<<rozmiar<<endl;
	cout<<"Elementy Stosu:"<<endl;
	if(!empty()){
			help.elem=elem;
			help.rozmiar=rozmiar;
		while(!help.empty()){
			wypis.push(help.elem->liczba);
			help.pop();
		}
		while(!wypis.empty()) {
			cout<<wypis.Elem()->liczba<<' ';
			wypis.pop();
		}
	} else {
		cout<<"Stos jest pusty."<<endl;
	}
}
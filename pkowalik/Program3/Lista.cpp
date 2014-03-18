#include"Lista.h"
using namespace std;

Lista::Lista(){
	rozmiar=0;
	elem=new ElementListy;
	last=new ElementListy;
	first=new ElementListy;
}

ElementListy* Lista::Elem(){
	return elem;
}

void Lista::push_el0(int x){
	elem->liczba=x;
	elem->prev=NULL;
	elem->next=NULL;
	first=elem;
	last=elem;
}

void Lista::push_back(int x){
		ElementListy* i= new ElementListy;
		if(!empty()){
			i->liczba=x;
			last->next=i;
			i->next=NULL;
			i->prev=last;
			elem=i;
			last=elem;
		}else {
			push_el0(x);
		}
		rozmiar++;
}

void Lista::push_front(int x){
		ElementListy* i= new ElementListy;
		if(!empty()){
			i->liczba=x;
			first->prev=i;
			i->next=first;
			i->prev=NULL;
			elem=i;
			first=elem;
		}else {
			push_el0(x);
		}
		rozmiar++;
}

bool Lista::Zdejmij_tyl(){
	if(elem->prev!=NULL){
		ElementListy *i=new ElementListy;
		i=elem->prev;
		i->next=NULL;
		elem=i;
		last=elem;
		return true;
	} else {
		return true;
	}
}

bool Lista::Zdejmij_przod(){
	if(elem->next!=NULL){
		ElementListy *i=new ElementListy;
		i=elem->next;
		i->prev=NULL;
		elem=i;
		first=elem;
		return true;
	} else {
		return false;
	}
}

void Lista::pop_back(){
	if(!Zdejmij_tyl()) {
		cout<<"Nie mozna wykonac tej opcji poniewaz lista jest pusta"<<endl;
	} else{
		rozmiar--;
	}
}

void Lista::pop_front(){
	if(!Zdejmij_przod()) {
		cout<<"Nie mozna wykonac tej opcji poniewaz lista jest pusta"<<endl;
	}else{
		rozmiar--;
	}
}

bool Lista::empty(){
	if(elem->prev==NULL && elem->next==NULL && rozmiar==0) {
		return true;
	} else {
		return false;
	}
}

int Lista::size(){
	return rozmiar;
}

void Lista::Wypisz(){
	ElementListy *i;
	i=first;
	cout<<"Rozmiar listy:"<<rozmiar<<endl;
	cout<<"Element:"<<endl;
	do{
		cout<<i->liczba<<' ';
		i=i->next;
	}while(i->next!=NULL);
	cout<<i->liczba<<' ';
}
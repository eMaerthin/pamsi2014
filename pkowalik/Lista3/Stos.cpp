#include"Stos.h"
using namespace std;

Stos::Stos() {
	while(!S.empty()) {
		S.pop();
	}
}

void Stos::push(int x) {
	S.push(x);
}

void Stos::pop(){
	if(!S.empty()){
		S.pop();
	} else {
		cout<<"Na stosie nie ma elementow"<<endl;
	}
}

int Stos::top(){
	return S.top();
}

void Stos::clear(){
	while(!empty()){
		pop();
	}
}

void Stos::Wypisz(){
	stack<int> wypis;
	wypis=S;
	while(!wypis.empty()){
		cout<<wypis.top()<<' ';
		wypis.pop();
	}
	cout<<endl;
}

bool Stos::szukaj(int x){
	stack<int> helping;
	helping=S;
	while(!helping.empty()){
		if(helping.top()==x) {
			return true;
		}
		helping.pop();
	}
	return false;
}

void Stos::Znajdz(int x){
	if(szukaj(x)){
		cout<<"Na Stosie znajduje sie liczba:"<<x<<endl;
	} else {
		cout<<"Na stosie nie ma liczby:"<<x<<endl;
	}
}

bool Stos::empty(){
	return S.empty();
}

int Stos::size(){
	return S.size();
}
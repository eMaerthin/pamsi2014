#include<iostream>
#include"Kolejka.h"
using namespace std;

Kolejka::Kolejka(){
	while(!Q.empty()){
		Q.pop();
	}
}

void Kolejka::push(int x){
	Q.push(x);
}

int Kolejka::pop(){
	int x;
	x=Q.front();
	Q.pop();
	return x;
}

int Kolejka::size(){
	return Q.size();
}

void Kolejka::Wyswietl(){
	queue<int> H;
	H=Q;
	while(!H.empty()){
		cout<<H.front()<<' ';
		H.pop();
	}
}
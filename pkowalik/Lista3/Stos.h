#include<iostream>
#include<stack>
using namespace std;

class Stos {
	stack<int> S;

public:
	Stos();
	void push(int x);
	void pop();
	int top();
	void clear();
	void Wypisz();
	void Znajdz(int x);
	bool szukaj(int x);
	bool empty();
	int size();
};
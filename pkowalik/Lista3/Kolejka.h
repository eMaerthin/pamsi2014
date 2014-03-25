#include<iostream>
#include<queue>
using namespace std;

class Kolejka{
	queue<int> Q;

public:
	Kolejka();
	void push(int x);
	int pop();
	int size();
	void Wyswietl();
};
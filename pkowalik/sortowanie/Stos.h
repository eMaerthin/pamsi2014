#include<iostream>
#include<stack>
using namespace std;

class Stos{
	stack<__int64> S;

public:
	void push(__int64 x);
	void pop();
	__int64 srednia();
	bool empty();
	__int64 top();
	void clear();

};
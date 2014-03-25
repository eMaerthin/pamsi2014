#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<ostream>
using namespace std;

class Kopiec{
	vector<int> K;

public:
	Kopiec();
	void Wypelnij(int koniec);
	void Sortuj(int i);
	void Wyswietl();
	void WypiszKopiec();
	void Usun();
	void pop();
};
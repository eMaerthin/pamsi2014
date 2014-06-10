// DijkstraBellmanFord.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	int wierzcholki = 400;
	int powtorzenia = 50;

	wygeneruj(wierzcholki, powtorzenia);
	przetworzdane();

	system("pause");
	return 0;
}
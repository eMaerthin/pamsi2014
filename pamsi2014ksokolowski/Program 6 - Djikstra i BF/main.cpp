#include <iostream>

#include "Graf.hpp"

using namespace std;

int main()
{
	Graf<int> moj;

	moj.wczytaj_graf_z_pliku("graf10.txt");
	moj.alg_Dijkstry(0);
	cout << endl << endl;
	moj.alg_BF(0);

	system("PAUSE");
	return 0;
}
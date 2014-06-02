#include <iostream>

#include "Siec.hpp"

using namespace std;

//Funkcja wykonujaca eksperyment wyznaczania sredniego czasu dla wykonywania algorymtu E-K dla zadanych sieci
void eksperyment()
{
	Siec<int> testy[5];
	const int l_powtorzen = 10;
	double czas;
	int i, j;

	testy[0].wczytaj_siec("graf1.txt");
	testy[1].wczytaj_siec("graf2.txt");
	testy[2].wczytaj_siec("graf3.txt");
	testy[3].wczytaj_siec("graf4.txt");
	testy[4].wczytaj_siec("graf5.txt");

	for (j = 0; j < 5; ++j){
		czas = 0;
		for (i = 0; i < l_powtorzen; ++i){
			cout << "\t\tObliczam dla j=" << j << " oraz i=" << i << endl;
			testy[j].alg_Edmondsa_Karpa();
			czas += testy[j]._czas();
		}
		cout << "Czas dla j=" << j << " wynosi: " << (czas / l_powtorzen) << endl;
	}
}

int main(void)
{
	eksperyment();


	system("PAUSE");
	return 0;
}
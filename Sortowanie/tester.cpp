#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <cstring>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <boost\timer.hpp>

using namespace std;

template <class T>
class Sortowania
{
private:
	double srednia(double * czasy, int powtorzenia)
	{
		long sum = 0;
		for(int i=0;i<powtorzenia;i++)
			sum += czasy[i];
		return sum/powtorzenia;
	}
	
	T * kopiujTab(T * tab, int rozmiar)
	{
		T * result = new T[rozmiar];
		for(int i=0;i<rozmiar;i++)
			result[i] = tab[i];
		return result;
	}
	
	static void merge(T * tab, T * t, int pocz, int sr, int kon)
	{
		int i, j, q;
		for (i = pocz; i <= kon; i++)
			t[i] = tab[i];  // Skopiowanie danych do tablicy pomocniczej
		i = pocz; j = sr + 1; q=pocz;                 // Ustawienie wskaŸników tablic
		while (i<=sr && j<=kon)
		{         								// Przenoszenie danych z sortowaniem ze zbiorów pomocniczych do tablicy g³ównej
			if (t[i] < t[j])
			   tab[q++] = t[i++];
			else
				tab[q++] = t[j++];
		}
		while (i <= sr) tab[q++] = t[i++]; 			// Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbiór siê skoñczy³
	}
	
public:
	static void SORTUJ_BABELKOWO(T * tab, int rozmiar)
	{
		bool sorted = false;
		for(int j = rozmiar - 1; j > 0; j--)
	    {
		    sorted = true;
		    for(int i = 0; i < j; i++)
		        if(tab[i] > tab[i + 1])
		        {
		          swap(tab[i], tab[i + 1]);
		          sorted = false;
		        }
		    if(sorted) break;
	    }
	}
	
	static void SORTUJ_QUICKSORT(T * tab, int lewy, int prawy)
	{
		int i = lewy;
		int j = prawy;
		int x = tab[(lewy + prawy) / 2];
		do
		{
			while (tab[i] < x)
				i++;

			while (tab[j] > x)
				j--;

			if (i <= j)
			{
				swap(tab[i], tab[j]);

				i++;
				j--;
			}
		} while (i <= j);

		if (lewy < j) SORTUJ_QUICKSORT(tab, lewy, j);

		if (prawy > i) SORTUJ_QUICKSORT(tab, i, prawy);
	}
	
	static void SORTUJ_SCALANIE(T * tab, T * pom, int pocz, int kon)
	{
		int sr;
		if (pocz < kon)
		{
			sr = (pocz + kon) / 2;
			SORTUJ_SCALANIE(tab, pom, pocz, sr);    // Dzielenie lewej czêœci
			SORTUJ_SCALANIE(tab, pom, sr + 1, kon);   // Dzielenie prawej czêœci
			merge(tab, pom, pocz, sr, kon);   // £¹czenie czêœci lewej i prawej
		}		
	}

	double sredniaCzasBabelkowego(T * tab, int rozmiar, int powtorzenia)
	{
		double * czasy = new double[powtorzenia];
		for(int i = 0; i < powtorzenia; i++)
		{
			T * copy = kopiujTab(tab, rozmiar);
			boost::timer t;
			SORTUJ_BABELKOWO(copy, rozmiar);
			czasy[i] = t.elapsed();
		}
		double result = srednia(czasy, powtorzenia);
		delete[] czasy;
		return result;
	}
	
	double sredniaQuicksort(T * tab, int rozmiar, int powtorzenia)
	{
		double * czasy = new double[powtorzenia];
		for(int i = 0; i < powtorzenia; i++)
		{
			T * copy = kopiujTab(tab, rozmiar);
			boost::timer t;
			SORTUJ_QUICKSORT(copy, 0, rozmiar - 1);
			czasy[i] = t.elapsed();
		}
		double result = srednia(czasy, powtorzenia);
		delete[] czasy;
		return result;
	}
	
	double sredniaScalanie(T * tab, int rozmiar, int powtorzenia)
	{
		double * czasy = new double[powtorzenia];
		for(int i = 0; i < powtorzenia; i++)
		{
			T * copy = kopiujTab(tab, rozmiar);
			T * copy2 = kopiujTab(tab, rozmiar);
			boost::timer t;
			SORTUJ_SCALANIE(copy, copy2, 0, rozmiar - 1);
			czasy[i] = t.elapsed();
		}
		double result = srednia(czasy, powtorzenia);
		delete[] czasy;
		return result;
	}

	static bool czyPosortowane(int * tab, int rozmiar)
	{
		for (int i = 0; i < rozmiar - 1; i++)
			if (tab[i] > tab[i + 1])
				return false;
		return true;
	}
};



void wypLos(int *t, int iR)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < iR; i++)
	{
		t[i] = rand() % 100;
	}
}

void wyswietlTab(int * tab, int rozmiar)
{
	for(int i = 0; i < rozmiar; i++)
		cout << tab[i] << " ";
}
BOOST_AUTO_TEST_SUITE(Sortowaniaa)
BOOST_AUTO_TEST_CASE(testBabelkowe)
{
	int * tab = new int[200];
	wypLos(tab, 200);
	Sortowania<int>::SORTUJ_BABELKOWO(tab, 200);
	BOOST_CHECK(Sortowania<int>::czyPosortowane(tab, 200));
	delete []tab;
}
BOOST_AUTO_TEST_CASE(testQuicksort)
{
	int * tab = new int[200];
	wypLos(tab, 200);
	Sortowania<int>::SORTUJ_QUICKSORT(tab, 0, 199);
	BOOST_CHECK(Sortowania<int>::czyPosortowane(tab, 200));
	delete []tab;
}
BOOST_AUTO_TEST_CASE(testScalanie)
{
	int * tab = new int[200];
	int * result = new int[200];
	for (int i = 0; i<200; i++)
		result[i] = tab[i];
	wypLos(tab, 200);
	Sortowania<int>::SORTUJ_SCALANIE(tab, result, 0, 200);
	BOOST_CHECK(Sortowania<int>::czyPosortowane(tab, 200));
	delete []tab;
	delete []result;
}
BOOST_AUTO_TEST_SUITE_END()
/*
int main()
{
	int N = 100;
	int * tab = new int[0];
	int rozmiar = 0;
	int wybor;
	Sortowania<int> * sort = new Sortowania<int>();
	
	do
	{
		
		cout << endl << "MENU" << endl;
		cout << "1. Generuj losowa tablice (int)" << endl;
		cout << "2. Testuj pierwszy algorytm (sortowanie babelkowe)" << endl;
		cout << "3. Testuj drugi algorytm (quicksort)" << endl;
		cout << "4. Testuj trzeci algorytm" << endl;
		cout << "5. Zmien ilosc powtorzen dla sredniego czasu sortowania" << endl;
		cout << "0. Zakoncz" << endl;
		
		cout << "Wybierz opcje: ";
		cin >> wybor;
		switch (wybor)
		{
			case 1:
			{
				cout << "Podaj rozmiar tablicy: ";
				cin >> rozmiar;
				delete[] tab;
				tab = new int[rozmiar];
				wypLos(tab, rozmiar);
				break;
			}
			case 2:
			{
				cout << "Sredni czas sortowania babelkowego dla" << endl;
				cout << "Powtorzenia: " << N << endl;
				cout << "Rozmiar tablicy: " << rozmiar << endl;
				cout << "Sredni czas sortowania: " << sort->sredniaCzasBabelkowego(tab, rozmiar, N);
				break;
			}
			case 3:
			{
				cout << "Sredni czas sortowania quicksort dla" << endl;
				cout << "Powtorzenia: " << N << endl;
				cout << "Rozmiar tablicy: " << rozmiar << endl;
				cout << "Sredni czas sortowania: " << sort->sredniaQuicksort(tab, rozmiar, N);
				break;
			}
			case 4:
			{
				cout << "Sredni czas sortowania przez scalanie dla" << endl;
				cout << "Powtorzenia: " << N << endl;
				cout << "Rozmiar tablicy: " << rozmiar << endl;
				cout << "Sredni czas sortowania: " << sort->sredniaScalanie(tab, rozmiar, N);
				break;
			}
			case 5:
			{
				cout << "Podaj nowa liczbe powtorzen: ";
				cin >> N;
				break;
			}
		}
	} while (wybor != 0);
	delete(sort);
	return 0;
}*/

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <cstring>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <random>
#include <boost\timer.hpp>

using namespace std;

template <class T>
class Sortowania
{
private:
	double srednia(double * czasy, int powtorzenia)
	{
		double sum = 0;
		for (int i = 0; i < powtorzenia; i++)
			sum += czasy[i];
		return sum / powtorzenia;
	}

	void merge(T * tab, T * t, int pocz, int sr, int kon)
	{
		int i, j, q;
		for (i = pocz; i <= kon; i++)
			t[i] = tab[i];								// Skopiowanie danych do tablicy pomocniczej
		i = pocz; j = sr + 1; q = pocz;                 // Ustawienie wskaŸników tablic
		while (i <= sr && j <= kon)
		{         										// Przenoszenie danych z sortowaniem ze zbiorów pomocniczych do tablicy g³ównej
			if (t[i] < t[j])
				tab[q++] = t[i++];
			else
				tab[q++] = t[j++];
		}
		while (i <= sr) tab[q++] = t[i++]; 				// Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbiór siê skoñczy³
	}

public:
	T * kopiujTab(T * tab, int rozmiar)
	{
		T * result = new T[rozmiar];
		for (int i = 0; i < rozmiar; i++)
			result[i] = tab[i];
		return result;
	}
	static void SORTUJ_BABELKOWO(T * tab, int rozmiar)
	{
		bool sorted = false;
		for (int j = rozmiar - 1; j > 0; j--)
		{
			sorted = true;
			for (int i = 0; i < j; i++)
			if (tab[i] > tab[i + 1])
			{
				swap(tab[i], tab[i + 1]);
				sorted = false;
			}
			if (sorted) break;
		}
	}

	void SORTUJ_QUICKSORT(T * tab, int lewy, int prawy)
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

	void SORTUJ_SCALANIE(T * tab, T * pom, int pocz, int kon)
	{
		int sr;
		if (pocz < kon)
		{
			sr = (pocz + kon) / 2;
			SORTUJ_SCALANIE(tab, pom, pocz, sr);      // Dzielenie lewej czêœci
			SORTUJ_SCALANIE(tab, pom, sr + 1, kon);   // Dzielenie prawej czêœci
			merge(tab, pom, pocz, sr, kon);   		  // £¹czenie czêœci lewej i prawej
		}
	}

	double sredniaCzasBabelkowego(T * tab, int rozmiar, int powtorzenia)
	{
		double * czasy = new double[powtorzenia];
		for (int i = 0; i < powtorzenia; i++)
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
		for (int i = 0; i < powtorzenia; i++)
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
		clock_t start, koniec;
		double * czasy = new double[powtorzenia];
		for (int i = 0; i < powtorzenia; i++)
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
};

void losowaTab(int *t, int iR)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < iR; i++)
	{
		t[i] = rand() % 1000000;
	}
}

void jednostajnaTab(int *t, int iR)
{
	srand((unsigned)time(NULL));
	default_random_engine generator;
	uniform_int_distribution<int> dist(0,999999);
	for (int i = 0; i < iR; i++)
	{
		t[i] = dist(generator);
	}
}

void poissonaTab(int *t, int iR)
{
	srand((unsigned)time(NULL));
	default_random_engine generator;
	poisson_distribution<int> dist(1000000);
	for (int i = 0; i < iR; i++)
	{
		t[i] = dist(generator);
	}
}

void porzadkujTab(int *t, int iR, int percent)
{
	int sortLenght = iR * percent / 100;
	//Sortowania<int> sort;
	//sort.SORTUJ_SCALANIE(t, sort.kopiujTab(t, iR), 0, sortLenght);

	for (int i = 0; i < sortLenght; i++)
	{
		t[i] = 0;
	}
}

void wyswietlTab(int * tab, int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
		cout << tab[i] << " ";
}

int main()
{
	int N = 100, rozmiar, rozkladTab, uporzadkowanie;
	char powtorzyc;
	int *tab;
	Sortowania<int> * sort = new Sortowania<int>();

	do
	{
		cout << "Witaj! Ile elementow ma miec tablica?" << endl;
		cin >> rozmiar;
		tab = new int[rozmiar];

		cout << "0 - sortowanie tablicy z rozkladu jednostajnego" << endl;
		cout << "1 - sortowanie tablicy z rozkladu normalnego" << endl;
		cout << "2 - sortowanie tablicy z rozkladu Poissona" << endl;
		cin >> rozkladTab;
		switch (rozkladTab)
		{
			case 0:
			{
					  jednostajnaTab(tab, rozmiar);
					  break;
			}
			case 1:
			{
					  losowaTab(tab, rozmiar);
					  break;
			}
			case 2:
			{
					  poissonaTab(tab, rozmiar);
					  break;
			}
			default:
			{
					   cout << "Wybrano nieprawidlowy rozklad. Uzyto rozkladu normalnego." << endl;
					   losowaTab(tab, rozmiar);
			}
		}

		cout << "0 - sortowanie nieuporzadkowanej tablicy" << endl;
		cout << "1 - sortowanie tablicy z 50% uporzadkowanymi elementami" << endl;
		cout << "2 - sortowanie tablicy z 90% uporzadkowanymi elementami" << endl;
		cout << "3 - sortowanie tablicy z 99% uporzadkowanymi elementami" << endl;
		cin >> uporzadkowanie;
		switch (uporzadkowanie)
		{
			case 0:
			{
					  break;
			}
			case 1:
			{
					  porzadkujTab(tab, rozmiar, 50);
					  break;
			}
			case 2:
			{
					  porzadkujTab(tab, rozmiar, 90);
					  break;
			}
			case 3:
			{
					  porzadkujTab(tab, rozmiar, 99);
					  break;
			}
			default:
			{
					   cout << "Wybrano nieprawidlowe uporzadkowanie elementow. Uzyto nieuporzadkowanej tablicy." << endl;
			}
		}

		cout << "Czekaj..." << endl;
		cout << "Sredni czas pomierzony dla n=" << N << " powtorzen:" << endl;
		cout << "Sortowanie quicksort: " << sort->sredniaQuicksort(tab, rozmiar, N) << endl;
		cout << "Sortowanie przez scalanie: " << sort->sredniaScalanie(tab, rozmiar, N) << endl;
		cout << "Sortowanie babelkowe: " << sort->sredniaCzasBabelkowego(tab, rozmiar, N) << endl;

		cout << "Powtorzyc eksperyment? [t/n]" << endl;
		cin >> powtorzyc;
	} while (powtorzyc == 't');
	system("pause");
	delete(sort);
	return 0;
}

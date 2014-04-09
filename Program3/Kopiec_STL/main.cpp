#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>



using namespace std;

template <class T>
class Kopiec{

    vector<T> tab;

    public:

        void StworzTablice();
        void PrzywrocKopiec();
        void UsunSzczyt();
        void WyswietlKopiec();
        void menu();


        Kopiec(){}
        virtual ~Kopiec(){}
    };


template <class T>
void Kopiec<T>::StworzTablice()
{
    default_random_engine generator;
    uniform_int_distribution<T> distribution(5,2000); //rozklad jednostajny

    int rozmiar;
    cout<<"Podaj liczbe elementow: \n";
    cin>>rozmiar;

    tab.clear();

    for(int i=0; i<rozmiar; i++)
    {
        tab.push_back(distribution(generator));
    }
}

template <class T>
void Kopiec<T>::UsunSzczyt()
{
    pop_heap(tab.begin(), tab.end());
    tab.pop_back();
}

template <class T>
void Kopiec<T>::WyswietlKopiec()
{


	// obliczenie glebokosci drzewa i max szerokosci liczb
	int treeSize = log2(tab.size());
	int minVal = tab[0];
	for (int i = 0; i < tab.size() / 2; ++i)
		if (minVal>tab[tab.size() - 1 - i])
			minVal = tab[tab.size() - 1 - i];
	int printWidth = log10(tab[0]);
	if(printWidth < log10(abs(minVal))+1)
		printWidth = log10(abs(minVal))+1;
	printWidth += 1;

	// zaczynajac od korzenia drzewa
	for (int i = 0; i <= treeSize; ++i)
	{
		int n = pow(2, i); // zmienna opisujaca ile liczb miesci sie na danym poziomie drzewa

		cout.width(printWidth*pow(2, treeSize-i)); // ustawienie szerokosci pierwszego elementu od lewej
		for (int j = 0; j < n; ++j)
		{
			if (n + j - 1 >= tab.size()) // jesli element nie istnieje przerywamy wypisywanie kluczy
				break;
			cout << tab[n + j - 1]; // wypisanie elementu
			cout.width(printWidth * pow(2, treeSize - i + 1)); // i ustawienie innej szerokosci nastepnych elementow
		}
		cout.width(0); // wyzerowanie szerokosci
		cout << endl;
	}
}

template <class T>
void Kopiec<T>::PrzywrocKopiec()
{
    if(is_heap(tab.begin(), tab.end()) == true)
        cout<<"Kopiec jest dobry\n";
    else
        make_heap(tab.begin(), tab.end());
}

template <class T>
void Kopiec<T>::menu()
{
	int opcja;

    do{
		cout << "\n1.Utworz tablice"<<endl;
		cout << "2.Przywroc wlasnosci kopca"<<endl;
        cout << "3.Usun elementu ze szczytu"<<endl;
		cout << "4.Wyswietl kopiec"<<endl;
		cout << "0.Koniec"<<endl;

		cout << "Wybierz opcje\n";
		cin >> opcja;

		switch(opcja)
		{
			case 0: break;
			case 1:
                StworzTablice();
                break;
			case 2:
				PrzywrocKopiec();
				break;
			case 3:
                UsunSzczyt();
                break;
			case 4:
				cout<<"\nZawartosc kopca: "<<endl;
				WyswietlKopiec();
				break;
		}

	}while(opcja !=0);

}

int main()
{

    Kopiec<int> k;

    k.menu();

    return 0;
}


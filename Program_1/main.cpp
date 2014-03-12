#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>

#define ROZMIAR 10

using namespace std;


class Tablica {

	int tablica[ROZMIAR];

public:

	bool operator = (Tablica M);

	int wczytaj_tablice();
	int wczytaj_plik();
	int wczytaj_z_pliku_binarnego();
	int wczytanie_do_pliku_binarnego();
	int wypelnianie_tablicy_losowo();
	int wczytaj_do_pliku();



};



// bool Tablica::operator = ( Tablica T )
// {
//   for ( int i = 0; i<ROZMIAR; i++ )
//   {
//     tablica[i] = T(i+1);
//   }
//   return true;
// }

int Tablica::wczytaj_tablice()
{
	double *t;
	int N, i;
	cout << "podaj wielkosc tablicy ";
	cin >> N;
	t = new double[N];

	for (i = 0; i<N; ++i)
	{
		cout << "podaj " << i + 1 << " liczbe ";
		cin >> t[i];
	}
	cout << "\n\nzawartosc tablicy\n";
	for (i = 0; i<N; ++i) cout << t[i] << " ";
	cout << endl;
	cin.sync();
	cin.get();

	delete[]t;
	return 0;
}

int Tablica::wczytaj_plik()
{
	ifstream ifs("dane.txt");

	if (ifs.is_open()) {
		// print file:
		char c = ifs.get();
		while (ifs.good()) {
			cout << c;
			c = ifs.get();
		}
		cout << endl;
	}
	else {
		cout << "Error opening file";
	}

	return 0;
}

struct File
{
	int number1;
};

int Tablica::wczytaj_z_pliku_binarnego()
{
	ifstream ifs("plik.foo", ios::binary); // otwieramy plik do odczytu binarnego

	char* temp = new char[sizeof(File)]; // tymczasowy bufor na dane
	ifs.read(temp, sizeof(File)); // wczytujemy dane do bufora
	File* file = (File*)(temp); // rzutujemy zawartość bufora na typ File

	cout << file->number1 << " " << endl;
	delete file;
	return 0;
}

int Tablica::wczytanie_do_pliku_binarnego()
{
	ofstream ofs("plik.foo", ios::binary); // otwieramy plik do zapisu binarnego

	File* file = new File;
	cin >> file->number1;
	ofs.write((char*)(file), sizeof(File)); // zapisujemy dane do pliku

	delete file;
	return 0;
}

int Tablica::wypelnianie_tablicy_losowo()
{
	int tablica[10];
	int licznik = 0;
	int licznik_2 = 0;
	srand(time(NULL));
	do
	{
		tablica[licznik] = (4 + rand() % 7);
		cout << tablica[licznik];
		licznik++;
		licznik_2++;
		cout << endl;
	} while (licznik_2<10);
	return EXIT_SUCCESS;
}

int Tablica::wczytaj_do_pliku()
{
	int i, n;
	int tab[ROZMIAR];
	fstream zapisz("plik.txt", ios::out);

	cout << "Ile liczb ma zawierac plik: ";
	cin >> n;
	cout << "Podaj " << n << " liczby: " << endl;
	for (i = 0; i < n; i++)
		cin >> tab[i];
	cout << "Twoje liczby to: " << endl;
	for (i = 0; i < n; i++)
		cout << tab[i] << ", ";

	do {
		n = n - 1;
		for (i = 0; i <= n; i++) {
			i = n;
			zapisz << tab[i] << endl;
			zapisz.flush();
		}
	} while (n > 0);
	cout << endl;
	zapisz.close();
	return EXIT_SUCCESS;
}



int main()
{
  int opcja;
  Tablica T;
  do
    {
      cout << "1.Wczytanie tablicy z konsoli"<<endl;
      cout << "2.Wczytywanie z pliku tekstowego"<<endl;
      cout << "3.Zapisywanie do pliku tekstowego"<<endl;
      cout << "4.Wczytywanie z pliku binarnego"<<endl;
      cout << "5.Zapisywanie do pliku binarnego"<<endl;
      cout << "6.Wypelnianie tablicy"<<endl;
      cout << "0.Koniec"<<endl;
      cout << "Wybierz opcję" << endl;
      cin >> opcja;
      switch(opcja)
	{
	case 0: 
	  break;
	case 1: 
	  T.wczytaj_tablice();
	  break;
	case 2:
	  T.wczytaj_plik();
	  break;
	case 3:
	  T.wczytaj_do_pliku();
	  break;
	case 4:
	  T.wczytaj_z_pliku_binarnego();
 break;
	case 5: 
	  T.wczytanie_do_pliku_binarnego();
break;
	case 6: 
	  T.wypelnianie_tablicy_losowo();
	  break;
	}
    }while(opcja !=0);
}

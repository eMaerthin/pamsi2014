#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
ifstream plik;
ofstream plik2;

/*Definicja klasy tablica. Zostal wykorzystany szablon
	rozmiar-wielkosc tablicy, typ-typ elementow tablicy*/
template <int rozmiar, class typ>
class tablica
{
	public:
	typ tab[rozmiar];
/*Metoda odpowiadajaca za uzupelnianie elementow tablicy poprzez
	wpisywanie ich z konsoli*/
	void wpisz_z_konsoli()
{
     cout<<"Wpisz kolejne elementy tablicy\n";
    for(int i=0; i<rozmiar; i++)
            cin>>tab[i];        
}
/*Metoda odpowiadajaca za wyswietlanie zawartosci tablicy.
	przy wyswietlaniu kolejne elementy oddzielane sa spacjami*/
void wyswietl_zawartosc()
{
    cout<<"Wyswietlanie zawartosci tablicy:\n";
    for(int i=0; i<rozmiar; i++)
            cout<<tab[i]<<" ";
    cout<<endl;
}
/*Metoda odpowiadajaca za wczytywanie zawartosci tablicy z
	istniejacego wczesniej pliku txt*/
void wczytaj_z_pliku_txt()
{
    cout<<"Wczytywanie tablicy z pliku tekstowego\n";
    plik.open("test.txt");
    if(plik.good())
    {
    cout<<"Pomyslnie otworzono plik tekstowy\n";
        for(int i=0; i<rozmiar; i++)
            plik>>tab[i];
        plik.close();
    }
    else
    cout<<"Blad otwierania pliku\n"; 
}
/*Metoda odpowiadajaca za zapisywanie zawartosci tablicy do
	istniejacego wczesniej pliku txt*/
void zapisz_do_pliku_txt()
{
    cout<<"Zapisywanie tablicy do pliku tekstowego\n";
	plik2.open("test.txt");
    if(plik2.good())
    {
    cout<<"Pomyslnie otworzono plik tekstowy\n";
        for(int i=0; i<rozmiar; i++)
           plik2<<tab[i]<<" ";
        plik2.close();
    }
    else
    cout<<"Blad otwierania pliku\n";   
}
/*Metoda odpowiadajaca za uzupelnianie tablicy liczbami pseudolosowymi.
	Parametr ilosc_rand jest to ilosc liczb, ktora zostanie wylosowana
	(zaczynajac od pierwszego elementu o indeksie 0). Jesli przekracza
	on rozmiar tablicy, zostanie wyswietlony komunikat, a sama zawartosc
	nie ulegnie zmianie*/
void wpisz_losowe(int ilosc_rand)
{
    cout<<"Wypelnianie tablicy liczbami losowymi\n";
    if(ilosc_rand>rozmiar)
    cout<<"Wybrana ilosc przekracza rozmiar tablicy\n";
    else
        for(int i=0; i<ilosc_rand; i++)
            tab[i]=rand()%100;

}
/*Metoda odpowiadajaca za tworzenie kopii tablicy. Utworzona kopia jest
	parametrem wyjsciowym metody*/
tablica kopiuj_tablice()
{
     tablica T1;
    for(int i=0; i<rozmiar; i++)
            T1.tab[i]=tab[i];
    return T1;
}
/*Metoda odpowiadajaca za zapisywanie zawartosci tablicy do pliku binarnego*/
void zapisz_do_pliku_bin()
{
   cout<<"Zapisywanie tablicy do pliku binarnego\n";
    ofstream plik("test2.bin", ios::binary);
    if(plik.good())
    {
    cout<<"Pomyslnie otworzono plik binarny\n";
        for(int i=0; i<rozmiar; i++)
        plik.write((char*)&tab[i], sizeof(tab));
        plik.close();
    }
    else
    cout<<"Blad otwierania pliku\n";   
}
/*Metoda odpowiadajaca za wczytywanie zawartosci tablicy z pliku binarnego*/
void wczytaj_z_pliku_bin()
{
    cout<<"Wczytywanie tablicy z pliku binarnego\n";
    ifstream plik2("test2.bin", ios::binary);
    if(plik2.good())
    {
    cout<<"Pomyslnie otworzono plik binarny\n";
        for(int i=0; i<rozmiar; i++)
        plik2.read((char*)&tab[i], sizeof(tab));
        plik2.close();
    }
    else
    cout<<"Blad otwierania pliku\n"; 
}

};


int main()
{
    srand(time(NULL));
    int opcja;
    int rand;
    tablica <20, float> T;   /*definicja nowej tablicy, nalezy wpisac rozmiar oraz typ elementow*/
    

do{
    cout<<"1.Wczytanie tablicy z konsoli\n";
    cout<<"2.Wyswietlenie tablicy\n";
    cout<<"3.Wcztywanie z pliku tekstowego\n";
    cout<<"4.Zapisywanie do pliku tekstowego\n";
    cout<<"5.Wczytywanie z pliku binarnego\n";
    cout<<"6.Zapisywanie do pliku binarnego\n";
    cout<<"7.Wypelnianie tablicy liczbami losowymi\n";
    cout<<"8.Tworzenie dynamicznej kopii + wyswietlanie kopii\n";
    cout<<"0.Koniec\n";
    cout<<"Wybierz opcje\n";
    cin>>opcja;
    cout<<endl;
    
    switch(opcja)
    {
    case 0: break;
    
    case 1:
    T.wpisz_z_konsoli();
    break;
    
    case 2:
    T.wyswietl_zawartosc();
    break;
    
    case 3:
    T.wczytaj_z_pliku_txt();
    break;
    
    case 4:
    T.zapisz_do_pliku_txt();
    break;
    
    case 5:
    T.wczytaj_z_pliku_bin();
    break;
    
    case 6:
    T.zapisz_do_pliku_bin();
    break;
    
    case 7:
    cout<<"Ile liczb ma zostac wybranych losowo?\n";
    cin>>rand;
    T.wpisz_losowe(rand);
    break;    
    
    case 8:
    T.kopiuj_tablice().wyswietl_zawartosc();
    break;
    
    default:
    cout<<"Bledny wybor\n";
    break;
    }          
}while(opcja!=0);

}

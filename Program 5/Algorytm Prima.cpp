/*Program wczytujacy graf z pliku tekstowego, a nastepnie zapisujacy go w postaci listy oraz macierzy do plikow tekstowych*/

#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;
ifstream plik;
ofstream plik2;
const int rozmiar=10; //Rozmiar grafu - ilosc wierzcholkow
const int inf=10000000;
//Struktura polaczenie konieczna do zdefiniowania postaci listowej grafu.
struct polaczenie
{
       int wierzcholek; // wierzcholek z ktorym jest polaczenie o nastepujacej wadze:
       int waga;
       friend ostream & operator <<(ostream &wyjscie, polaczenie p);
};

ostream & operator <<(ostream &wyjscie,const polaczenie p)
{
        return wyjscie<<"->"<<p.wierzcholek<<"("<<p.waga<<")";
}

struct luk
{
	int poczatek, koniec, waga;	
};


struct graf
{
	    list<luk> MDR; //minimalne drzewo rozpinajace w postaci listy
       int macierz[rozmiar][rozmiar];
       list<polaczenie> lista[rozmiar];
       graf()
       {
                   for(int i=0; i<rozmiar; i++)
                           for(int j=0; j<rozmiar; j++)
                                   macierz[i][j]=-1;      
       }
       
        void wczytaj_z_pliku()
       {
            cout<<"Wczytywanie danych z pliku tekstowego\n";
            plik.open("nazwa2.txt");   // nazwa pliku zawierajacego dane wejsciowe
            if(plik.good())
            {
                           cout<<"Plik zostal otwarty pomyslnie\n";
                           while(!plik.eof())
                           {
                           int i,j,w;
                           plik>>i;
                           plik>>j;
                           plik>>w;
                           polaczenie tmp;
                           tmp.wierzcholek=j;
                           tmp.waga=w;
                           lista[i].push_back(tmp);
                           tmp.wierzcholek=i;
                           lista[j].push_back(tmp);
                           macierz[i][j]=w;
                           macierz[j][i]=w;
                           }
            }
            else
            cout<<"Nie udalo sie otworzyc pliku\n";
       }
       
       
       
       void zapisz_macierz()
       {
            cout<<"Zapisywanie tablicy do pliku tekstowego\n";
            plik2.open("macierz.txt");
            if(plik2.good())
            {
                            cout<<"Plik do zapisu zostal otworzony pomyslnie\n";
                             for (int i=0; i<rozmiar; i++)
                             {
                                           for(int j=0; j<rozmiar; j++)
                                           {
                                           plik2<<macierz[i][j]<<" ";
                                           cout<<macierz[i][j]<<" ";
                                           }
                                           plik2<<"\n";
                                           cout<<"\n";
                             }
                             plik2.close();
            }
            else
            {
                cout<<"Nie udalo sie zapisac do pliku\n";
            }
       }
       
       
       void zapisz_liste()
       {
            cout<<"Zapisywanie listy do pliku tekstowego\n";
            plik2.open("lista.txt");
            if(plik2.good())
            {
                            cout<<"Plik do zapisu zostal otworzony pomyslnie\n";
                            for(int i=0; i<rozmiar; i++)
                            {
                              plik2<<i;
                              cout<<i;
                              while(!lista[i].empty())
                              {
                                            plik2<<lista[i].front();
                                            cout<<lista[i].front();
                                            lista[i].pop_front();
                              }
                              plik2<<"\n";
                              cout<<"\n";
                            }
            plik2.close();
            }
       }
       


void sortuj_tablice_lukow(luk* tab, int rozmiar)
{
	int  i = 0;
  do
  {
    if(tab[i].waga > tab[i+1].waga) // Porz¹dek rosn¹cy
    {
      swap(tab[i], tab[i+1]);
      i = 0;
      continue;
    }
    i++;
  } while(i < rozmiar-1);
}

/*Metoda sprawdzajaca czy wszystkie wierzcholki grafu znajduja sie w minimalnym drzewie rozpinajacym*/
bool czy_drzewo_zawiera_wszystkie_wierzcholki(bool* tab)
{
	int ilosc=0;
	for(int i=0; i<rozmiar; i++)
	if(tab[i]==true)
	ilosc++;
	
	if(ilosc==rozmiar)
	return true;
	else
	return false;
}

       
       
void algorytm_prima()
{

    luk tablica_lukow[30000],tmp; 
    int wielkosc_tablicy_lukow=0;
    bool czy_nalezy_do_drzewa[rozmiar];
    
	for(int i=0; i<rozmiar; i++)
    czy_nalezy_do_drzewa[i]=false;  //na poczatku wszystkie wierzcholki nie naleza do drzewa
       	
	int  i, wierzcholek=0;  //wierzcholek-wierzcholek startowy, na poczatku 0, ktore nalezy dodac MDR (linijka ponizej)
    czy_nalezy_do_drzewa[0]=true;
       	
	do //glowna petla programu wykonywana tak dlugo, az wszystkie wierzcholki znajda sie w MDR
	{
       	for( i=0; i<rozmiar; i++) //petla zapisujaca do tablicy luki, pod warunkiem ze istnieje polaczenie miedzy wierzcholkami, oraz wierzcholek koncowy
       	{							//nie nalezy jeszcze do MDR
       		if(macierz[wierzcholek][i]!=-1&&czy_nalezy_do_drzewa[i]==false)
       		{
       			tmp.poczatek=wierzcholek;
       			tmp.koniec=i;
       			tmp.waga=macierz[wierzcholek][i];
       			tablica_lukow[wielkosc_tablicy_lukow]=tmp;
       			wielkosc_tablicy_lukow++;
       		}
       	}
       		sortuj_tablice_lukow(tablica_lukow,wielkosc_tablicy_lukow); //sortowanie otrzymanej tablicy lukow
       	//	cout<<"posortowane";
       		if(czy_nalezy_do_drzewa[tablica_lukow[0].koniec]==false) //jesli koniec pierwszego luku w posortowanej tablicy(a wiec o najmnieszej wadze) nie jest jeszcze w MDR luk ten trafia do MDR
       		MDR.push_front(tablica_lukow[0]);
       		
       		czy_nalezy_do_drzewa[tablica_lukow[0].koniec]=true;
       		czy_nalezy_do_drzewa[tablica_lukow[0].poczatek]=true;
       		wierzcholek=tablica_lukow[0].koniec;  //wierzcholek jest oznaczony jako koniec dodanego do MDR luku, a wiec teraz w petli beda szukane polaczenia z tym koncem
       		tablica_lukow[0]=tablica_lukow[wielkosc_tablicy_lukow-1]; //pierwszy element tablicy musi zostac z niej usuniety. najpierw przypisana mu jest wartosc ostatniego elementu;
       		wielkosc_tablicy_lukow--;	//a nastepnie rozmiar tablicy zostaje zmniejszony, w wyniku czego ostatni element "znika"
       		sortuj_tablice_lukow(tablica_lukow,wielkosc_tablicy_lukow); //sortowanie tablicy koniecznie ze wzgledu na trafienie na 1 miejsce tablicy luku o najwiekszej wadze(ostatniego)
    }while(!czy_drzewo_zawiera_wszystkie_wierzcholki(czy_nalezy_do_drzewa));
    int waga=0;
       	
       /*Wyswietlanie MDR w czytelnej formie*/	
    do 
    {
       	cout<<MDR.front().poczatek<<" "<<MDR.front().koniec<<" "<<MDR.front().waga<<"\n";
       	waga+=MDR.front().waga;
       	MDR.pop_front();
    }
    while(!MDR.empty());
    cout<<"Waga: "<<waga<<"\n";
}
       
       
       

       
};





int main()
{
    int i;
    graf G;
    cout<<"Utworzony zostal nowy graf\n";
    G.wczytaj_z_pliku();
    cout<<"MDR znalezione za pomoca algorytmu Prima:\n";
    G.algorytm_prima();

    cin>>i;
}


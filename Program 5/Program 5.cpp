/*Program wczytujacy graf z pliku tekstowego, a nastepnie zapisujacy go w postaci listy oraz macierzy do plikow tekstowych*/

#include <iostream>
#include <list>
#include <fstream>
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
       
/*Metoda odpowiadajaca za sortowanie tablicy lukow w kolejnosci rosnacej w zaleznosci od wag*/


void sortuj_tablice_lukow(luk* tab, int rozmiar)
{
	int i,j;
	luk tmp;
	for(i=1; i<rozmiar; i++)
	{
		tmp=tab[i];
		for(j=i-1;j>=0&&tab[j].waga>tmp.waga; j--)
		{
			tab[j+1]=tab[j];
		}
		tab[j+1]=tmp;
	}
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
    list<luk> MDR; //minimalne drzewo rozpinajace w postaci listy
    luk tablica_lukow[10000],tmp; 
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
       		
       		if(czy_nalezy_do_drzewa[tablica_lukow[0].koniec]==false) //jesli koniec pierwszego luku w posortowanej tablicy(a wiec o najmnieszej wadze) nie jest jeszcze w MDR luk ten trafia do MDR
       		MDR.push_front(tablica_lukow[0]);
       		
       		czy_nalezy_do_drzewa[tablica_lukow[0].koniec]=true;
       		czy_nalezy_do_drzewa[tablica_lukow[0].poczatek]=true;
       		wierzcholek=tablica_lukow[0].koniec;  //wierzcholek jest oznaczony jako koniec dodanego do MDR luku, a wiec teraz w petli beda szukane polaczenia z tym koncem
       		tablica_lukow[0]=tablica_lukow[wielkosc_tablicy_lukow-1]; //pierwszy element tablicy musi zostac z niej usuniety. najpierw przypisana mu jest wartosc ostatniego elementu;
       		wielkosc_tablicy_lukow--;	//a nastepnie rozmiar tablicy zostaje zmniejszony, w wyniku czego ostatni element "znika"
       		sortuj_tablice_lukow(tablica_lukow,wielkosc_tablicy_lukow); //sortowanie tablicy koniecznie ze wzgledu na trafienie na 1 miejsce tablicy luku o najwiekszej wadze(ostatniego)
    }while(!czy_drzewo_zawiera_wszystkie_wierzcholki(czy_nalezy_do_drzewa));
       	
       	
       /*Wyswietlanie MDR w czytelnej formie*/	
    do 
    {
       	cout<<MDR.front().poczatek<<" "<<MDR.front().koniec<<" "<<MDR.front().waga<<"\n";
       	MDR.pop_front();
    }
    while(!MDR.empty());
}
       
       
       
       
       
       
       
       void algorytm_kruskala()
       {
       	list<luk> MDR;
    	luk tablica_lukow[10000],tablica_lukow2[10000],tmp;
    	int wielkosc_tablicy_lukow=0;
    	bool czy_nalezy_do_drzewa[rozmiar];
    		
	    for(int i=0; i<rozmiar; i++)
    	czy_nalezy_do_drzewa[i]=false;
    	//w ponizszej petlii for macierz jest odczytywana, a kolejne istniejace polaczenia trafiaja do tablicy lukow
    	for(int i=0;i<rozmiar; i++)
    		for(int j=0; j<rozmiar; j++)
    			if(macierz[i][j]!=-1)
    			{
    			tmp.poczatek=i;
       			tmp.koniec=j;
       			tmp.waga=macierz[i][j];
       			tablica_lukow[wielkosc_tablicy_lukow]=tmp;
       			wielkosc_tablicy_lukow++;
    			}
    	sortuj_tablice_lukow(tablica_lukow,wielkosc_tablicy_lukow);
    	
    	
    	
    	//ponizsze instrukcje odpowiadaja za usuniecie duplikatow polaczen uzyskanych w procesie szukania istniejacych polaczen (jesli a laczy sie z b, to b laczy sie z a, co daje nam 2 tozsame polaczenia)
    	for(int i=0; i<wielkosc_tablicy_lukow; i++)
    		tablica_lukow2[i]=tablica_lukow[2*i];	
    	wielkosc_tablicy_lukow/=2;
    		
    	/*Glowna petla algorytmu dzialajaca tak dlugo, az w MDR nie znajda sie wszystkie istniejace wierzcholki*/	
    	do
    	{
    		for(int i=0;i<wielkosc_tablicy_lukow;i++)
    		{
    			//jesli koniec lub poczatek rozpatrywanego luku nie znajduje sie jeszcze w MDR, to luk trafia do MDR
    			if(czy_nalezy_do_drzewa[tablica_lukow2[i].koniec]==false||czy_nalezy_do_drzewa[tablica_lukow2[i].poczatek]==false) 
    			{
    			MDR.push_front(tablica_lukow2[i]);
    			czy_nalezy_do_drzewa[tablica_lukow2[i].koniec]=true;
    			czy_nalezy_do_drzewa[tablica_lukow2[i].poczatek]=true;
    
    			}
			} 
    	}while(!czy_drzewo_zawiera_wszystkie_wierzcholki(czy_nalezy_do_drzewa));
    	
    	    do
   		 	{
   	    		cout<<MDR.front().poczatek<<" "<<MDR.front().koniec<<" "<<MDR.front().waga<<"\n";
       			MDR.pop_front();
    		}
    	while(!MDR.empty());
       }
       
};





int main()
{
    int i;
    graf G;
    cout<<"Utworzony zostal nowy graf\n";
    G.wczytaj_z_pliku();
    cout<<"Graf w postaci macierzy wczytany z pliku:\n";
    G.zapisz_macierz();
    cout<<"Graf w postaci listy (w nawiasach zamieszczone sa wagi):\n";
    G.zapisz_liste();
    cout<<"MDR znalezione za pomoca algorytmu Prima:\n";
    G.algorytm_prima();
    cout<<"MDR znalezione za pomoca algorytmu Kruskala:\n";
    G.algorytm_kruskala();
}


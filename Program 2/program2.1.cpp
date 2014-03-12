/*Program realizujacy liste jednokierunkowa*/


#include <iostream>



using namespace std;
/*Struktura modelujaca elementy listy. Zawiera ona wartosc elementu oraz wskaznik na nastepny element na liscie.
            Przy tworzeniu elementu wskaznik wskazuje na 0, co oznacza, ze kolejnego elementu nie ma*/
template <class typ>
struct element
{
       public:
       typ wartosc;
       element *nastepny;
       element()
       {
                nastepny=0;
       }
       
       
};
/*Struktura modelujaca stos elementow. Zawiera ona zmienna odpowiadajaca za rozmiar, czyli ilosc elementow na stosie,
            oraz wskaznik na pierwszy (poczatkowy) element stosu. Przy utworzeniu listy wskaznik wskazuje na 0, co oznacza,
            ze pierwszego elementu nie ma, a zmienna rozmiar przyjmuje wartosc 0*/
template <class typ>
struct stos
{
       int rozmiar;
       element<typ> *poczatek;
       stos()
       {
              rozmiar=0;
              poczatek=0;
       }
/*Metoda odpowiadajaca za dodanie na stos nowego elementu o wartosci przekazanej przez parametr wejsciowy
         oraz zwiekszenie licznika elementow. Jezeli lista jest pusta (to znaczy, ze wskaznik "poczatek" wskazuje na 0)
         nowododany element zostaje wskazany jako poczatkowy. Jesli jest to kolejny element stosu, to najpierw wskaznik przesuwamy
         na koniec listy, a nastepnie wskaznikiem ostatniego elementu (ktory z zalozenia wskazuje na element nastepny) wskazujemy na
         nowy, dodawany element.*/
         
       void dodaj_element(typ I)
       {
            rozmiar++;
            element<typ> *nowy = new element<typ>;
            nowy->wartosc=I;
            if(poczatek==0)
                    poczatek=nowy;
            else
            {
                    element<typ> *tmp=poczatek;
                    while(tmp->nastepny)
                                        tmp=tmp->nastepny;
                    tmp->nastepny=nowy;
                    nowy->nastepny=0;
            }
       }
/*Metoda odpowiadajaca za usuniecie ze stosu ostatnio dodanego elementu. Najpierw sprawdza ona, czy lista nie jest pusta,
         to znaczy czy wskaznik "poczatek" nie wskazuje na 0. Jesli tak sie stanie, wyswietlony zostanie komunikat o bledzie.
         Jezeli lista nie jest pusta, to przesuwamy sie na przedostatni element listy, a nastepnie jego wskaznik wskazujemy na 0,
         czyniac jednoczesnie element przedostatni elementem ostatnim. Jezeli na stosie jest tylko jeden element, czyli
         nie mozna zdefiniowac elementu "przedostatniego", to wtedy wskaznik "poczatek" ustawiamy na 0, co oznacza, ze lista jest pusta*/       
       
       void usun_element()
       {
            if(poczatek==0)
            cout<<"Nie mozna usunac elementu z pustej listy\n";
            else
            {

                rozmiar--;
                element<typ> *tmp=poczatek;
                if(tmp->nastepny==0)
                                   poczatek=0;
                else
                {
                while(tmp->nastepny->nastepny)
                tmp=tmp->nastepny;
                tmp->nastepny=0;
                }
            }
       }
/*Metoda odpowiadajaca za wyswietlenie aktualnej zawartosci listy. Wyswietlane zostaja kolejne elementy oddzielone od siebie spacja oraz rozmiar listy,
         czyli ilosc elementow
		 
		 
~~~~~~~~~~~~~Problemem tej metody jest niewlasciowa kolejnosc wyswietlania elementow. Pierwszym wyswietlonym elementem, zgodnie z wymogami zadania,
		powinien byc element ostatni umieszczony na stosie. Stos zdefiniowany w tym zadaniu posiada wskaznik na pierwszy element, a kazdy z elementow
		posiada wskaznik na element nastepny. Taka sytuacja wymusza "przechodzenie" pomiedzy kolejnymi elementami od pierwszego, do ostatniego.
		Jedyna mozliwoscia rozwiazania tego problemu, jaka udalo mi sie wymyslic, jest dodanie do elementu stosu wskaznika do elementu poprzedniego.
		Rozwiazanie to wydaje sie jednak sprzeczne z tematem zadania - lista jednokierunkowa*/       
       void wyswietl_liste()
       {
            element<typ> *tmp=poczatek;
            while(tmp)
            {
                      cout<<tmp->wartosc<<" ";
                      tmp=tmp->nastepny;
            }
            cout<<"\nIlosc elementow na liscie: "<<rozmiar<<"\n";
       }
       
};




int main()
{
    int wybor;
/*Zmienna wartosc odpowiadajaca za okreslanie wartosci elementu wpisywanego na stos.
          Jej typ musi byc taki sam jak typ elementow na stosie:
              typ wartosc;
              stos<typ> S;*/
    float wartosc;
    stos<float> S;
    do
    {
    cout<<"1. Dodaj nowy element\n2. Usun element\n3. Wyswietl liste\n0. Zakoncz dzialanie programu\n";
    cin>>wybor;
    switch(wybor)
    {
    case 0:
         break;
    case 1:
         cout<<"Wpisz wartosc:\n";
         cin>>wartosc;
         S.dodaj_element(wartosc);
         break;
    case 2:
         cout<<"Usuwanie elementu\n";
         S.usun_element();
         break;
    case 3:
         cout<<"Aktualna lista:\n";
         S.wyswietl_liste();
         break;
    default:
         cout<<"Bledny wybor, sprobuj jeszcze raz\n";
    }
    }
    while(wybor!=0);
    
}


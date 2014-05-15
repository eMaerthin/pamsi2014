#include <iostream>
using namespace std;

// ******************************************************************************************************/
//                                       Lista jednokierunkowa                                           /
// ******************************************************************************************************/
struct element_listy_jedn{
    element_listy_jedn* nastepny;
    int zawartosc;
};

class lista_jednokierunkowa{
private:
    element_listy_jedn* tyl;  // adres poprzedniego elementu
    element_listy_jedn* przod;    // adres nastepnego elementu
    unsigned licznik_jedn;       // licznik_jedn elementow
    int wartosc;

public:
// konstruktor
    lista_jednokierunkowa(){
    tyl = NULL; // zerujemy adres poprzedniego
    przod = NULL;    // zerujemy adres nastepnego
    licznik_jedn = 0;    // zerujemy liczbe elementow
    }

// destruktor - kasuje wszystkie elementy listy
~lista_jednokierunkowa(){

    element_listy_jedn* adres_roboczy;
    while(przod)
        {
        adres_roboczy = przod->nastepny;
        delete przod;
        przod = adres_roboczy;
        }
    }

// deklaracje metod
    unsigned zwroc_wielkosc_jedn();
    element_listy_jedn* wpisz_przod_jedn();
    element_listy_jedn* wpisz_tyl_jedn();
    element_listy_jedn* usun_przod_jedn();
    element_listy_jedn* usun_tyl_jedn();
    void wyswietl_wielkosc_jedn();
    void wyswietl_liste_jedn();
};


// ******************************************************************************************************/
//                                    Zwracanie wielkoœci listy                                          /
// ******************************************************************************************************/
unsigned lista_jednokierunkowa::zwroc_wielkosc_jedn(){
    return licznik_jedn;
}
// ******************************************************************************************************/
//                                  Dodawanie elementu na poczatku                                       /
// ******************************************************************************************************/
element_listy_jedn* lista_jednokierunkowa::wpisz_przod_jedn()
    {

        cout << "Podaj wartosc    " << endl;
        cin >> wartosc;
        element_listy_jedn* roboczy = new element_listy_jedn;
        roboczy->zawartosc = wartosc;
        roboczy->nastepny = przod;
        przod = roboczy;
        if(!tyl) tyl = przod;
        licznik_jedn++;
        return przod;
    }
// ******************************************************************************************************/
//                              Dodawanie elementu na koncu                                              /
// ******************************************************************************************************/
element_listy_jedn* lista_jednokierunkowa::wpisz_tyl_jedn()
    {
        cout << "Podaj wartosc    " << endl;
        cin >> wartosc;
        element_listy_jedn* roboczy = new element_listy_jedn;
        roboczy->zawartosc = wartosc;

        if(tyl) tyl->nastepny = roboczy;
        roboczy->nastepny = NULL;
        tyl = roboczy;
        if(!przod) przod = tyl;
        licznik_jedn++;
        return tyl;
    }
// ******************************************************************************************************/
//                              Usuwanie elementu na poczatku                                            /
// ******************************************************************************************************/
element_listy_jedn* lista_jednokierunkowa::usun_przod_jedn()
    {
      element_listy_jedn* roboczy;

      if(przod)
      {
        roboczy = przod;
        przod = przod->nastepny;
        if(!przod) tyl = NULL;
        licznik_jedn--;
        return roboczy;
      }
      else return NULL;
    }
// ******************************************************************************************************/
//                              Usuwanie elementu na koncu                                               /
// ******************************************************************************************************/
element_listy_jedn* lista_jednokierunkowa::usun_tyl_jedn()
    {
      element_listy_jedn* roboczy;

      if(tyl)
      {
        roboczy = tyl;
        if(roboczy == przod) przod = tyl = NULL;
        else
        {
          tyl = przod;
          while(tyl->nastepny != roboczy) tyl = tyl->nastepny;
          tyl->nastepny = NULL;
        }
        licznik_jedn--;
        return roboczy;
      }
      else return NULL;
    }
// ******************************************************************************************************/
//                              Wyswietlanie wielkoscji listy                                            /
// ******************************************************************************************************/
void lista_jednokierunkowa::wyswietl_wielkosc_jedn(){
    cout << "Aktualna wielkosc tablicy to  " << licznik_jedn << endl;
}
// ******************************************************************************************************/
//                              Wyswietlanie elementow listy                                             /
// ******************************************************************************************************/
void lista_jednokierunkowa::wyswietl_liste_jedn()
    {
      element_listy_jedn* roboczy;

      if(!przod) cout << "Lista jest pusta." << endl;
      else
      {
        cout << endl << "Kolejne elementy listy to  ";
        roboczy = przod;
        while(roboczy)
        {
          cout << roboczy->zawartosc << " ";
          roboczy = roboczy->nastepny;
        }
        cout << endl;
      }
    }

// ******************************************************************************************************/
//                                       Lista dwukierunkowa                                             /
// ******************************************************************************************************/
struct element_listy_dwu
{
    element_listy_dwu* nastepny;
    element_listy_dwu* poprzedni;
    int zawartosc;
};

class lista_dwukierunkowa
{
private:
    element_listy_dwu* przod;
    element_listy_dwu* tyl;
    unsigned licznik_dwu;
    int wartosc;
public:
// konstruktor
lista_dwukierunkowa()
    {
    przod = NULL;
    tyl = NULL;
    licznik_dwu  = 0;
    }
// destruktor
~lista_dwukierunkowa()
{
    element_listy_dwu * roboczy;
    while(przod)
    {
        roboczy = przod->nastepny;
        delete przod;
        przod = roboczy;
    }
}
// deklaracje metod
    unsigned zwroc_wielkosc_dwu();
    element_listy_dwu* wpisz_przod_dwu();
    element_listy_dwu* wpisz_tyl_dwu();
    element_listy_dwu* usun_przod_dwu();
    element_listy_dwu* usun_tyl_dwu();
    void wyswietl_liste_dwu();
    void wyswietl_wielkosc_dwu();
};
// ******************************************************************************************************/
//                                    Zwracanie wielkoœci listy                                          /
// ******************************************************************************************************/
unsigned lista_dwukierunkowa::zwroc_wielkosc_dwu(){
return licznik_dwu;
}
// ******************************************************************************************************/
//                                Dodawanie elementu na poczatku                                         /
// ******************************************************************************************************/
element_listy_dwu* lista_dwukierunkowa::wpisz_przod_dwu()
{
        cout << "Podaj wartosc    " << endl;
        cin >> wartosc;
        element_listy_dwu* roboczy = new element_listy_dwu;
        roboczy->zawartosc = wartosc;

roboczy->nastepny = przod;
roboczy->poprzedni = NULL;
if(przod) przod->poprzedni = roboczy;
przod = roboczy;
if(!tyl) tyl = przod;
licznik_dwu++;
return przod;
}
// ******************************************************************************************************/
//                              Dodawanie elementu na koncu                                              /
// ******************************************************************************************************/
element_listy_dwu* lista_dwukierunkowa::wpisz_tyl_dwu()
{
        cout << "Podaj wartosc    " << endl;
        cin >> wartosc;
        element_listy_dwu* roboczy = new element_listy_dwu;
        roboczy->zawartosc = wartosc;

        if(tyl) tyl->nastepny = roboczy;
        roboczy->nastepny = NULL;
        roboczy->poprzedni = tyl;
        tyl = roboczy;
        if(!przod) przod = tyl;
        licznik_dwu++;
        return tyl;
}
// ******************************************************************************************************/
//                              Usuwanie elementu na poczatku                                            /
// ******************************************************************************************************/
element_listy_dwu* lista_dwukierunkowa::usun_przod_dwu()
{
element_listy_dwu * roboczy;
if(przod)
    {
    roboczy = przod;
    przod = przod->nastepny;
    if(!przod) tyl = NULL;
    else przod->poprzedni = NULL;
    licznik_dwu--;
    return roboczy;
    }
else return NULL;
}
// ******************************************************************************************************/
//                              Usuwanie elementu na koncu                                               /
// ******************************************************************************************************/
element_listy_dwu* lista_dwukierunkowa::usun_tyl_dwu()
{
element_listy_dwu* roboczy;
if(tyl)
    {
    roboczy = tyl;
    if(roboczy == przod) przod = tyl = NULL;
    else
        {
        tyl = tyl->poprzedni;
        tyl->nastepny = NULL;
        };
    licznik_dwu--;
    return roboczy;
    }
else return NULL;
}
// ******************************************************************************************************/
//                              Wyswietlanie elementow listy                                             /
// ******************************************************************************************************/
void lista_dwukierunkowa::wyswietl_liste_dwu()
{
element_listy_dwu * roboczy;

if(!przod) cout << "Lista jest pusta." << endl;
else
    {
    roboczy = przod;
    while(roboczy)
        {
        cout << roboczy->zawartosc << " ";
        roboczy = roboczy->nastepny;
        }
    cout << endl;
    }
}
// ******************************************************************************************************/
//                              Wyswietlanie wielkosci listy                                             /
// ******************************************************************************************************/
void lista_dwukierunkowa::wyswietl_wielkosc_dwu(){
    cout << "Aktualna wielkosc tablicy to  " << licznik_dwu << endl;
}

int main(){



cout << "Tworze obiekt listy jednokierunkowej " << endl;
lista_jednokierunkowa Lista_jedn;
cout << "Stworzylem!" << endl;
cout << "Tworze obiekt listy dwukierunkowej " << endl;
lista_dwukierunkowa Lista_dwu;
cout << "Stworzylem!" << endl;

int wybor = 0;
do{
bool poprawny_wybor = false;
cout << endl << endl;
cout << "Witaj w programie, wybierz wartosc od 1 do 15 i zatwierdz klawiszem enter " << endl << endl;
cout << "                    LISTA JEDNOKIERUNKOWA                    " << endl;
// ******************************************************************************************************/
//                                       Lista jednokierunkowa                                           /
// ******************************************************************************************************/
cout << "1 - Dodaj element do listy jednokierunkowej z tylu" << endl;
cout << "2 - Dodaj element do listy jednokierunkowej z przodu" << endl;
cout << "3 - Wyswietl liczbe elementow listy jednokierunkowej" << endl;
cout << "4 - Wyswietl elementy listy jednokierunkowej" << endl;
cout << "5 - Wyczysc liste jednokierunkowa" << endl;
cout << "6 - Usun element z listy jednokierunkowej z tylu" << endl;
cout << "7 - Usun element z listy jednokierunkowej z przodu" << endl << endl;
// ******************************************************************************************************/
//                                       Lista dwukierunkowa                                             /
// ******************************************************************************************************/
cout << "                    LISTA DWUKIERUNKOWA                    " << endl;
cout << "8 - Dodaj element do listy dwukierunkowej z tylu" << endl;
cout << "9 - Dodaj element do listy dwukierunkowej z przodu" << endl;
cout << "10 - Wyswietl liczbe elementow listy dwukierunkowej" << endl;
cout << "11 - Wyswietl elementy listy dwukierunkowej" << endl;
cout << "12 - Wyczysc liste dwukierunkowa" << endl;
cout << "13 - Usun element do listy dwukierunkowej z tylu" << endl;
cout << "14 - Usun element do listy dwukierunkowej z przodu" << endl << endl;
cout << "15 - Wyjscie z programu" << endl;
while(poprawny_wybor != true){
	cin >> wybor;
    cout << endl << endl << endl;
	if((wybor >0)&&(wybor <16))
        {
        poprawny_wybor = true;
        }
	else
        {
        cout << "Niepoprawna wartosc - wprowadz jeszcze raz !" << endl;
        }
    }
switch(wybor){
// ******************************************************************************************************/
//                                       Lista jednokierunkowa                                           /
// ******************************************************************************************************/
// "1 - Dodaj element do listy jednokierunkowej z tylu"
case 1:
Lista_jedn.wpisz_tyl_jedn();
break;
// "2 - Dodaj element do listy jednokierunkowej z przodu"
case 2:
Lista_jedn.wpisz_przod_jedn();
break;
// "3 - Wyswietl liczbe elementow listy jednokierunkowej"
case 3:
Lista_jedn.wyswietl_wielkosc_jedn();
break;
// "4 - Wyswietl elementy listy jednokierunkowej"
case 4:
Lista_jedn.wyswietl_liste_jedn();
break;
// "5 - Wyczysc liste jednokierunkowa"
case 5:
while(Lista_jedn.zwroc_wielkosc_jedn()){Lista_jedn.usun_przod_jedn();
  cout << "Aktualne elementy listy to   ";
  Lista_jedn.wyswietl_liste_jedn();
}
break;
// "6 - Usun element z listy jednokierunkowej z tylu"
case 6:
Lista_jedn.usun_tyl_jedn();
break;
// "7 - Usun element z listy jednokierunkowej z przodu"
case 7:
Lista_jedn.usun_przod_jedn();
break;
// ******************************************************************************************************/
//                                       Lista dwukierunkowa                                             /
// ******************************************************************************************************/
// "8 - Dodaj element do listy dwukierunkowej z tylu"
case 8:
Lista_dwu.wpisz_tyl_dwu();
break;
// "9 - Dodaj element do listy dwukierunkowej z przodu"
case 9:
Lista_dwu.wpisz_przod_dwu();
break;
// "10 - Wyswietl liczbe elementow listy dwukierunkowej"
case 10:
Lista_dwu.wyswietl_wielkosc_dwu();
break;
// "11 - Wyswietl elementy listy dwukierunkowej"
case 11:
Lista_dwu.wyswietl_liste_dwu();
break;
// "12 - Wyczysc liste dwukierunkowa"
case 12:
while(Lista_dwu.zwroc_wielkosc_dwu()){Lista_dwu.usun_przod_dwu();
cout << "Aktualne elementy listy to   ";
Lista_dwu.wyswietl_liste_dwu();
}
break;
// "13 - Usun element do listy dwukierunkowej z tylu"
case 13:
Lista_dwu.usun_tyl_dwu();
break;
// "14 - Usun element do listy dwukierunkowej z przodu"
case 14:
Lista_dwu.usun_przod_dwu();
break;
// "15 - Wyjscie z programu"
case 15:
cout << "Dziekuje za skorzystanie z programu" << endl;
break;
}
}while(wybor!=15);

}

#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
const int n = 50;
using namespace std;

struct Zbior_Liczb
{
  Zbior_Liczb * next, * prev;
  //int key; // dla liczb
  string key; //dla wyrazow lecz wtedy zabezpieczenie przed zlym znakiem (przypadek dla liczb-blokuje wprowadzanie liter) staje sie bezuzyteczne
  //poniewaz string jest to ciag znakow zarowno liter jak i liczb.
};


class Lista
{
  private:

    Zbior_Liczb * front, * back;
    unsigned licznik;

  public:

    Lista()
    {
      front = back = NULL;
      licznik  = 0;
    }

    ~Lista()
    {
      Zbior_Liczb * p;

      while(front)
      {
        p = front->next;
        delete front;
        front = p;
      }
    }

    unsigned size()
    {
      return licznik;
    }

    Zbior_Liczb * push_front(Zbior_Liczb * p)
    {
      p->next = front; p->prev = NULL;
      if(front) front->prev = p;
      front = p;
      if(!back) back = front;
      licznik++;
      return front;
    }


    Zbior_Liczb * push_back(Zbior_Liczb * p)
    {
      if(back) back->next = p;
      p->next = NULL; p->prev = back;
      back = p;
      if(!front) front = back;
      licznik++;
      return back;
    }

    Zbior_Liczb * pop_front()
    {
      Zbior_Liczb * p;

      if(front)
      {
        p = front;
        front = front->next;
        if(!front) back = NULL;
        else front->prev = NULL;
        licznik--;
        return p;
      }
      else return NULL;
    }

    Zbior_Liczb * pop_back()
    {
      Zbior_Liczb * p;

      if(back)
      {
        p = back;
        if(p == front) front = back = NULL;
        else
        {
          back = back->prev;
          back->next = NULL;
        };
        licznik--;
        return p;
      }
      else return NULL;
    }

    void wyswietl()
    {
      Zbior_Liczb * p;

      if(!front) cout << "Lista jest pusta." << endl;
      else
      {
        p = front;
        while(p)
        {
          cout << p->key << " ";
          p = p->next;
        }
        cout << endl;
      }
    }
};

main()
{
  Lista    L;
  Zbior_Liczb * p;
  int opcja;
   //int i; // dla liczb
   string i; // dla wyrazow



do{
cout<<"----------------------"<<endl;
cout << "1.dodaj na poczatek" << endl;
cout << "2.usun z poczatku" << endl;
cout << "3.wyswietl" << endl;
cout << "4.dodaj na koniec" << endl;
cout << "5.usun z konca" << endl;
cout << "0.Zakoncz" << endl;
cout<<"----------------------"<<endl;

cin>>opcja;

switch(opcja){
    case 1:

        cout<< "Podaj Liczbe ktora chcesz dodac: ";
cin >> i;
        do{
      if(cin.fail())
      {

         cout << "Niedozwolony Znak! Wprowadz Ponownie: ";
         cin.clear();
        cin.sync();
        cin >> i;

      }}while(cin.fail());
      p = new Zbior_Liczb;
    p->key = i;
    L.push_front(p);
  cout << "Poczatek listy-> ";L.wyswietl();

break;

case 2:
    L.pop_front();
    if(L.size() == 0 ) cout << "Lista jest pusta." << endl;
      else{
cout << "Poczatek listy-> ";L.wyswietl();
      }

break;

case 3:
    if(L.size() == 0 ) cout << "Lista jest pusta." << endl;
      else{
 cout << "Poczatek listy-> ";L.wyswietl();
 cout<< "Liczba elementow w liscie: "<<L.size()<<endl;
      }

break;

case 4:

        cout<< "Podaj Liczbe ktora chcesz dodac: ";
cin >> i;
        do{
      if(cin.fail())
      {

         cout << "Niedozwolony Znak! Wprowadz Ponownie: ";
         cin.clear();
        cin.sync();
        cin >> i;

      }}while(cin.fail());    p = new Zbior_Liczb;
    p->key = i;
    L.push_back(p);
  cout << "Poczatek listy-> ";L.wyswietl();


break;

case 5:
    L.pop_back();
    if(L.size() == 0 ) cout << "Lista jest pusta." << endl;
      else{
cout << "Poczatek listy-> ";L.wyswietl();
      }
      break;
case 0:

        cout << "\t\tKonczenie Pracy Programu."<<endl;

 for(int i=0;i<n;i++)
{
    Sleep(50);
    cout <<(char)219;

}
    break;
default:
    cout << "Nie ma takiej Opcji! "<<endl<<endl;

}

}while(opcja != 0);

return 0;
}

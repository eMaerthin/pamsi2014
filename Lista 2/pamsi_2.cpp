#include <iostream>
#include <windows.h>
const int n = 50;
using namespace std;

struct Zbior_Liczb
{
  Zbior_Liczb * next;
  //int key; // jesli maja to byc liczby
  double key; //jesli maja to byc l.zmiennoprzecinkowe
};

class Stos
{
  private:

    Zbior_Liczb * front, * back;
    unsigned licznik;

  public:

    Stos()
    {
      front = back = NULL;
      licznik  = 0;
    }


    ~Stos()
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
      p->next = front;
      front = p;
      if(!back) back = front;
      licznik++;
      return front;
    }

    Zbior_Liczb * pop_front()
    {
      Zbior_Liczb * p;

      if(front)
      {
        p = front;
        front = front->next;
        if(!front) back = NULL;
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


   int main()
{
Stos s;
Zbior_Liczb * p, *k;

    int opcja;

do{
cout<<"----------------------"<<endl;
cout << "1.dodaj na poczatek" << endl;
cout << "2.usun z poczatku" << endl;
cout << "3.wyswietl" << endl;
cout << "0.Zakoncz" << endl;
cout<<"----------------------"<<endl;

cin>>opcja;

switch(opcja){
    case 1:
       // int i; //jesli maja to byc liczby
        double i; //jesli maja to byc l.zmiennoprzecinkowe
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
    s.push_front(p);
  cout << "Poczatek listy-> ";s.wyswietl();


break;


break;

case 2:
    s.pop_front();
    if(s.size() == 0 ) cout << "Lista jest pusta." << endl;
      else{
cout << "Poczatek listy-> ";s.wyswietl();
      }

break;

case 3:
    if(s.size() == 0 ) cout << "Lista jest pusta." << endl;
      else{
 cout << "Poczatek listy-> ";s.wyswietl();
 cout<< "Liczba elementow w liscie: "<<s.size()<<endl;
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

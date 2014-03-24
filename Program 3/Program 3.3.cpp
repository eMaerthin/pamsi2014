/*Lista 3 zadanie 3 - kolejka*/
#include <iostream>
#include <queue>

using namespace std;
int main()
{
    queue<int> kolejka,tmp;
    int wybor,wartosc;
    do
    {
        cout<<"1.Dodanie elementu na koniec kolejki\n2.Usuwanie elementu z poczatku kolejki\n3.Wyswietlenie dlugosci kolejki\n4.Wyswietlenie zawartosci\n0.Zakoncz\n";
        cin>>wybor;
        switch(wybor)
        {
                     case 1:
                          cout<<"Wprowadz wartosc dodawanego elementu\n";
                          cin>>wartosc;
                          kolejka.push(wartosc);
                          break;
                     case 2:
                          cout<<"Usuwanie elementu z poczatku kolejki\n";
                          if(!kolejka.empty())
                          kolejka.pop();
                          else
                          cout<<"Nie mozna usunac elementu z pustej listy\n";
                          break;
                     case 3:
                          cout<<"Dlugosc kolejki wynosi "<<kolejka.size()<<"\n";
                          break;
                     case 4:
                          tmp=kolejka;
                          while(!tmp.empty())
                                {
                                                  cout<<tmp.front()<<" ";
                                                  tmp.pop();
                                }
                                cout<<"\n";
                          break;
                          
        }
    }
    while(wybor);
}


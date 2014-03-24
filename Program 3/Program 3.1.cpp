/*Lista 3 zadanie 1 - Stos*/
#include <iostream>
#include <stack>
using namespace std;



int main()
{
    stack<int> stos,tmp;
    int wybor,wartosc,ilosc;
    do{
              cout<<"1.Umieszczanie elementu na stosie\n2.Wyswietlanie zawartosci stosu\n3.Wyszukiwanie elementu na stosie\n4.Usuwanie elementu ze stosu\n0.Zakoncz\n";
              cin>>wybor;
              switch(wybor)
              {
                           case 1:
                                cout<<"Umieszczanie elementu na stosie. Podaj wartosc\n";
                                cin>>wartosc;
                                stos.push(wartosc);
                                break;
                           case 2:
                                cout<<"Aktualny stos:\n";
                                tmp=stos;
                                while(!tmp.empty())
                                {
                                                  cout<<tmp.top()<<" ";
                                                  tmp.pop();
                                }
                                cout<<"\n";
                                break;
                           case 3:
                                ilosc=0;
                                cout<<"Wybierz wartosc szukanego elementu\n";
                                cin>>wartosc;
                                tmp=stos;
                                while(!tmp.empty())
                                {
                                      if(tmp.top()==wartosc)
                                      ilosc++;
                                      tmp.pop();            
                                }
                                cout<<"Element wystepuje na stosie "<<ilosc<<" razy\n";
                                break;
                           case 4:
                                cout<<"Usuwanie elementu ze stosu\n";
                                if(!stos.empty())
                                stos.pop();
                                else
                                cout<<"Nie mozna usunac elementu z pustego stosu\n";
                                break;
              } 
      }
    while(wybor);          
}








#include <queue>
#include <iostream>
#include <windows.h>

const int n = 50;
using namespace std;
int main()
{
    queue < int > kolejka;
    queue < int > kolejka_tmp;
int opcja,liczba;

    do
    {
        cout << "1. Dodanie Elementu na koniec kolejki."<<endl;
        cout << "2. Usuwanie Elementow z poczatku kolejki."<<endl;
        cout << "3. Wyswietlenie dlugosci kolejki."<<endl;
        cout << "0. Zakoncz."<<endl;
      cin>>opcja;
switch(opcja){
case 1:
    cout << "Jaka Liczbe dodac na koniec kolejki ? : ";
    cin >> liczba;
kolejka.push(liczba);
kolejka_tmp = kolejka;
while(!kolejka_tmp.empty())
{
    cout <<"<-"<<kolejka_tmp.front();
    kolejka_tmp.pop();

}

cout<<endl;
    break;
case 2:
    if (kolejka.size() != 0)
    {
    kolejka.pop();
    kolejka_tmp = kolejka;
    cout << "Usunieto pierwszy element kolejki."<<endl;

while(!kolejka_tmp.empty())
{
    cout <<"<-"<<kolejka_tmp.front();
    kolejka_tmp.pop();
}
cout<<endl;
}
else
    cout << "W kolejce nie znajduja sie zadne liczby."<<endl<<endl;
    break;
case 3:
    if (kolejka.size()!= 0)
    cout << "W kolejce znajduje sie "<<kolejka.size()<< " liczb"<<endl;
    if (kolejka.size() == 0)
        cout << "W kolejce nie znajduja sie zadne liczby."<<endl<<endl;
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

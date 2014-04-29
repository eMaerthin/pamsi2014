#include <queue>
#include <iostream>
#include <windows.h>
#include <conio.h>

const int n = 50;
using namespace std;
int main()
{
    queue < int > kolejka;
    queue < int > kolejka_tmp;
int opcja,liczba;

    do
    {
    cout << char(201);
for(int r=0;r<39;r++)
{
   cout << char(205);

}
cout << char(187);
cout<<endl;
cout <<char(186)  <<"1.Dodawanie Elementu na koniec kolejki " <<char(186) << endl;
cout << char(186) <<"2.Usuwanie Elementow z poczatku kolejki" <<char(186) << endl;
cout << char(186) <<"3.Wyswietlanie dlugosci kolejki        " <<char(186) << endl;
cout << char(186) <<"0.Koniec                               " <<char(186) << endl;
cout << char(200);
for(int r=0;r<39;r++)
{
   cout << char(205);

}
cout << char(188)<<endl;
if(kolejka.size()>0){
cout<<endl;
    for(int r=0;r<kolejka.size()+20;r++){
   cout << char(205);}
cout<<endl;
cout << "Wygenerowana Kolejka"<<endl;
kolejka_tmp = kolejka;
while(!kolejka_tmp.empty())
{
    cout <<char(60)<<kolejka_tmp.front();
    kolejka_tmp.pop();
}
cout<<endl;
    for(int r=0;r<kolejka.size()+20;r++){
   cout << char(205);}

        cout<<endl;
}
cout << "Twoj Wybor"<<char(175);
cin>>opcja;
if(cin.fail())
      do{

         cout << "Niedozwolony Znak! Wprowadz Ponownie: ";
         cin.clear();
        cin.sync();
        cin >> opcja;

      }while(cin.fail());

switch(opcja){
case 1:
    cout << "Jaka Liczbe dodac na koniec kolejki ? : ";
    cin >> liczba;

      if(cin.fail())
      do{

         cout << "Niedozwolony Znak! Wprowadz Ponownie: ";
         cin.clear();
        cin.sync();
        cin >> liczba;

      }while(cin.fail());
kolejka.push(liczba);

cout << "Dodano "<< liczba << " do kolejki."<<endl;
cout<<endl;
cout << "Wcisnij dowolny klawisz aby powrocic do MENU";
         getch();
        system( "cls" );
    break;
case 2:
    if (kolejka.size() != 0)
    {
    kolejka.pop();
    kolejka_tmp = kolejka;
    cout << "Usunieto pierwszy element kolejki."<<endl;
}
else
    cout << "W kolejce nie znajduja sie zadne liczby."<<endl<<endl;
    cout << endl;
    cout << "Wcisnij dowolny klawisz aby powrocic do MENU";
         getch();
        system( "cls" );
    break;
case 3:
    if (kolejka.size()!= 0){
    cout << "W kolejce ";
if(kolejka.size()== 1)                             cout <<"znajduje sie "<<kolejka.size()<<" liczba."<<endl;
if(kolejka.size() < 5 && kolejka.size() > 1  )     cout <<"znajduja sie "<<kolejka.size()<<" liczby."<<endl;
if(kolejka.size() > 4)                             cout <<"znajduje sie "<<kolejka.size()<<" liczb."<<endl;
            }
    if (kolejka.size() == 0)
        cout << "W kolejce nie znajduja sie zadne liczby."<<endl<<endl;
        cout<<endl;
        cout << "Wcisnij dowolny klawisz aby powrocic do MENU";
         getch();
        system( "cls" );
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
    cout << "Nie ma takiej Opcji! "<<endl;
    cout << "Wcisnij dowolny klawisz aby powrocic do MENU";
         getch();
        system( "cls" );
    }
    }while(opcja != 0);

    return 0;
}

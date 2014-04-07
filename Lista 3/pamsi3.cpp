#include <stack>
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
const int n = 50;


int main()
{
stack < int > stosLiczb;
stack < int > stosLiczb_tmp;


int opcja,liczba,licznik;

do{
cout << char(201);
for(int r=0;r<31;r++)
{
   cout << char(205);

}
cout << char(187);
cout<<endl;
cout <<char(186)  <<"1.Umieszczane na stosie        " <<char(186) << endl;
cout << char(186) <<"2.Wyswietlenie zawartosci stosu" <<char(186) << endl;
cout << char(186) <<"3.Wyszukiwanie elementu stosu  " <<char(186) << endl;
cout << char(186) <<"4.Usuwanie elementu stosu      " <<char(186) <<endl;
cout <<char(186)  <<"0.Zakoncz                      " <<char(186) <<endl;
cout << char(200);
for(int r=0;r<31;r++)
{
   cout << char(205);

}
cout << char(188)<<endl;
cout << "Twoj Wybor"<<char(175);
cin>>opcja;

switch(opcja){


case 1:
    cout<< "Wpisujac liczby pamietaj ze jest to STOS czyli struktura danych typu LIFO (Last in First Out ) "<<endl;
    cout << "Podaj liczbe (99 konczy wpisywanie) : "<<endl;
	do{
    cout<< " #";
	cin >> liczba;
	do{
      if(cin.fail())
      {

         cout << "Niedozwolony Znak! Wprowadz Ponownie: ";
         cin.clear();
        cin.sync();
        cin >> liczba;

      }}while(cin.fail());

        stosLiczb.push( liczba );
	}while(liczba != 99);
	stosLiczb.pop();
	system( "cls" );
break;
case 2:
    if (stosLiczb.size()!= 0)
    {
stosLiczb_tmp = stosLiczb;
while(!stosLiczb_tmp.empty())
{
	cout <<"# "<<stosLiczb_tmp.top()<<endl;
	stosLiczb_tmp.pop();
}
}
if (stosLiczb.size() == 0)
        cout << "W stosie nie znajduja sie zadne liczby."<<endl<<endl;
        cout << "Wcisnij dowolny klawisz aby powrocic do MENU";
         getch();
        system( "cls" );
break;

case 3:
    if (stosLiczb.size() == 0)
    {
        cout << "W stosie nie znajduja sie zadne liczby."<<endl<<endl;
        cout << "Wcisnij dowolny klawisz aby powrocic do MENU";
         getch();
        system( "cls" );
        break;
    }
    int k;
    cout << "Jaki Element sprawdzic czy znajduje sie w stosie: ";
    cin>>k;
    do{
      if(cin.fail())
      {

         cout << "Niedozwolony Znak! Wprowadz Ponownie: ";
         cin.clear();
        cin.sync();
        cin >> k;

      }}while(cin.fail());

    stosLiczb_tmp = stosLiczb;
    licznik = 0;
while (!stosLiczb_tmp.empty())
{
    if (k == stosLiczb_tmp.top())
            {
                licznik++;
            }
            stosLiczb_tmp.pop();
}

if (licznik == 0)
{
    cout << "Wybrany element nie znajduje sie w stosie :( "<<endl;
}
if (licznik == 1)
{
    cout << "Szukany element wystepuje tylko raz w calym stosie :) "<<endl;
}
if (licznik > 1)
{
    cout << "Szukany element wystepuje "<<licznik<<" razy w calym stosie :) "<<endl;
}
cout << "Wcisnij dowolny klawisz aby powrocic do MENU";
         getch();
        system( "cls" );
    break;
case 4:
    if (stosLiczb.size() == 0)
    {
        cout << "W kolejce nie znajduja sie zadne liczby."<<endl<<endl;
        cout << "Wcisnij dowolny klawisz aby powrocic do MENU";
         getch();
        system( "cls" );
        break;
    }
        else
stosLiczb.pop();
cout<< "Usunieto Element ze szczytu stosu. "<<endl;
stosLiczb_tmp = stosLiczb;
while(!stosLiczb_tmp.empty())
{
	cout <<"# "<<stosLiczb_tmp.top()<<endl;
	stosLiczb_tmp.pop();

}
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
    cout << "Nie ma takiej Opcji! ";
Sleep(2000);
system( "cls" );
}
}while(opcja != 0);
    return 0;
}

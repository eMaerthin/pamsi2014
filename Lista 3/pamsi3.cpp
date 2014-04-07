#include <stack>
#include <iostream>
#include <windows.h>
using namespace std;
const int n = 50;
int main()
{
stack < int > stosLiczb;
stack < int > stosLiczb_tmp;


int opcja,liczba,licznik;

do{

cout << "1.Umieszczane na stosie" << endl;
cout << "2.Wyswietlenie zawartosci stosu" << endl;
cout << "3.Wyszukiwanie elementu stosu" << endl;
cout << "4.Usuwanie elementu stosu" << endl;
cout << "0.Zakoncz" << endl;
cin>>opcja;

switch(opcja){


case 1:
    cout<< "Wpisujac liczby pamietaj ze jest to STOS czyli struktura danych typu LIFO (Last in First Out ) "<<endl;
    cout << "Podaj liczbe (99 konczy wpisywanie) : "<<endl;
	do{
    cout<< " #";

	cin >> liczba;
        stosLiczb.push( liczba );
	}while(liczba != 99);
	stosLiczb.pop();
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
break;

case 3:
    if (stosLiczb.size() == 0)
    {
        cout << "W kolejce nie znajduja sie zadne liczby."<<endl<<endl;
        break;
    }
    int k;
    cout << "Jaki Element sprawdzic czy znajduje sie w stosie: ";
    cin>>k;
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
else
{
    cout << "Szukany element wystepuje "<<licznik<< " raz/y w stosie :) "<<endl;
}

    break;
case 4:
    if (stosLiczb.size() == 0)
    {
        cout << "W kolejce nie znajduja sie zadne liczby."<<endl<<endl;
        break;
    }
        else
stosLiczb.pop();
cout<< "Usunieto Element ze szczytu stosu. "<<endl;
break;
case 0:

        cout << "\t\tKonczenie Pracy Programu."<<endl;

 for(int i=0;i<n;i++)
{
    Sleep(50);
    cout <<(char)219;

}
}
}while(opcja != 0);
    return 0;
}

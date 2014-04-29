#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()

{
    int opcja,x,n,k;
    int R = 31;
    int tab[R];

    srand((unsigned)time(NULL));
    for(int i = 0; i < R; i++)
    {
        tab[i] = rand() % 10;
    }


vector < int > v(tab, tab + R);

               do{

    cout << char(201);
for(int r=0;r<39;r++)
{
   cout << char(205);

}
cout << char(187);
cout<<endl;
cout <<char(186)  <<"1.Tworzymy Kopiec                      " <<char(186) << endl;
cout << char(186) <<"2.Wyswietl Kopiec                      " <<char(186) << endl;
cout << char(186) <<"3.Usun Najwiekszy Element              " <<char(186) << endl;
cout << char(186) <<"0.Koniec                               " <<char(186) << endl;
cout << char(200);
for(int r=0;r<39;r++)
{
   cout << char(205);

}
cout << char(188)<<endl;
for(int r=0;r<62;r++)
{
   cout << char(205);

}
cout<<endl;
cout << "Wygenerowana Losowo Tablica"<<endl;
for (int i = 0; i<R; i++){
cout << v[i] << char(249);
}    cout<<endl;
    for(int r=0;r<62;r++)
{
   cout << char(205);

}
        cout<<endl;
cout << "Twoj Wybor"<<char(175);
   cin>>opcja;
   if(cin.fail())
      do{

         cout << "Niedozwolony Znak! Wprowadz Ponownie: ";
         cin.clear();
        cin.sync();
        cin >> opcja;

      }while(cin.fail());

switch(opcja)
{
case 1:
make_heap(v.begin(), v.end());
cout<<"Utworzono kopec"<<endl;
cout<<endl;
cout << "Wcisnij dowolny klawisz aby powrocic do MENU";
         getch();
        system( "cls" );
break;
case 2:
x = (R + 1 ) / 2; k = 2;
for (int i = 0; i < R; i++)
{
for (int j = 1; j < x ; j++) cout << " ";
cout <<v[i];
for (int j = 1; j <= x; j++) cout << " ";
if (i + 2 == k)
{
cout << " ";
k += k;
x /= 2;
cout << " " << endl;
}
}
cout << endl;
cout<<endl;
cout << "Wcisnij dowolny klawisz aby powrocic do MENU";
         getch();
        system( "cls" );
                                            break;
                                case 3:
pop_heap(v.begin(), v.end());
R--;
x = R  / 2; k = 2;
for (int i = 0; i < R; i++)
{
for (int j = 1; j < x ; j++) cout << " ";
cout <<v[i];
for (int j = 1; j <= x; j++) cout << " ";
if (i + 2 == k)
{
cout << " ";
k += k;
x /= 2;
cout << " " << endl;
}
}
cout << endl;
cout<<endl;
cout << "Wcisnij dowolny klawisz aby powrocic do MENU";
         getch();
        system( "cls" );


                                            break;
                                case 0:
                                    cout << "\t\tKonczenie Pracy Programu"<<endl;

 for(int i=0;i<62;i++)
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

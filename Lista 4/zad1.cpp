#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <iomanip>


using namespace std;



class Sortownik{

vector <string> w;
vector <string> w_tmp;
string wyraz;
string x;



int ile,ile_;
int I;
int i,p;

public:

int k;
double PCFreq,C;
__int64 CounterStart;


void ile_wyrazow();
void ile_posort();
void clone();
void clear();
void clear_All();
void QuickS();
void BubleS();
void InsertS();
void poka();
void save();
void StartCounter();
double GetCounter();




};

void Sortownik::save()
{
    ofstream plik;
plik.open("wyniki.txt", ios::out|ios::app);
if(k==1)
plik<<"QuickSort,"<<setprecision(2)<<fixed<< C << "," <<w.size()<<","<<endl;
if(k==2)
plik<<"BubleSort,"<<setprecision(2)<<fixed<< C << "," <<w.size()<<","<<endl;
if(k==3)
plik<<"InsertSort,"<<setprecision(2)<<fixed<< C << "," <<w.size()<<","<<endl;
plik.close();
}

void Sortownik::ile_wyrazow()
{


    cout << char(201);
for(int r=0;r<25;r++)
{
   cout << char(205);

}
cout << char(187);
cout<<endl;
cout <<char(186)  <<"1.Zbior 100 wyrazow      " <<char(186) << endl;
cout << char(186) <<"2.Zbior 1 000 wyrazow    " <<char(186) << endl;
cout << char(186) <<"3.Zbior 10 000 wyrazow   " <<char(186) << endl;
cout << char(186) <<"4.Zbior 100 000 wyrazow  " <<char(186) << endl;
cout << char(186) <<"5.Zbior 1000 000 wyrazow " <<char(186) << endl;
cout << char(200);
for(int r=0;r<25;r++)
{
   cout << char(205);

}
cout << char(188)<<endl;
cout<<endl;
cout << "Twoj Wybor"<<char(175);
    cin >>ile;
    if(cin.fail())
      do{

         cout << "Niedozwolony Znak! Wprowadz Ponownie: ";
         cin.clear();
        cin.sync();
        cin >> ile;

      }while(cin.fail());


    switch(ile)
    {
        case 1:
            {
    ifstream in("wyrazy100.txt");
    while(in >> wyraz)
    w.push_back(wyraz);
    break;
            }
        case 2:
           {
    ifstream in("wyrazy1000.txt");
    while(in >> wyraz)
    w.push_back(wyraz);
    break;

    }
        case 3:
            {
    ifstream in("wyrazy10000.txt");
    while(in >> wyraz)
    w.push_back(wyraz);
    break;
            }
            case 4:
            {
    ifstream in("wyrazy100000.txt");
    while(in >> wyraz)
    w.push_back(wyraz);
    break;
            }
            case 5:
            {
    ifstream in("wyrazy1000000.txt");
    while(in >> wyraz)
    w.push_back(wyraz);
    break;

            }
             default :
                cout<< "Nie ma takiej opcji!"<<endl;
                exit(0);

}
}

void Sortownik::ile_posort()
{
     cout << char(201);
for(int r=0;r<35;r++)
{
   cout << char(205);

}
cout << char(187);
cout<<endl;
cout <<char(186)  <<"1.Zbior w calosci nieuporzadkowany " <<char(186) << endl;
cout << char(186) <<"2.Zbior uporzadkowany w 10%        " <<char(186) << endl;
cout << char(186) <<"3.Zbior uporzadkowany w 50%        " <<char(186) << endl;
cout << char(186) <<"4.Zbior uporzadkowany w 90%        " <<char(186) << endl;
cout << char(186) <<"5.Zbior uporzadkowany w 99%        " <<char(186) << endl;
cout << char(200);
for(int r=0;r<35;r++)
{
   cout << char(205);

}
cout << char(188)<<endl;
cout<<endl;
cout << "Twoj Wybor"<<char(175);
    cin>>ile_;
    if(cin.fail())
      do{

         cout << "Niedozwolony Znak! Wprowadz Ponownie: ";
         cin.clear();
        cin.sync();
        cin >> ile_;

      }while(cin.fail());
    switch(ile_)
    {
    case 1:
        break;
    case 2:
         sort(w.begin(),w.begin()+(w.size()*0.1));
        break;
    case 3:
         sort(w.begin(),w.begin()+(w.size()*0.5));
        break;
    case 4:
         sort(w.begin(),w.begin()+(w.size()*0.9));
        break;
    case 5:
         sort(w.begin(),w.begin()+(w.size()*0.99));
        break;
        default :
                cout<< "Nie ma takiej opcji!"<<endl;
                exit(0);
    }
}

void Sortownik::clone()
{
    w_tmp.assign(w.begin(),w.end());
}

void Sortownik::clear()
{
    w_tmp.clear();
}

void Sortownik::clear_All()
{
    w_tmp.clear();
    w.clear();
}


void Sortownik::QuickS()
{
  sort(w_tmp.begin(),w_tmp.end());
}

void Sortownik::BubleS()
{
    for(int j = w_tmp.size() - 1; j > 0; j--)
  {
    p = 1;
    for(int i = 0; i < j; i++)
      if(w_tmp[i] > w_tmp[i + 1])
      {
        swap(w_tmp[i], w_tmp[i + 1]);
        p = 0;
      }
    if(p) break;
  }
}

void Sortownik::InsertS()
{
   for(int j = w_tmp.size() - 2; j >= 0; j--)
  {
    x = w_tmp[j];
    i = j + 1;
    while((i < w_tmp.size()) && (x > w_tmp[i]))
    {
      w_tmp[i - 1] = w_tmp[i];
      i++;
    }
    w_tmp[i - 1] = x;
  }
}



void Sortownik::poka()
{
    I=0;
    cout<<endl;
  for(int i = 0; i < w_tmp.size(); i++)
    {
        cout << w_tmp[i] << " ";
        I++;
        if (I == 10)
        {
            cout<<endl;
            I=0;
        }

    }
    cout<<endl;
}



void Sortownik::StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
	cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double Sortownik::GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    C = (li.QuadPart-CounterStart)/PCFreq;
    return C;

}

int main()
{

 char opcja = 't';

   Sortownik s;
   s.PCFreq = 0.0;
   __int64 CounterStart = 0;
   s.k=1;

   while(opcja=='t'){

s.ile_wyrazow();
s.ile_posort();
s.clone();
s.StartCounter();
s.QuickS();
s.GetCounter();
s.save();
s.k++;
s.clear();

s.clone();
s.StartCounter();
s.BubleS();
s.GetCounter();
s.save();
s.k++;
s.clear();

s.clone();
s.StartCounter();
s.InsertS();
s.GetCounter();
s.save();
s.k=1;
s.clear_All();
	Beep(900, 250);
	cout<< "               GOTOWE! :) "<<endl;
	cout<< "Wyniki zapisano do pliku 'wyniki.txt' " <<endl;

cout<< "Powtorzyc Esperyment? [t/n] ";
cin>>opcja;



    while((opcja!='t')&&(opcja!='n'))
    {
        cout<< "Zly znak! ...Powtorzyc Eksperyment? [t/n] ";
        cin>>opcja;
    }
system( "cls" );

   }

return 0;
}

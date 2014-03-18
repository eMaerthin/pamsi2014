#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int *t, *wsk;
  int N,i;



void wczytaj_konsola ()
{
     cout<<"Podaj wielkosc tablicy: ";
     cin>>N;
     t=new int[N];

for(i=0;i<N;++i)
 {cout<<"#"<<i+1<<"# ";
   cin>>t[i];
}
}
void wyswietl_tablice()
{
    cout<<"\n\n Utworzona Tablica\n";
 for(i=0;i< N;++i)
 {
 cout<<" #"<<t[i]<<endl;
 cout<<endl;

 }

}
void z_txt ()
{
ifstream dane("tab.txt");
dane>>N;
     t=new int[N];
     for (int i=0;i<N; i++){
                        dane>>t[i];
                }
                dane.close();
}
void do_txt()
{
  
ofstream plik("tab.txt", ios::trunc);
plik<<N<<endl;
                        for (int i=0; i<N; i++){
                                plik<<t[i]<<endl;
                        }
                        plik.close();
}
void z_bin ()
{
 ifstream ifs("tab.dat", ios::binary);
 ifs>>N;
         t=new int[N];
        for (int i=0; i<N; i++){
                char* temp = new char[sizeof(int)];
                ifs.read(temp, sizeof(int));
                int* element = (int*)(temp);
                t[i]=*element;
        }
        ifs.close();
        }

void do_bin()
{
 ofstream ofs("tab.dat", ios::binary);
  ofs<<N;
        for (int i=0; i<N; i++){
                ofs.write((char*)(&t[i]), sizeof(t[i]));
        }
        ofs.close();
}
void losowe()
{
    cout<<"Podaj wielkosc tablicy: ";
     cin>>N;
     t=new int[N];
    for(i=0;i<N;++i)
 {
     t[i]=rand()%11;

}
}
int* kopia()
{
        wsk = new int[N];
        for(int i=0;i<N;i++)
        {
            wsk[i] = t[i];
        }
        return wsk;
}
void wyswietl_kopie()
{


    cout<<"\n\n ORGINAL      COPY"<<endl;
 for(i=0;i<N;i++)
 {
 cout<<" # "<<t[i]<<"      #COPY# "<< wsk[i]<<"\n"<<endl;
 }
}
int main()
{



int opcja;

do{

cout << "1.Wczytanie tablicy z konsoli" << endl;
cout << "2.Wyswietlenie tablicy" << endl;
cout << "3.Wczytywanie z pliku tekstowego" << endl;
cout << "4.Zapisywanie do pliku tekstowego" << endl;
cout << "5.Wczytywanie z pliku binarnego" << endl;
cout << "6.Zapisywanie do pliku binarnego" << endl;
cout << "7.Wypelnianie liczbami losowymi" << endl;
cout << "8.Tworzenie dynamicznej kopii tablicy + wyswietlenie" << endl;
cout << "0.Wyjscie z programu\n" << endl;
cout << "\t\t\t\tWybierz Opcje" << endl<<endl;
cout << "# ";
cin>>opcja;

switch(opcja){

case 1:
wczytaj_konsola();
break;

case 2:
wyswietl_tablice();
break;

case 3:
z_txt();
break;

case 4:
do_txt();
break;

case 5:
z_bin();
break;

case 6:
do_bin();
break;

case 7:
losowe();
break;

case 8:
kopia();
wyswietl_kopie();
break;


}

}while(opcja != 0);
return 0;
}

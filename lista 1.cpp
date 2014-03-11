
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
 
using namespace std;
 
const int ROZMIAR = 3;
 
void wczytaj_z_konsoli(float tab[]){
        for(int i = 0; i<ROZMIAR; i++){
                cout<<"Podaj "<<i+1<<" element tablicy\n";
                cin>>tab[i];
        }
}
 
void wyswietl(float tab[]){
        cout<<"Elementy tablicy:\n";
        for(int i = 0; i<ROZMIAR; i++){
                cout<<tab[i]<<endl;
        }
        cout<<endl<<endl;
}
 
void wczytaj_z_txt(float tab[]){
        ifstream dane("D:\\tab.txt");
                if (!dane){
                        cout << "Nie mozna otworzyc pliku.\n <tab.txt>";
                        cin.get();
                        return;
                }
                for (int i=0;!dane.eof() &&  i<ROZMIAR; i++){
                        dane>>tab[i];
                }
        cout<<"Pomyslnie wczytano dane z pliku <tab.txt>"<<endl<<endl;
        dane.close();
}
 
void zapisz_do_txt(float tab[]){
 
        ofstream plik("D:\\tab.txt", ios::trunc);
                if( plik.good() ){
                        for (int i=0; i<ROZMIAR; i++){
                                plik<<tab[i]<<endl;
                        }
                        plik.close();
                        cout<<endl<<endl<<"Zapisano do pliku <tab.txt>"<<endl<<endl;
                }
                else cout<<"Blad! Nie zapisano do pliku <tab.txt>\n";
 
}
 
void zapisz_do_bin(float tab[]){
        ofstream ofs("D://tab.dat", ios::binary);
        for (int i=0; i<ROZMIAR; i++){ 
                ofs.write((char*)(&tab[i]), sizeof(tab[i]));
        }
        ofs.close();
}
 
void wczytaj_z_bin(float tab[]){
        ifstream ifs("D://tab.dat", ios::binary);
        for (int i=0; i<ROZMIAR; i++){ 
                char* temp = new char[sizeof(float)];
                ifs.read(temp, sizeof(float));
                float* element = (float*)(temp);
                tab[i]=*element;
        }
        ifs.close();
}
 
void wypelnij_losowymi(float tab[]){
        unsigned ile=0;
        cout<<"Ile losowych liczb ma zostac wstawionych: ";
        cin>>ile;
        if(ile>ROZMIAR) ile = ROZMIAR;
 
        srand (time(NULL));
 
        for (int i=0; i<ile; i++){                     
                tab[i] = rand() % 10 + 1;
        }
}
 
float* kopia_dynamiczna(float tab[], int rozmiar)
{
        float *wsk = new float[rozmiar];
        for(int i=0;i<rozmiar;i++) wsk[i] = tab[i];
        return wsk;
}
 
int main()
{
        float tablica[ROZMIAR];
 
        unsigned short opcja=0;
 
        do{
                cout << "1.Wczytanie tablicy z konsoli"<<endl;
                cout << "2.Wyswietlenie tablicy"<<endl;
                cout << "3.Wczytywanie z pliku tekstowego"<<endl;
                cout << "4.Zapisywanie do pliku tekstowego"<<endl;
                cout << "5.Wczytywanie z pliku binarnego"<<endl;
                cout << "6.Zapisywanie do pliku binarnego"<<endl;
                cout << "7.Wypelnianie tablicy"<<endl;
                cout << "8.Tworzenie dynamicznej kopii + wyœwietlenie kopii"<<endl;
                cout << "0.Koniec"<<endl;
                cout << "\n Wybierz opcje\n";
 
                cin >> opcja;
 
                switch(opcja){
                case 1:
                        wczytaj_z_konsoli(tablica);
                         break;
                case 2:
                        wyswietl(tablica);
                        break;
                 case 3:
                         wczytaj_z_txt(tablica);
                         break;
                case 4:
                        zapisz_do_txt(tablica);
                         break;
                case 5:
                        wczytaj_z_bin(tablica);
                         break;
                case 6:
                        zapisz_do_bin(tablica);                
                         break;
                case 7:
                        wypelnij_losowymi(tablica);
                         break;
                case 8:
                        kopia_dynamiczna(tablica, ROZMIAR);
                         break;
 
        }
}while(opcja !=0);
 
 
        return 0;
}

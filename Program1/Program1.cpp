#include <iostream> // cin
#include <fstream> // strumienie do pliku
#include <sstream> // istringstream
#include <cstdlib> // rand i srand
#include <ctime> // time
using namespace std;

// zmienna pomocnicza globalna testowa
int tabliczka[10]={4,2,16,7,5,6,6,6,5,4};



void wczytywanie_konsola(){


int rozmiar;
cout << "Wprowadz rozmiar tablicy:  " << endl;
cin >> rozmiar;

int * wsk;
wsk = new int[rozmiar];

for(int i = 0; i<rozmiar;i++){
    int liczba;
    cout << "Wprowadz element " << (i+1) << " tablicy:  "<< endl;
    cin >> liczba;
    wsk[i]=liczba;

}
}
void wyswietl(int tab[]){
    int rozmiar;
    cout << "Wprowadz rozmiar wyswietlanej tablicy:  " << endl;
    cin >> rozmiar;
    for (int i = 0;i < rozmiar;i++){
    cout << "Oto element " << (i+1) << "  tablicy  "<< tab[i] << endl;
    }

}
void wczytaj_plik(){


fstream plik_odczyt;
plik_odczyt.open( "C:/Users/S3/Desktop/Wskaznik/2.txt", ios::in); // stala lokalizacja pliku na te chwile
if( plik_odczyt.good() == true )
    {
    cout << "Plik otworzono pomyslnie - sciezka jest poprawna" << endl;
    }
else
    {
    cout << "Blad w dostepie do pliku - prawdopodobnie niepoprawna sciezka do pliku" << endl;
    }
if(plik_odczyt)
    {
    string linia;
    getline(plik_odczyt, linia);
    cout << linia << endl; // linia z rozmiarem
    int rozmiar;
    istringstream iss(linia);
    iss >> rozmiar;
    cout << "odczytany rozmiar  " << rozmiar << endl;


    for(int i=0;i<rozmiar;i++)
        {
        getline(plik_odczyt, linia);
        string str = linia;
        // Konwersja na int
        int temp;
        istringstream iss(str);
        iss >> temp;
        tabliczka[i]=temp;  // na razie do zmiennej globalnej
        }
    plik_odczyt.close();
    }
}
void zapisz_plik(){
    int rozmiar = 10; // na razie staly rozmiar - skoreluj z tworzeniem tablicy lub z inna zmienna
    fstream plik_zapis("C:/Users/S3/Desktop/Wskaznik/1.txt", ios::out);
    if (plik_zapis.good())
        cout << "Plik otworzono / stworzono pomyslnie  " << endl;
    {
        for(int i=0;i<rozmiar;i++)
            {
            int linia;
            linia = (rand()% 9)*2; // zapisuje randomami * 2
            plik_zapis << linia << endl;
            tabliczka[i]=linia;
            }
        plik_zapis.flush();
        plik_zapis.close();
    }
}

void wczytaj_binarny(){

{
ifstream ifs("C:/Users/S3/Desktop/Wskaznik/binarny.foo", ios::binary);
int rozmiar = 10;
char* bufor = new char[rozmiar];
ifs.read(bufor, rozmiar);
int wynik;
stringstream konwersja;
konwersja << bufor;
konwersja >> wynik;
cout << wynik << endl;
}
}

void zapisz_binarny(int tab[]){

int rozmiar = 10;
char tablica[rozmiar];
ofstream ofs("C:/Users/S3/Desktop/Wskaznik/binarny.foo", ios::binary);
// konwersja na tablice char
for(int i = 0;i<rozmiar;i++){
stringstream konwersja;
konwersja << tab[i];
konwersja >> tablica[i];
//char* wsk = &tablica[0];
cout << "tu jest tablica charow " << tablica[i] << endl;
}
char* wsk = tablica;
//ofs.write((char*)(wsk), sizeof(int));
ofs.write((char*)(wsk), rozmiar);
delete wsk;
}
void wpisz_losowe(int tab[]){

    int zakres;
    int rozmiar;
    cout << "Ile elementow ma tablica  " << endl;
    cin >> rozmiar;
    cout << "Podaj maksymalna wartosc n losowej liczby  - liczby wygenerowane beda <0,n>" << endl;
    cin >> zakres;
    for(int i = 0; i < rozmiar; i++){
    tab[i]=(rand()%zakres);
    }


}

int main(){
srand( time( NULL ) ); // wyznacza losowosc



int wybor = 0;
do{
bool poprawny_wybor = false;
cout << endl << endl;
cout << "Witaj w menu, wybierz wartosc od 1 do 9 i zatwierdz klawiszem enter " << endl;
cout << "1 - Wczytywanie tablicy jednowymiarowej z konsoli" << endl;
cout << "2 - Wyswietlenie tablicy jednowymiarowej na konsoli" << endl;
cout << "3 - Wczytywanie tablicy jednowymiarowej z pliku tekstowego" << endl;
cout << "4 - Zapisywanie tablicy jednowymiarowej do pliku tekstowego" << endl;
cout << "5 - Wczytywanie tablicy jednowymiarowej z pliku binarnego" << endl;
cout << "6 - Zapisywanie tablicy jednowymiarowej do pliku binarnego" << endl;
cout << "7 - Wypelnianie tablicy jednowymiarowej liczbami losowymi" << endl;
cout << "8 - Tworzenie dynamicznej kopii tablicy jednowymiarowej" << endl;
cout << "9 - Wyjscie z programu" << endl;
while(poprawny_wybor != true){
	cin >> wybor;
	if((wybor >0)&&(wybor <10))
        {
        poprawny_wybor = true;
        }
	else
        {
        cout << "Niepoprawna wartosc - wprowadz jeszcze raz !" << endl;
        }
    }

switch(wybor){
// "1 - Wczytywanie tablicy jednowymiarowej z konsoli"
case 1:
wczytywanie_konsola();
break;
// "2 - Wyswietlenie tablicy jednowymiarowej na konsoli"
case 2:
wyswietl(tabliczka);
break;
// "3 - Wczytywanie tablicy jednowymiarowej z pliku tekstowego"
case 3:
wczytaj_plik();
break;
// "4 - Zapisywanie tablicy jednowymiarowej do pliku tekstowego"
case 4:
zapisz_plik();
break;
// "5 - Wczytywanie tablicy jednowymiarowej z pliku binarnego"
case 5:
wczytaj_binarny();
break;
// "6 - Zapisywanie tablicy jednowymiarowej do pliku binarnego"
case 6:
zapisz_binarny(tabliczka);
break;
// "7 - Wypelnianie tablicy jednowymiarowej liczbami losowymi"
case 7:
wpisz_losowe(tabliczka);
break;
// "8 - Tworzenie dynamicznej kopii tablicy jednowymiarowej"
case 8:
break;
// "9 - Wyjscie z programu"
case 9:
cout << "Dziekuje za skorzystanie z programu" << endl;
break;
}
}while(wybor!=9);


}

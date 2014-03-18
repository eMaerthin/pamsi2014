#include <iostream> // cin
#include <fstream> // strumienie do pliku
#include <sstream> // istringstream
#include <cstdlib> // rand i srand
#include <ctime> // time
using namespace std;



class Tablica{
public:
    void wczytywanie_konsola();
    void wyswietl();
    void wczytaj_plik();
    void zapisz_plik();
    void wczytaj_binarny();
    void zapisz_binarny();
    void wpisz_losowe();
    int* tworz_dynamiczna(int tab[], int wielkosc);
    // zmienne
    int rozmiar;
    int* wsk;
    int zakres;
    int* kopia;

};

void Tablica::wczytywanie_konsola(){


cout << "Wprowadz rozmiar tablicy:  " << endl;
cin >> rozmiar;

wsk = new int[rozmiar];
for(int i = 0; i<rozmiar;i++){
    int liczba;
    cout << "Wprowadz element " << (i+1) << " tablicy:  "<< endl;
    cin >> liczba;
    wsk[i]=liczba;
}
}
void Tablica::wyswietl(){

    for (int i = 0;i < rozmiar;i++){
    cout << "Oto element " << (i+1) << "  tablicy  "<< wsk[i] << endl;
    }

}
void Tablica::wczytaj_plik(){


fstream plik_odczyt;
plik_odczyt.open( "C:/Users/S3/Desktop/Wskaznik/4.txt", ios::in); // stala lokalizacja pliku na te chwile
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
    //getline(plik_odczyt, linia);
    //cout << linia << endl;
    //istringstream iss(linia);
    //iss >> rozmiar;
    //cout << "odczytany rozmiar  " << rozmiar << endl;


    for(int i=0;i<rozmiar;i++)
        {
        getline(plik_odczyt, linia);
        string str = linia;
        // Konwersja na int
        int temp;
        istringstream iss(str);
        iss >> temp;
        wsk[i]=temp;
        }
    plik_odczyt.close();
    }
}
void Tablica::zapisz_plik(){

    fstream plik_zapis("C:/Users/S3/Desktop/Wskaznik/4.txt", ios::out);
    if (plik_zapis.good())
        cout << "Plik otworzono / stworzono pomyslnie  " << endl;
    {
        for(int i=0;i<rozmiar;i++)
            {
            int linia;
            linia = (rand()% 9)*2.0; // zapisuje randomami * 2
            plik_zapis << linia+1 << endl;
            wsk[i]=linia;
            }
        plik_zapis.flush();
        plik_zapis.close();
    }
}

void Tablica::wczytaj_binarny(){

ifstream ifs("C:/Users/S3/Desktop/Wskaznik/binarny.foo", ios::binary);

char* bufor = new char[rozmiar];
ifs.read(bufor, rozmiar);

int wynik[rozmiar];
for (int i=0;i<rozmiar;i++){
stringstream konwersja;
konwersja << bufor[i];
konwersja >> wynik[i];
cout << wynik[i] << endl;
}

}

void Tablica::zapisz_binarny(){

char tablica[rozmiar];
ofstream ofs("C:/Users/S3/Desktop/Wskaznik/binarny.foo", ios::binary);
// konwersja na tablice char
for(int i = 0;i<rozmiar;i++){
stringstream konwersja;
konwersja << wsk[i];
konwersja >> tablica[i];
}
char* wsk_char = tablica;
ofs.write((char*)(wsk_char), rozmiar);
delete wsk_char;
}
void Tablica::wpisz_losowe(){


    cout << "Podaj maksymalna wartosc n losowej liczby  - liczby wygenerowane beda <0,n>" << endl;
    cin >> zakres;
    for(int i = 0; i < rozmiar; i++){
    wsk[i]=(rand()%zakres);
    }


}
int* Tablica::tworz_dynamiczna(int tab[], int wielkosc){
{

	int i;
	kopia = new int[wielkosc];
	for(i=0;i<wielkosc;i++)
		kopia[i] = tab[i];
}


}

int main(){
srand( time( NULL ) );
Tablica Test;





int wybor = 0;
do{
bool poprawny_wybor = false;
cout << endl << endl;
cout << "Witaj w programie, wybierz wartosc od 1 do 10 i zatwierdz klawiszem enter " << endl;
cout << "1 - Wczytywanie tablicy jednowymiarowej z konsoli" << endl;
cout << "2 - Wyswietlenie tablicy jednowymiarowej na konsoli" << endl;
cout << "3 - Wczytywanie tablicy jednowymiarowej z pliku tekstowego" << endl;
cout << "4 - Zapisywanie tablicy jednowymiarowej do pliku tekstowego" << endl;
cout << "5 - Wczytywanie tablicy jednowymiarowej z pliku binarnego" << endl;
cout << "6 - Zapisywanie tablicy jednowymiarowej do pliku binarnego" << endl;
cout << "7 - Wypelnianie tablicy jednowymiarowej liczbami losowymi" << endl;
cout << "8 - Tworzenie dynamicznej kopii tablicy jednowymiarowej" << endl;
cout << "9 - Wyswietlanie aktualnie przechowywanej tablicy"<< endl;
cout << "10 - Wyjscie z programu" << endl;
while(poprawny_wybor != true){
	cin >> wybor;
    cout << endl << endl << endl;
	if((wybor >0)&&(wybor <11))
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
Test.wczytywanie_konsola();
break;
// "2 - Wyswietlenie tablicy jednowymiarowej na konsoli"
case 2:
Test.wyswietl();
break;
// "3 - Wczytywanie tablicy jednowymiarowej z pliku tekstowego"
case 3:
Test.wczytaj_plik();
break;
// "4 - Zapisywanie tablicy jednowymiarowej do pliku tekstowego"
case 4:
Test.zapisz_plik();
break;
// "5 - Wczytywanie tablicy jednowymiarowej z pliku binarnego"
case 5:
Test.wczytaj_binarny();
break;
// "6 - Zapisywanie tablicy jednowymiarowej do pliku binarnego"
case 6:
Test.zapisz_binarny();
break;
// "7 - Wypelnianie tablicy jednowymiarowej liczbami losowymi"
case 7:
Test.wpisz_losowe();
break;
// "8 - Tworzenie dynamicznej kopii tablicy jednowymiarowej"
case 8:
Test.tworz_dynamiczna(Test.wsk, Test.rozmiar);
for (int i = 0;i < Test.rozmiar;i++){
cout << "Oto element " << (i+1) << "  tablicy  "<< Test.kopia[i] << endl;
}

break;
// "9 - Wyswietlanie tablicy"
case 9:
Test.wyswietl();
break;
// "10 - Wyjscie z programu"
case 10:
cout << "Dziekuje za skorzystanie z programu" << endl;
break;
}
}while(wybor!=10);


}

#include "operacje.hh"

void Wczytywanie_Konsola(queue<int> &tablica) {

	if (!tablica.empty()) do tablica.pop(); while (!tablica.empty()); //czyszczenie tablicy w pamieci przed wczytaniem nowej
	string temp;
	string koniec ("#");
	int elem;

	cout << endl << "Podaj kolejne elementy tablicy. Wpisz # aby zakoñczyæ dodawanie elementów." << endl << endl;
do {
	temp.clear();
	cin >> temp;
	if(temp.compare(koniec) == 0) break; //sprawdzenie, czy wczytano sygnal stop
	else elem=stoi(temp);
	elem >> tablica;
} while (elem>0);
}
void Wyswietl_Konsola(queue<int> tablica) {
	cout << endl << "Tablica elementów: " << endl << tablica << endl << "___________________________________" << endl;
}

void Wczytaj_TXT(queue<int> &tablica) {
	string nazwa;
	string linia;
	fstream plik;
	int elem;

	if (!tablica.empty()) do tablica.pop(); while (!tablica.empty()); //czyszczenie tablicy w pamieci przed wczytaniem nowej

	cout << endl << "Podaj nazwê pliku: " << endl;
	cin >> nazwa;
	plik.open(nazwa, ios::in);
	if (plik.good()) {
		while (getline(plik, linia))  { //wczytywanie do zmiennej tymczasowej
			elem = stoi(linia); //konwersja
			elem >> tablica; //wczytanie do tablicy
		}
		plik.close();
	}
}

void Zapisz_TXT(queue<int> tablica) {
	string nazwa;
	string linia;
	fstream plik;

	cout << endl << "Podaj nazwê pliku:" << endl;
	cin >> nazwa;

	plik.open(nazwa, ios::out);

	if (plik.good() == true) {
		while (plik << tablica.front()) { //zapisywanie do pliku
			plik << endl;
			tablica.pop();
		}
	}
	plik.close();
}
void Wczytaj_BIN(queue<int> &tablica) {
	string nazwa;
	fstream plik;
	char bufor[256];
	int elem;

	if (!tablica.empty()) do tablica.pop(); while (!tablica.empty()); //czyszczenie tablicy w pamieci przed wczytaniem nowej

	cout << endl << "Podaj nazwê pliku: " << endl;
	cin >> nazwa;
	plik.open(nazwa, ios::in, ios::binary);

	int l = 0;
	do {
		plik.read((char*)bufor + l, sizeof(char)); //wczytanie kolejnych blokow do tymczasowej zmiennej
		if ((int)bufor[l] != -52) ++l; //sprawdzenie warunku poprawnoœci odczytanego bloku i indeksowanie kolejnych danych w pliku binarnym
	} while (!plik.eof());

	for (int i = 0; i < l; i++) {
		elem = (int)bufor[i]; //konwersja
		elem >> tablica;  //wczytanie do tablicy
	}
		plik.close();
}
void Zapisz_BIN(queue<int> tablica) {
	string nazwa;
	char bufor[256];
	fstream plik;

	cout << endl << "Podaj nazwê pliku:" << endl;
	cin >> nazwa;

	plik.open(nazwa, ios::out, ios::binary);

	int i = 0;
	while (!tablica.empty()) {
		bufor[i] = (char)tablica.front();  //przygotowanie buforu do zapisu
		tablica.pop();
		i++;
	}

	if (plik.good() == true) {
		for (i = 0; i < sizeof(bufor); i++) //indeksowanie kolejnych blokow danych w buforze
			plik.write((char*)bufor + i, sizeof(char)); //zapisywanie kolejnych blokow danych z bufora do pliku binarnego
	}
	plik.close();
}
void Wypelnij_Losowo(queue<int> &tablica) {
	int ile, elem;

	if (!tablica.empty()) do tablica.pop(); while (!tablica.empty()); //czyszczenie tablicy w pamieci przed wczytaniem nowej

	cout << endl << "Podaj iloœæ losowych liczb w tablicy:" << endl;
	cin >> ile;
	while (ile>0) {
		ile--;
		elem = rand(); //losowanie liczby
		elem >> tablica; //wczytanie liczby do tablicy
	}
}
queue<int> * Kopia(queue<int> tablica) {
	if (tablica.size() == NULL) { cout << "Tablica jest pusta!" << endl; return NULL; }
	queue<int> *kopia = &tablica;
	Wyswietl_Konsola(*kopia);
	return kopia;
}
istream & operator >> (istream &wej, queue<int> &L) {
	int elem;
	wej >> elem;
	L.push(elem);
	return wej;
}

void operator >> (int &elem, queue<int> &L) {
	L.push(elem);
}

ostream & operator << (ostream &wyj, queue<int> L) {
    queue<int> kopia_L;
	kopia_L = L;
    int elem;

	while (!kopia_L.empty()) {
		elem = kopia_L.front();
		cout << elem << endl;
		kopia_L.pop();
	}
	return wyj;
}

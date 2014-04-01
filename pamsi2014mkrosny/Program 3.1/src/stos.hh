#include <stack>
#include <iostream>

using namespace std;

void Dodaj_konsola(stack <int> &stos) {
	int element;
	cout << "__________________________________" << endl;
	cout << "Podaj element:" << endl;
	cin >> element;
	stos.push(element);
}

void Wyswietl_konsola(stack <int> stos) {
	int nr = 0;
	stack<int> temp, i; //i - do zamiany kolejnosci, temp - do wyswietlania w odpowiedniej kolejnosci
	i = stos;
	cout << "__________________________________" << endl;
	cout << "Lista elementow w kolejnosci od pierwszego do ostatniego:" << endl;
	while (!i.empty()) {
		temp.push(i.top()); i.pop(); } //zamiana kolejnosci, od ostatniego do pierwszego -> pierwszy do ostatniego
	while (!temp.empty()) { nr++;  cout << "Element nr " << nr << ": " << temp.top() << endl; temp.pop(); }
	cout << endl;
}
void Wyszukaj(stack <int> stos) {
	int nr = 0;
	int ile = 0;
	int element;
	stack<int> i = stos; //do zamiany kolejnosci
	stack<int> temp; //do odpowiedniej kolejnosci i wyszukiwania
	cout << "__________________________________" << endl;
	cout << "Podaj element do wyszukwania" << endl;
	cin >> element;
	while (!i.empty()) {
		temp.push(i.top());
		i.pop(); } //zamiana kolejnosci, od ostatniego do pierwszego -> pierwszy do ostatniego
	while (!temp.empty()) {
		nr++;
		if (element==temp.top()) { cout << "Znaleziono szukany element na pozycji: " << nr << "." << endl;  ile++; }
		temp.pop();
	}
	cout << "Szukany element wyst¹pi³: " << ile << " razy." << endl;
}

bool Usun(stack <int> &stos) {
	int bufor;
	stack<int> temp = stos;
	stack<int> i;
	int wybor;
	cout << "__________________________________" << endl;
	cout << "Czy chcesz usunac konkretny element? (2-tak/3-nie):" << endl;
	cin >> wybor;
	if (wybor == 2) {
		while (!stos.empty()) { stos.pop(); } //czyszczenie stosu przed zapisem w jego miejsce nowego, bez usuwanego elementu
		cout << "Podaj element do usuniecia: " << endl;
		cin >> wybor;
		while (!temp.empty()) { //przeszukiwanie tymczasowego stosu
			bufor = temp.top();
			temp.pop();
			if (wybor != bufor) i.push(bufor); //zapisujemy nowy tymczasowy stos, bez usuwanego elementu
		}
		while (!i.empty()) { stos.push(i.top()); i.pop(); } //zamiana kolejnosci na nieprawidlowa, dla poprawnosci funkcji wyswietl_stos
	return true;
	}
	if (wybor == 3) cout << "Czy chcesz usunac wszystkie elementy? (2-tak/3-nie):" << endl;
	cin >> wybor;
	if (wybor == 2) { while (!stos.empty()) stos.pop(); }
	if (wybor == 3) cout << "Przerwano usuwanie elementow." << endl;
	return true;
}
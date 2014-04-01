#include <queue>
#include <iostream>

using namespace std;

void Dodaj_koniec(queue <int> &kolejka) {
	int element;
	cout << "__________________________________" << endl;
	cout << "Podaj element:" << endl;
	cin >> element;
	kolejka.push(element);
}

void Usun_poczatek(queue <int> &kolejka) {
	if (kolejka.empty()) cout << "Kolejka jest pusta!" << endl;
	else {
		int element = kolejka.front(); kolejka.pop();
		cout << "Usuniêto element:\t" << element << endl; }
}

void Dlugosc(queue <int> kolejka) {
	cout << "Dlugosc kolejki:\t" << kolejka.size() << endl;
}

#include "funkcje_menu.h"

using namespace std;

void menu_stos()
{
	cout << endl << "******\tTESTOWANIE STOSU\t******" << endl;

	Stos<int> moj;

	cout << "Czy pusty\t" << moj.czy_pusty() << endl;
	moj.dodaj(5).dodaj(6).dodaj(7).dodaj(8);
	cout << "Wyswietlanie po dodaniu elementow\t"; moj.wyswietl();
	cout << "Co na wierzchu\t" << moj.top() << endl;
	cout << "Czy pusty\t" << moj.czy_pusty() << endl;
	cout << "Rozmiar\t" << moj.rozmiar() << endl;
	moj.wyrzuc();
	cout << "Po wyrzuceniu elementu\t";  moj.wyswietl();
	cout << "Czy jest '5'\t" << moj.szukaj(5) << endl << "Czy jest '1'\t" << moj.szukaj(1) << endl << endl;
}
/////////////////////////////////////////////////////////////////////////
void menu_kopiec()
{
	cout << endl << "******\tTESTOWANIE KOPCA\t******" << endl;

	Kopiec<int> moj(15);

	cout << "Wyswietlanie Kopca" << endl;  
	moj.wyswietl();
	moj.usun_pierwszy();
	cout << "Po usunieciu pierwszego elementu" << endl;
	moj.wyswietl();
}
/////////////////////////////////////////////////////////////////////////
void menu_kolejka()
{
	cout << endl << "******\tTESTOWANIE KOLEJKI\t******" << endl;

	Kolejka<int> moja;

	moja.dodaj(10).dodaj(12).dodaj(17).dodaj(4);
	cout << "Rozmiar kolejki po dodaniu kilku elementow\t" << moja.rozmiar() << endl;
	cout << "Wyjmujemy pierwszy element\t" << moja.wez_element() << endl;
	cout << "Teraz rozmiar\t" << moja.rozmiar() << endl;

}
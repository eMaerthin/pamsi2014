#ifndef KOLEJKA_HH
#define KOLEJKA_HH

//Klasa pojemnikowa typu kolejka

#include <iostream>
#include <queue>

//Klasa pojemnikowa typu kolejka
//Wykorzysywana jest klasa pojemnikowa queue z biblioteki standardowej.
//*****************************************************************************************************
template <class TYP>
class Kolejka{
	std::queue<TYP> moja_kolejka;

public:

	//Dodawanie elementu na koniec kolejki
	Kolejka& dodaj(const TYP& nowy)
	{
		moja_kolejka.push(nowy);
		return *this;
	}
	/////////////////////////////////////////////////////////////////////////
	//Pobieranie elementu z poczatku kolejki. Zwracana jest jego wartosc i wyrzucany jest z kolejki.
	TYP wez_element()
	{
		TYP pierwszy_ele = moja_kolejka.front();
		moja_kolejka.pop();

		return pierwszy_ele;
	}
	/////////////////////////////////////////////////////////////////////////
	//Podawany jest rozmiar kolejki
	int rozmiar()
	{
		return moja_kolejka.size();
	}
	/////////////////////////////////////////////////////////////////////////

};
//*****************************************************************************************************

#endif
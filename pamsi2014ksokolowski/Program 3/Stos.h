#ifndef STOS_HH
#define STOS_HH

//Klasa pojemnikowa typu Stos

#include <iostream>
#include <stack>
#include <algorithm>

//Klasa pojemnikowa typu Stos
//Wzkorzystywane jest klasa stock
//*****************************************************************************************************
template <class TYP>
class Stos {
	std::stack<TYP> stosik;

public:

	//Informacja czy stos jest pusty. Jezeli tak to TRUE 
	bool czy_pusty() const
	{
		return stosik.empty();
	}
	/////////////////////////////////////////////////////////////////////////
	//Podanie rozmiaru stosu
	int rozmiar() const
	{
		return stosik.size();
	}
	/////////////////////////////////////////////////////////////////////////
	//Podanie elementu z gory stosu
	TYP& top()
	{
		return stosik.top();
	}
	/////////////////////////////////////////////////////////////////////////
	//Dodawanie elementu ta gore stosu
	Stos& dodaj(const TYP& element)
	{
		stosik.push(element);
		return *this;
	}
	/////////////////////////////////////////////////////////////////////////
	//Wyrzucanie elementu z gory stosu
	Stos& wyrzuc()
	{
		stosik.pop();
		return *this;
	}
	/////////////////////////////////////////////////////////////////////////
	//Wyswietlanie zawartosci stosu
	void wyswietl() const
	{
		std::stack<TYP> schowek(stosik);

		std::cout << endl;
		while (!schowek.empty()){
			std::cout << schowek.top() << " ";
			schowek.pop();
		}
		std::cout << endl;
	}
	/////////////////////////////////////////////////////////////////////////
	//Informacja o tym czy element znajduje sie w stosie. Je¿eli jest to TRUE
	bool szukaj(const TYP& element) const
	{
		std::stack<TYP> schowek(stosik);

		while (!schowek.empty()){
			if (element == schowek.top()) return true;

			schowek.pop();
		}
		return false;
	}


};
//*****************************************************************************************************

#endif
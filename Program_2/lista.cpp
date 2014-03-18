#include <iostream>

using namespace std;

// deklaracja typu elementu listy
//-------------------------------

struct Element
{
	Element * next;
	int key;
};


// deklaracja typu klasy listy jednokierunkowej
//---------------------------------------------

class Lista
{
private:

	Element * poczatek, *koniec;
	unsigned licz;

public:

	// konstruktor
	//------------

	Lista()
	{
		poczatek = koniec = NULL;
		licz = 0;
	}

	// destruktor
	//-----------

	~Lista()
	{
		Element * p;

		while (poczatek)
		{
			p = poczatek->next;
			delete poczatek;
			poczatek = p;
		}
	}

	// Zwraca d³ugoœæ listy
	//---------------------

	unsigned size()
	{
		return licz;
	}

	// Dodaje element na pocz¹tku listy i zwraca jego adres
	//-----------------------------------------------------

	Element * push_poczatek(Element * p)
	{
		p->next = poczatek;
		poczatek = p;
		if (!koniec) koniec = poczatek;
		licz++;
		return poczatek;
	}

	// Dodaje element na koñcu listy i zwraca jego adres
	//--------------------------------------------------

	Element * push_koniec(Element * p)
	{
		if (koniec) koniec->next = p;
		p->next = NULL;
		koniec = p;
		if (!poczatek) poczatek = koniec;
		licz++;
		return koniec;
	}


	// Usuwa element z pocz¹tku listy i zwraca adres usuniêtego elementu
	//------------------------------------------------------------------

	Element * pop_poczatek()
	{
		Element * p;

		if (poczatek)
		{
			p = poczatek;
			poczatek = poczatek->next;
			if (!poczatek) koniec = NULL;
			licz--;
			return p;
		}
		else return NULL;
	}

	// Usuwa element z koñca listy i zwraca adres usuniêtego elementu
	//---------------------------------------------------------------

	Element * pop_koniec()
	{
		Element * p;

		if (koniec)
		{
			p = koniec;
			if (p == poczatek) poczatek = koniec = NULL;
			else
			{
				koniec = poczatek;
				while (koniec->next != p) koniec = koniec->next;
				koniec->next = NULL;
			}
			licz--;
			return p;
		}
		else return NULL;
	}

	// Wyœwietla liste
	//----------------------------------------------------

	void Wyswietl()
	{
		Element * p;

		if (!poczatek) cout << "Lista jest pusta." << endl;
		else
		{
			p = poczatek;
			while (p)
			{
				cout << p->key << " ";
				p = p->next;
			}
			cout << endl;
		}
	}

	//************************************************************************
	//**     Przyk³adowa funkcja testuj¹ca liste                            **
	//************************************************************************

	int Testuj()
	{
		Lista    sl;
		Element * p;
		int            i;

		cout << "(A) : "; sl.Wyswietl();

		// tworzymy piêæ elementów dodaj¹c je kolejna na pocz¹tek listy

		for (i = 1; i <= 5; i++)
		{
			p = new Element;
			p->key = i;
			sl.push_poczatek(p);
		}

		cout << "(B) : ";   sl.Wyswietl();

		// tworzymy piêæ elementów dodaj¹c je kolejna na koniec listy

		for (i = 1; i <= 5; i++)
		{
			p = new Element;
			p->key = i;
			sl.push_koniec(p);
		}

		cout << "(C) : ";   sl.Wyswietl();

		// usuwamy pierwszy element listy

		sl.pop_poczatek();

		cout << "(D) : ";   sl.Wyswietl();

		// usuwamy ostatni element listy

		sl.pop_koniec();

		cout << "(E) : ";   sl.Wyswietl();

		cout << endl << endl;


		return 0;
	}


};




int main()
{
	Lista l;
	Element * p;
	int i = 0, k;
	while (i != 1)
	{
		cout << "\n******************M E N U**************\n";
		cout << "1.Poloz na poczatek\n2. Poloz na koniec\n3.Sciagnij z poczatku\n4. Sciagnij z konca\n5.Wyswietl\n6. Testuj program\n7.Koniec\n";
		cout << "\n***************************************\n";
		cout << "\nWybierz opcje ";
		cin >> k;
		switch (k)
		{
		case 1: 
			cout << "Podaj liczbe: " << endl;
			cin >> i;
			p = new Element;
			p->key = i;
			l.push_poczatek(p);
			break;
		case 2:
			cout << "Podaj liczbe: " << endl;
			cin >> i;
			p = new Element;
			p->key = i;
			l.push_koniec(p);
			break;
		case 3: l.pop_poczatek();
			break;
		case 4: l.pop_koniec();
		case 5: l.Wyswietl();
			break;
		case 6: l.Testuj();
			break;
		case 7: i = 1;
			break;
		default: cout << "\n------- Zla opcja -------\n";
			break;
		}
	} return 0;
}


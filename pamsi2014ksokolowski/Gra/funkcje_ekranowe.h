#ifndef FUNKCJE_EKRANOWE_H
#define FUNKCJE_EKRANOWE_H

#include <GL/glut.h>
#include <conio.h>
#include <stdio.h>
#include <stdarg.h>
#include <iomanip>

#include <boost/thread/thread.hpp>
#include "Postac.h"

enum
{
	EXIT1 // wyj�cie z gry
};

// funkcja generuj�ca scen� 3D
void Display();
// obs�uga klawiszy funkcyjnych i klawiszy kursora
void SpecialKeys(int key, int x, int y);
// obs�uga menu podr�cznego
void Menu(int value);
//Obs�uga bezczynnosci w programie - automatyczny ruch graczy
void bezczynnosc();
//rysowanie krawedzi planszy
void rysujPlansze();
//Wyswietlenie wyniku
void wypiszZwyciezceIZakonczGre(const std::string& nazwa);

#endif
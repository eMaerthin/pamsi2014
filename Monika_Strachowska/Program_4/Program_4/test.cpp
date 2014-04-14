#define BOOST_TEST_MAIN
//#define BOOST_TEST_MODULE Hello
#include <boost/test/included/unit_test.hpp>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

int dodaj( int i, int j )
{
    return i + j;
}

BOOST_AUTO_TEST_CASE( testDodaj )
{
    BOOST_CHECK( dodaj( 2, 2 ) == 4 );
	system("PAUSE");
	
}


//Utworzony tylko w celu sprawdzenia czy zrozumiale
//sa testy jednostkowe dla autora 
BOOST_AUTO_TEST_CASE( testGetteraRozkladu ) 
{
	BubbleSort BS;
	BS.setRozklad(6);
	BOOST_CHECK( BS.getRozklad() == 6 );
	system("PAUSE");
}

BOOST_AUTO_TEST_CASE( testUporzadkowaniaTablicyBS ) 
{
	BubbleSort BS;
	int tablicaDoPorownania[10];
	int tablicaDoKlasy[10];
	for(int i = 0; i < 10; i++) {
		tablicaDoPorownania[i] = i + 1;
		tablicaDoKlasy[i] = 10 - i;
	}
	BS.tablica = tablicaDoKlasy;
	BS.rozmiar = 10;
	BS.algorytmBS();
	int flaga = 1; // = 0 -> nie sa takie same; = 1 -> sa takie same
	for(int i = 0; i < 10; i++)
		if(tablicaDoPorownania[i] != tablicaDoKlasy[i]) {
			flaga = 0;
			break;
		}
	BOOST_CHECK( flaga == 1 );
	system("PAUSE");
}

BOOST_AUTO_TEST_CASE( testUporzadkowaniaTablicySS ) 
{
	ShellSort SS;
	int tablicaDoPorownania[10];
	int tablicaDoKlasy[10];
	for(int i = 0; i < 10; i++) {
		tablicaDoPorownania[i] = i + 1;
		tablicaDoKlasy[i] = 10 - i;
	}
	SS.tablica = tablicaDoKlasy;
	SS.rozmiar = 10;
	SS.algorytmSS();
	int flaga = 1; // = 0 -> nie sa takie same; = 1 -> sa takie same
	for(int i = 0; i < 10; i++)
		if(tablicaDoPorownania[i] != tablicaDoKlasy[i]) {
			flaga = 0;
			break;
		}
	BOOST_CHECK( flaga == 1 );
	system("PAUSE");
}

BOOST_AUTO_TEST_CASE( testUporzadkowaniaTablicyQS ) 
{
	QuickSort QS;
	int tablicaDoPorownania[10];
	int tablicaDoKlasy[10];
	for(int i = 0; i < 10; i++) {
		tablicaDoPorownania[i] = i + 1;
		tablicaDoKlasy[i] = 10 - i;
	}
	QS.tablica = tablicaDoKlasy;
	QS.rozmiar = 10;
	QS.algorytmQS(0,10-1);
	int flaga = 1; // = 0 -> nie sa takie same; = 1 -> sa takie same
	for(int i = 0; i < 10; i++)
		if(tablicaDoPorownania[i] != tablicaDoKlasy[i]) {
			flaga = 0;
			break;
		}
	BOOST_CHECK( flaga == 1 );
	system("PAUSE");
}
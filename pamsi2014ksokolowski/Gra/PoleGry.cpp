#include "PoleGry.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////////
void PoleGry::zmienWsp(int x, int y, short wartosc)
{
	if (x > 39 || x < -39 || y > 39 || y < -39) {
		cout << "Bledna Wspolrzedna do zmiany Pola "  << x << " " << y << endl;
		return;
	}
	if (wartosc != 1 && wartosc != 0){
		cout << "Bledna wartosc do zmiany Pola" << endl;
		return;
	}
	x += 39;
	y += 39;

	pole[x / 4][y / 4].zmienPole(x % 4,y % 4, wartosc);
}
/////////////////////////////////////////////////////////////////////////////////
void PoleGry::zmienWsp(const Wspolrzedne& wsp, short wartosc)
{
	zmienWsp(wsp.X, wsp.Y, wartosc);
}
/////////////////////////////////////////////////////////////////////////////////
short PoleGry::podajWart(int x, int y) const
{
	if (x > 39 || x < -39 || y > 39 || y < -39) {
		cout << "Bledna Wspolrzedna do zmiany Pola" << endl;
		return -1;
	}
	x += 39;
	y += 39;
	return pole[x / 4][y / 4].podajWartPola(x % 4, y % 4);
}
/////////////////////////////////////////////////////////////////////////////////
short PoleGry::podajWart(const Wspolrzedne& wsp) const
{
	return podajWart(wsp.X, wsp.Y);
}
/////////////////////////////////////////////////////////////////////////////////
int PoleGry::wagaPolaczenia(short w_p, short k_p, short w_d, short k_d) const
{
	int waga = stala;

	//sprawdzenie czy poprawnie podano argoumenty
	if (w_p >= _rozm || k_p >= _rozm || w_d >= _rozm || k_d >= _rozm) {
		cout << "Bledne podane wspolrzedne ktoregos z kafelkow!" << endl;
		return INF_;
	}
	if (abs(w_p - w_d) > 1 && abs(k_p - k_d) > 1){
		cout << "Podane kafelki nie leza obok siebie!" << endl;
		return INF_;
	}
	
	//sprawdzenie z ktorej strony jest polaczenie i zmiana wartosci zmiennej 'waga'
	if (w_p - w_d < 0){ //pierszy znajduje sie nad drugim
		waga -= 2 * pole[w_d][k_d]._G1() * 2 * pole[w_d][k_d]._G1() + pole[w_d][k_d]._G2()*pole[w_d][k_d]._G2();
		if (pole[w_d][k_d]._G1() == 0) return INF_;
	}
	if (w_p - w_d > 0){ //odwrotna sytuacja
		waga -= 2 * pole[w_d][k_d]._D1() * 2 * pole[w_d][k_d]._D1() + pole[w_d][k_d]._D2()*pole[w_d][k_d]._D2();
		if (pole[w_d][k_d]._D1() == 0) return INF_;
	}

	if (k_p - k_d < 0){ //pierwszy jest po lewej stronie
		waga -= 2 * pole[w_d][k_d]._L1() * 2 * pole[w_d][k_d]._L1() + pole[w_d][k_d]._L2()*pole[w_d][k_d]._L2();
		if (pole[w_d][k_d]._L1() == 0) return INF_;
	}
	if (k_p - k_d > 0){ //odwrotna sytuacja
		waga -= 2 * pole[w_d][k_d]._P1() * 2 * pole[w_d][k_d]._P1() + pole[w_d][k_d]._P2()*pole[w_d][k_d]._P2();
		if (pole[w_d][k_d]._P1() == 0) return INF_;
	}

	return waga - pole[w_d][k_d].wolnePola();
}
/////////////////////////////////////////////////////////////////////////////////
int PoleGry::wagaPolaczenia(short p_kafelek, short d_kafelek) const
{
	//sprawdzenie czy kafelki sa obok siebie
	if (abs(p_kafelek / _rozm - d_kafelek / _rozm) > 1 && abs(p_kafelek - d_kafelek) != 1){
		cout << "Podane kafelki: " << p_kafelek << " " << d_kafelek << " nie leza obok siebie!" << endl;
	}
	
	return wagaPolaczenia(p_kafelek / _rozm, p_kafelek%_rozm, d_kafelek / _rozm, d_kafelek%_rozm);
}


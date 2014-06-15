#include "Kafelek.h"


Kafelek::Kafelek()
{
	for (short i = 0; i < rozm_kaf; ++i)
		for (short j = 0; j < rozm_kaf; ++j)
			tab[i][j] = 0;
}
///////////////////////////////////////////////////////////
short Kafelek::_G1() const
{
	short licznik = rozm_kaf;

	for (short i = 0; i < rozm_kaf; ++i)
		if (tab[0][i] == 1) --licznik;

	return licznik;
}
///////////////////////////////////////////////////////////
short Kafelek::_G2() const
{
	short licznik = rozm_kaf;

	for (short i = 0; i < rozm_kaf; ++i)
		if (tab[1][i] == 1) --licznik;

	return licznik;
}
///////////////////////////////////////////////////////////
short Kafelek::_D1() const
{
	short licznik = rozm_kaf;

	for (short i = 0; i < rozm_kaf; ++i)
		if (tab[3][i] == 1) --licznik;

	return licznik;
}
///////////////////////////////////////////////////////////
short Kafelek::_D2() const
{
	short licznik = rozm_kaf;

	for (short i = 0; i < rozm_kaf; ++i)
		if (tab[2][i] == 1) --licznik;

	return licznik;
}
///////////////////////////////////////////////////////////
short Kafelek::_P1() const
{
	short licznik = rozm_kaf;

	for (short i = 0; i < rozm_kaf; ++i)
		if (tab[i][3] == 1) --licznik;

	return licznik;
}
///////////////////////////////////////////////////////////
short Kafelek::_P2() const
{
	short licznik = rozm_kaf;

	for (short i = 0; i < rozm_kaf; ++i)
		if (tab[i][2] == 1) --licznik;

	return licznik;
}
///////////////////////////////////////////////////////////
short Kafelek::_L1() const
{
	short licznik = rozm_kaf;

	for (short i = 0; i < rozm_kaf; ++i)
		if (tab[i][0] == 1) --licznik;

	return licznik;
}
///////////////////////////////////////////////////////////
short Kafelek::_L2() const
{
	short licznik = rozm_kaf;

	for (short i = 0; i < rozm_kaf; ++i)
		if (tab[i][1] == 1) --licznik;

	return licznik;
}
///////////////////////////////////////////////////////////
short Kafelek::wolnePola() const
{
	short licznik = rozm_kaf*rozm_kaf;

	for (short i = 0; i < rozm_kaf; ++i)
		for (short j = 0; j < rozm_kaf; ++j)
			if (tab[i][j] == 1) --licznik;

	return licznik;
}

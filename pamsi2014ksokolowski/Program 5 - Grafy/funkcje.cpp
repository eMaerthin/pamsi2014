#include "funkcje.hpp"

int silnia(int n)
{
	if (n == 0) return 1;
	else return n*silnia(n - 1);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double symbol_newtona(int g, int d)
{
	if (g < d) return 0;

	return (silnia(g) / (silnia(d)*silnia(g - d)));
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double wylosuj_prawdop_log2(int n)
{
	return (3 * log2(n) / n);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double wylosuj_prawdop_min2(int n)
{
	return (1/sqrt(n));
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double wylosuj_prawdop_min3(int n)
{
	return (1/cbrt(n));
}
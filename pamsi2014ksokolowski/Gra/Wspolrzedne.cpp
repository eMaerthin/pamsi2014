#include "Wspolrzedne.h"

Wspolrzedne Wspolrzedne::operator+(const Wspolrzedne& arg) const
{
	return Wspolrzedne(X + arg.X, Y + arg.Y);
}
/////////////////////////////////////////////////////////////////////////////
Wspolrzedne Wspolrzedne::operator-(const Wspolrzedne& arg) const
{
	return Wspolrzedne(X - arg.X, Y - arg.Y);
}
/////////////////////////////////////////////////////////////////////////////
bool Wspolrzedne::operator == (const Wspolrzedne& arg) const
{
	return (X == arg.X && Y == arg.Y);
}
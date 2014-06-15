#ifndef WSPOLRZEDNE_H
#define WSPOLRZEDNE_H

#include <limits>

#undef max //do zlikwidowania z bledem funkcji max w limits

const int INF_ = std::numeric_limits<int>::max();

//Przechowuje wspolrzedne
struct Wspolrzedne {
	int X;
	int Y;

	Wspolrzedne(int xx = INF_, int yy = INF_) : X(xx), Y(yy) {}

	void zmien_X(int wartosc = 1) { X += wartosc; }
	void zmien_Y(int wartosc = 1) { Y += wartosc; }
	void zmien(int x, int y) { X += x; Y += y; }
	void zmien(const Wspolrzedne& arg) { X += arg.X; Y += arg.Y; }

	Wspolrzedne operator+(const Wspolrzedne& arg) const;
	Wspolrzedne operator-(const Wspolrzedne& arg) const;

	bool operator==(const Wspolrzedne& arg) const;
};


#endif
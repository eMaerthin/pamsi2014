#pragma once
class Tablica
{
public:
	int *tablica;
	int rozmiar;
	int rozklad;
	int uporzadkowanie;
	Tablica(void);
	~Tablica(void);
	void setRozmiar(int rozmiar1);
	int getRozmiar(void);
	void setRozklad(int rozklad1);
	int getRozklad(void);
	void setUporzadkowanie(int uporzadkowanie1);
	int getUporzadkowanie(void);
	void wyswietlanieTablicy(void);
	void uzupelnianeTablicy(void);
	void wstepneSortowanie(void);
};


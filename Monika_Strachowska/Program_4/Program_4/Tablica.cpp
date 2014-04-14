#include "Tablica.h"
#include "QuickSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include <iostream>
#include <random>
#include <cmath>
#include <fstream>
#include <boost\random\normal_distribution.hpp>
#include <boost\random\poisson_distribution.hpp>
#include <boost\random\uniform_real_distribution.hpp>

using namespace std;


Tablica::Tablica(void)
{
}


Tablica::~Tablica(void)
{
}


void Tablica::setRozmiar(int rozmiar1)
{
	rozmiar = rozmiar1;
}


int Tablica::getRozmiar(void)
{
	return rozmiar;
}


void Tablica::setRozklad(int rozklad1)
{
	rozklad = rozklad1;
}


int Tablica::getRozklad(void)
{
	return rozklad;
}


void Tablica::setUporzadkowanie(int uporzadkowanie1)
{
	uporzadkowanie = uporzadkowanie1;
}


int Tablica::getUporzadkowanie(void)
{
	return uporzadkowanie;
}

void Tablica::wyswietlanieTablicy(void)
{
	for(int i = 0; i < rozmiar; i++)
		cout << tablica[i] << " ";
	cout << endl;
	/*fstream plik("wyniki.txt", ios::out | ios::app);
	plik << rozmiar << " "<< uporzadkowanie << " "<< rozklad << endl;
	for(int i = 0; i < rozmiar; i++)
		plik << tablica[i] << " ";
	plik << endl;*/
}


void Tablica::uzupelnianeTablicy(void)
{
	for(int i = 0; i < rozmiar; i++) tablica[i] = 0;
	default_random_engine generator;
	//rozklad jednostajny
	if(rozklad == 0) {
		mt19937 rng;
		for(int i = 0; i < rozmiar; i++) {
			uniform_real_distribution<> unif_dist(0.0,1.0);
			variate_generator<mt19937&, uniform_real_distribution<>> unif_sampler(rng, unif_dist);
			tablica[i] = (int)(unif_sampler() * 10);
		}
	}
	//rozkald normalny
	else if(rozklad == 1) {
		mt19937 rng;
		for(int i = 0; i < rozmiar; i++) {
			normal_distribution<> norm_dist(0.0,5.0);
			variate_generator<mt19937&, normal_distribution<>> normal_sampler(rng, norm_dist);
			tablica[i] = (int)(normal_sampler() * 10);
		}
	}
	//rozklad poissona
	else if(rozklad == 2) {
		mt19937 gen;
		for(int i = 0; i < rozmiar; i++) {
			poisson_distribution<> pois_dist(1.0);
			variate_generator<mt19937&, poisson_distribution<>> poisson_sampler(gen, pois_dist);
			tablica[i] = poisson_sampler() * 10;
		}
	}
}


void Tablica::wstepneSortowanie(void) 
{
	double procent = 0;
	if(uporzadkowanie == 0) procent = 0;
	else if(uporzadkowanie == 1) procent = 0.1;
	else if(uporzadkowanie == 2) procent = 0.5;
	else if(uporzadkowanie == 3) procent = 0.9;
	algorytmT(0,(int)(floor(rozmiar - (rozmiar * procent))-1));
}


void Tablica::algorytmT(int lewy, int prawy)
{
	int i = lewy, j = prawy + 1;
	int temp, v = tablica[lewy];
	do {
		do {
			++i;
		} while (tablica[i] < v);
		do {
			--j;
		} while (tablica[j] > v);
		if (i < j)
		{
			temp = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = temp;
		}
	} while (j > i);
	tablica[lewy] = tablica[j];
	tablica[j] = v;
	if (j - 1 > lewy) {
		algorytmT(lewy, j - 1);
	}
	if (prawy > j + 1)	{
		algorytmT(j + 1, prawy);
	}
}


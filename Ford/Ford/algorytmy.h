#include "stdafx.h"

// Dijkstra
int* dijkstra(lista **L, int ile_w, int *poprzednie);
int* dijkstra(int **M, int ile_w, int *poprzednie);
int min_sciezka(int *tab, int *tab2, int ile_w);

//Bell Ford
int* bell_Ford(lista **L, int ile_w, int *poprzednie);
int* bell_Ford(int** M, int ile_w, int *poprzednie);
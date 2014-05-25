//
//  kruskal.h
//  PAMSI_testy
//
//  Created by Adrian Bykowski on 29.04.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#ifndef __PAMSI_testy__kruskal__
#define __PAMSI_testy__kruskal__

#include <iostream>
#include "Graf.h"
#include <vector>
#include <list>
typedef std::list<Graf> _drzewo_lista;
int Kruskal(Graf & test, int & _ilosc_drzew, std::vector<_drzewo_lista> & drzewo);
void AlgorytmK(std::vector<std::list<Graf>> & drzewo,std::vector<Graf> & tab,int & roz);
#endif /* defined(__PAMSI_testy__kruskal__) */

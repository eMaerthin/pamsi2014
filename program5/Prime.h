//
//  Prime.h
//  PAMSI_testy
//
//  Created by Adrian Bykowski on 29.04.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#ifndef __PAMSI_testy__Prime__
#define __PAMSI_testy__Prime__

#include <iostream>
#include <iostream>
#include <list>
#include <vector>
#include "Graf.h"
#include "kruskal.h"
void CzyNalezyPrime(std::list<Graf>& _elementy, std::vector<Graf>& tab, int _wezlel, int & roz, std::vector<_drzewo_lista> & _drzewo);
void CzyszczenieListy(std::list<Graf>& _elementy,std::vector<_drzewo_lista> & _drzewo);
void DodawanieWezlow(std::list<Graf> & _elementy, std::list<int> & _wezly, int & wezel);
void AlgorytmP(std::vector<_drzewo_lista> & _drzewo, std::vector<Graf>& tab, int & roz);
#endif /* defined(__PAMSI_testy__Prime__) */

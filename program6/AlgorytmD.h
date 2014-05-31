//
//  AlgorytmD.h
//  PAMSI2014_6
//
//  Created by Adrian Bykowski on 29.05.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#ifndef __PAMSI2014_6__AlgorytmD__
#define __PAMSI2014_6__AlgorytmD__

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "Graf.h"

void WyswietlanieW(std::vector<int> &W, std::vector<std::list<int>> droga);
void AlgorytmD(std::vector<Graf>& G, std::vector<int>&W, int & N, std::vector<std::list<int>> & droga);
#endif /* defined(__PAMSI2014_6__AlgorytmD__) */

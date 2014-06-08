//
//  AlgorytmEK.h
//  PAMSI2014_7
//
//  Created by Adrian Bykowski on 08.06.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#ifndef __PAMSI2014_7__AlgorytmEK__
#define __PAMSI2014_7__AlgorytmEK__

#include <iostream>
#include <vector>
#include "Edge.h"
#include <list>
std::list<Edge*>  bfs (int s, int e, std::vector<Edge> & Graf, int & N);
int AlgorytmEK( std::vector<Edge> & Graf,int &e, int &s , int & N);
#endif /* defined(__PAMSI2014_7__AlgorytmEK__) */

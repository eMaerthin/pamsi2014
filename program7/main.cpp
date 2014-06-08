 //
//  main.cpp
//  PAMSI2014_7
//
//  Created by Adrian Bykowski on 03.06.2014.
//  Copyright (c) 2014 Adrian Bykowski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include "Edge.h"
#include <list>
#include <fstream>
#include "AlgorytmEK.h"
std::vector<int> prev (15000);


inline int min(int a, int b) { return a < b ? a : b; }




int main(int argc, const char * argv[])
{
    // zmienne
    int flow,e,s,opcja,N;
    std::vector<Edge> G;
    float t,wynik(0);
    std::fstream plik;
   // bool koniec;
    //wybor menu
    std::cout<< "Wybierz Algorytm \n 1. Ford - Fulkunson\n 2. ?\n";
    std::cin>>opcja;

    
    //for(opcja = 1; opcja == 2 ; opcja++){
   /* switch(opcja){
        case 1: {
            koniec = false;
            std::cout << "Ford-Fulkonson\n \n";
            //while(!koniec){
                // wczytywanie z pliku*/
                wczytywaniezpliku("/Users/rhyre_Mac/Desktop/grafy/2k100-35.txt", G, plik, e,s,N);
                t=clock();
                flow = AlgorytmEK(G,e,s,N);
                t=clock()-t;
                wynik=t/CLOCKS_PER_SEC;
                std::cout <<"czas usredniony : "<< std::setprecision(5) << std::fixed << wynik <<std::endl;
                std::cout << "Najwiekszy przeplyw w grafie wynosi : "<< flow << std::endl;
                flow = 0; G.clear(); prev.clear(); prev.resize(16000);
    

                /*//}
            break;
        }
        case 2:{
            break;
        }
        default: {std::cout<<"Zla opcja\n"; break;}
            // }*/
  //  }
    

   // std::cout << "Najwiekszy przeplyw w grafie wynosi : "<< flow << std::endl;
    std::cout << "Hello, World!\n";
    return 0;
}


//#define FOR_EACH( it, container ) for( typeof((container).begin()) it = (container).begin(); it != (container).end(); it++ )

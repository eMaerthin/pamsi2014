//autor: Marcin Ochocki 200330
//Kompilacja w standardzie C++0x ISO C++
//Warcaby - w trybie jednoosobowym (sztuczna inteligencja) i wieloosobowym
#include "interfejs.h"

int main() {
  interfejs gra;
  int typ,wygrany;
  do {
    cout << endl << " Wybierz rodzaj gry "
         << endl << " 1 - single player"
         << endl << " 2 - multiplayer"
         << endl << " Twoj wybor: ";
    cin >> typ;
  } while(typ<1 || typ>2);
  wygrany=gra.rozgrywka(typ);
  if(typ==1) {
    if(wygrany==1)
      cout << endl << "       --------------------------------- WYGRALES :> ----------------------------------" << endl;
    else
      cout << endl << "       -------------------------------- PRZEGRALES :< ---------------------------------" << endl;
  }
  else {
    if(wygrany==1)
      cout << endl << "       -------------------------------- WYGRAL GRACZ A --------------------------------" << endl;
    else
      cout << endl << "       -------------------------------- WYGRAL GRACZ B --------------------------------" << endl;
  }
  return 0;
}

#include "Game.h"
#include "Interface.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
	int first = 0;
	int second = 1;
	srand(time(NULL));
	Interface i;
	i.startNewGame(first, second); // rozpoczyna gr? z 1 graczem komputerowym (gracz typu random) oraz z 1 ludzkim graczem
	i.whoPlay(first, second);
	return 0;

}
#pragma once
#include "Game.h"

class Interface
{
	Game _game;
	int _firstCPU; // 0 means Human Player
	int _secondCPU; // 0 means Human Player
public:
	int _fields[64];
	Interface();
	void startNewGame(int firstCPU, int secondCPU);
	void printGameTable();
	void CPUmove(int lvl);
	int minimax(int* fields, int player, int glebokosc);
	int minimax2(int* fields, int player, int glebokosc);
	int whoPlay(int first, int second);
};
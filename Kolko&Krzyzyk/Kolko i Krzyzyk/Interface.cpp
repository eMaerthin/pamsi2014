#include "Interface.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
Interface::Interface()
{
}

int minimax(int board[64], int player) {
	//How is the position like for player (their turn) on board?
	int winner = 0;
	if (winner != 0) return winner*player;

	int move = -1;
	int score = -2;//Losing moves are preferred to no move
	int i;
	for (i = 0; i < 64; ++i) {//For all moves,
		if (board[i] == 0) {//If legal,
			board[i] = player;//Try the move
			int thisScore = -minimax(board, player*-1);
			if (thisScore > score) {
				score = thisScore;
				move = i;
			}//Pick the one that's worst for the opponent
			board[i] = 0;//Reset board after try
		}
	}
	if (move == -1) return 0;
	return score;
}

void computerMove(int board[64]) {
	int move = -1;
	int score = -2;
	int i;
	for (i = 0; i < 64; ++i) {
		if (board[i] == 0) {
			board[i] = 1;
			int tempScore = -minimax(board, -1);
			board[i] = 0;
			if (tempScore > score) {
				score = tempScore;
				move = i;
			}
		}
	}
	//returns a score based on minimax tree at a given node.
	board[move] = 1;
}
void Interface::CPUmove(int lvl)
{
	if (lvl == 0)
		return;
	else if (lvl == 1)
	{
		while (!_game.makeMove(rand() % 64));
	}
	else
	{
		int bestMove;
		bestMove = minimax(_game._fields,_game.getPlayer());
		_game.makeMove(bestMove);
	}
}

void Interface::startNewGame(int firstCPU, int secondCPU)
{
	_game.resetTable();
	_firstCPU = firstCPU;
	_secondCPU = secondCPU;
	while (_game.getResult() == 0)
	{
		printGameTable();
		std::cout << _game.getPlayer() << " player's turn";
		if ((_game.getPlayer() == 1) && (_firstCPU > 0))
		{
			CPUmove(_firstCPU);
		}
		else if ((_game.getPlayer() == 2) && (_secondCPU >0))
		{
			CPUmove(_secondCPU);
		}
		else // ruch gracza typu HUMAN
		{
			std::cout << std::endl;
			int level;
			unsigned char row, column;
			std::string lvl;
			std::cout << "choose level [1-4]: " << std::endl;
			std::cin >> lvl;
			level = atoi(lvl.c_str());
			if (level<1) level = 1;
			if (level>4) level = 1;
			std::cout << "choose row [q-r]: " << std::endl;
			std::cin >> row;
			std::cout << "choose column [a-f]: " << std::endl;
			std::cin >> column;
			int level1, level2;
			switch (row)
			{
			case 'q': level1 = 0;
				break;
			case 'w': level1 = 1;
				break;
			case 'e': level1 = 2;
				break;
			case 'r': level1 = 3;
				break;
			default: level1 = 0;
			}
			switch (column)
			{
			case 'a': level2 = 0;
				break;
			case 's': level2 = 1;
				break;
			case 'd': level2 = 2;
				break;
			case 'f': level2 = 3;
				break;
			default: level2 = 0;
			}

			if (!_game.makeMove((level - 1) * 16 + level1 * 4 + level2))
			{
				std::cout << "An impossible move! " << std::endl;
			}
		}
	}
	printGameTable();
	std::cout << "Play again? [y/n]" << std::endl;
	char n;
	std::cin >> n;
	if (n == 'y') startNewGame(_firstCPU, _secondCPU);
	else std::cout << "Byebye! " << std::endl;
}

void Interface::printGameTable()
{
	_game.drawTable();
	std::cout << std::endl;
	std::cout << "game status: ";
	switch (_game.getResult())
	{
	case 0: std::cout << "Game is running";
		break;
	case 1: std::cout << "1st player won!";
		break;
	case 2: std::cout << "2nd player won!";
		break;
	case 3: std::cout << "DRAW!";
	}
	std::cout << std::endl;
}
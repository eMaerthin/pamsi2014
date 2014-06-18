#include "Interface.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
Interface::Interface()
{
}

int Interface::minimax(int fields[], int player, int glebokosc) 
{

	int min, max, k = 0;

	if (_game.getResult()  == 1)
		return (player == 1) ? 1 : -1;

	if (_game.getResult() == 2)
		return (player == 2) ? -1 : 1;
	
	if (_game.getResult() == 3)
		return 0;

	player = (player == 1) ? 2 : 1;

	max = (player == 2) ? 65 : -65;

	if (glebokosc < 2)
	{
		for (int i = 0; i < 64; i++)
		if (_game._fields[i] == 0)
		{
			_game._fields[i] = player;
			min = minimax(_game._fields, player, glebokosc + 1);
			_game._fields[i] = 0;
			if (((player == 2) && (min < max)) || ((player == 1) && (min > max)))
			{
				max = min;
			}
		}
	}
	return max;
}

int Interface::minimax2(int fields[], int player, int glebokosc)
{
	int min, max, k = 0;

	if (_game.getResult() == 2)
		return (player == 2) ? 1 : -1;

	if (_game.getResult() == 1)
		return (player == 1) ? -1 : 1;

	if (_game.getResult() == 3)
		return 0;

	player = (player == 2) ? 1 : 2;

	max = (player == 1) ? 65 : -65;

	if (glebokosc < 2)
	{
		for (int i = 0; i < 64; i++)
		if (_game._fields[i] == 0)
		{
			_game._fields[i] = player;
			min = minimax2(_game._fields, player, glebokosc + 1);
			_game._fields[i] = 0;
			if (((player == 1) && (min < max)) || ((player == 2) && (min > max)))
			{
				max = min;
			}
		}
	}
	return max;
}
void Interface::CPUmove(int lvl)
{	

	if (lvl == 0)
		return;
	else if (lvl == 1)
	{
		int bestMove = 0;
		int min;
		int max;
		min = -65;
		for (int i = 0; i < 64; i++)
		{

			if (_game._fields[i] == 0)
			{
				_game._fields[i] = _game.getPlayer();
				if (whoPlay(_game.getPlayer(), _game.getPlayer()) == 2)
					max = minimax2(_game._fields, _game.getPlayer(), 0);
				else
					max = minimax(_game._fields, _game.getPlayer(), 0);
				_game._fields[i] = 0;
				if (max > min)
				{
					min = max;
					bestMove = i;
				}
			}
		}
		if (!_game.makeMove(bestMove))
			_game.makeMove(rand() % 64);
	}
	else if ( lvl == 2)
	{
		int bestMove = 0;
		int min;
		int max;
		min = -65;
		for (int i = 0; i < 64; i++)
		{

			if (_game._fields[i] == 0)
			{
				_game._fields[i] = _game.getPlayer();
				if (whoPlay(_game.getPlayer(), _game.getPlayer()) == 2)
					max = minimax2(_game._fields, _game.getPlayer(), -1);
				else
					max = minimax(_game._fields, _game.getPlayer(), -1);
				_game._fields[i] = 0;
				if (max > min)
				{
					min = max;
					bestMove = i;
				}
			}
		}
		if(!_game.makeMove(bestMove))
            _game.makeMove(rand() % 64);
	}
	else
	{
		int bestMove = 0;
		int min;
		int max;
		min = -65;
		for (int i = 0; i < 64; i++)
		{

			if (_game._fields[i] == 0)
			{
				_game._fields[i] = _game.getPlayer();
				if (whoPlay(_game.getPlayer(), _game.getPlayer()) == 2)
					max = minimax2(_game._fields, _game.getPlayer(), 0);
				else
					max = minimax(_game._fields, _game.getPlayer(), -2);
				_game._fields[i] = 0;
				if (max > min)
				{
					min = max;
					bestMove = i;
				}
			}
		}
		if (!_game.makeMove(bestMove))
			_game.makeMove(rand() % 64);
	}
}

int Interface::whoPlay(int first, int second)
{
	if ((_game.getPlayer() == 1) && (first > 0))
	{
		return 1;
	}
	else if ((_game.getPlayer() == 2) && (second > 0))
	{
		return 2;
	}
	else
		return  0;
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
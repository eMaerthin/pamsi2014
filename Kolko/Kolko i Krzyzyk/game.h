#pragma once


class Game
{
	bool _firstPlayer;
	
public:
	int _fields[64]; // 0 - no move, 1 - player 1, 2 - player 2
	Game();
	int getResult(); // check if someone won; 0 - game is running, 1,2 - one's player victory, 3 - draw
	bool makeMove(int fieldId); // true - movement was available; false - movement was forbidden
	void resetTable(); // reset state of table
	void drawTable(); // drawing table with values of fields
	int getPlayer();

};
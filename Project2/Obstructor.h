#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include <Windows.h>

class Obstructor
{
private:
	int x, y;
	int SPEED;
	int key;
	std::string shape[6];
public:

	void setPos(int x, int y) { this->x = x; this->y = y; };
	void setSPEED(int SPEED) { this->SPEED = SPEED; };
	void setKey(int key) { this->key = key; };

	void loadImg(int key);

	int getX() { return x; };
	int getY() { return y; };

	void GoToXY(SHORT posX, SHORT posY)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD Position;
		Position.X = posX;
		Position.Y = posY;

		SetConsoleCursorPosition(hStdout, Position);
	}

	std::string T_Rex[6] =
	{"              / _)",    
	 "     _.----._/ /  ",  
	 "    /         /   ",       // 18     1
	 " __/  | |  | |    ",
	 "/__.-'|_|--|_|    " };
	std::string Truck[4] = {
	"      ____",
	" ____//_]|________",   // 18      2
	"(o _ |  -|   _  o|",
	" `(_)-------(_)--'"
	};
	std::string Duck[3] =
	{ "<6)_ ,/",
	  " (_==/ ",                // 7        3 
	  "  ='-  ", };
	std::string Car[4] = {
		"  ______ ",
		" /|_||_ \\\__",
		"( ___________\\",      //15        4
		"=`-(_)--(_)-'"
	};
};


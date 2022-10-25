#pragma once

#include "Console.h"
#include "CPEOPLE.h"
#include "Obstructor.h"


class CGAME
{
private:
	Console cons;
	CMAP map;
public:
	CPEOPLE people;
	Obstructor obs[6];
	
	void SetColor(int backgound_color, int text_color)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

		int color_code = backgound_color * 16 + text_color;
		SetConsoleTextAttribute(hStdout, color_code);
	}
	CGAME();

	void drawPeople();
	void movePeople();

	void drawMap();

	void drawObs(int key);
	void moveObs(int key);

	void GoToXY(SHORT posX, SHORT posY)
	{
		HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD Position;
		Position.X = posX;
		Position.Y = posY;

		SetConsoleCursorPosition(hStdout, Position);
	}
	void playgame();
};


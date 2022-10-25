#pragma once
#include<string>
#include <Windows.h>
#include <iostream>
#include <conio.h>
class CPEOPLE
{
private:
	int x, y;
	std::string shape[3] =
	{
		" o ",
		"/|\\",
		"/ \\",
	};

	bool isAlive;
public:
	CPEOPLE();

	void setPos(int x, int y) { this->x = x; this->y = y; };
	int getX() { return x; };
	int getY() { return y; };
	bool getState() { return isAlive; };
	std::string getShape(int key) { return shape[key]; };


	bool checkDead();

};


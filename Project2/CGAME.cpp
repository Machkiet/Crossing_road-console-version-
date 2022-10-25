#include "Header.h"

CGAME::CGAME()
{
	drawMap();
	SetColor(15, 2);
	for (int i = 0; i < 4; i++)
	{
		obs[i].loadImg(i + 1);
		drawObs(i + 1);
	}
	drawPeople();

}

void CGAME::drawObs(int key)
{
	switch (key)
	{
	case 1:
		for (int i = 0; i < 6; i++)
		{
			GoToXY(obs[key -1].getX(), obs[key - 1].getY() + i);
			std::cout << obs->T_Rex[i];
		}
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			GoToXY(obs[key - 1].getX(), obs[key - 1].getY() + i);
			std::cout << obs->Truck[i];
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{
			GoToXY(obs[key - 1].getX(), obs[key - 1].getY() + i);
			std::cout << obs->Duck[i];
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++)
		{
			GoToXY(obs[key - 1].getX(), obs[key -1].getY() + i);
			std::cout << obs->Car[i];
		}
		break;
	default:
		break;
	}
}

void CGAME::moveObs(int key)
{
	switch (key)
	{
	case 1:
		for (int i = 0; i < 6; i++)
		{
			GoToXY(obs[key - 1].getX(), obs[key - 1].getY()+ i);
			cout << "                  ";
		}
		if (obs[key - 1].getX() + 1 != 90 - 19)
			obs[key - 1].setPos(obs[key - 1].getX() + 1, obs[key - 1].getY());
		else
		{
			obs[key - 1].loadImg(key);
		}
		
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			GoToXY(obs[key - 1].getX(), obs[key - 1].getY() + i);
			cout << "                  ";
		}
		if (obs[key - 1].getX() - 1 != 1)
			obs[key - 1].setPos(obs[key - 1].getX() - 1, obs[key - 1].getY());
		else
		{
			obs[key - 1].loadImg(key);
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{
			GoToXY(obs[key - 1].getX(), obs[key - 1].getY() + i);
			cout << "       ";
		}
		if (obs[key - 1].getX() - 1 != 1)
			obs[key - 1].setPos(obs[key - 1].getX() - 1, obs[key - 1].getY());
		else
		{
			obs[key - 1].loadImg(key);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++)
		{
			GoToXY(obs[key - 1].getX(), obs[key - 1].getY() + i);
			cout << "               ";
		}
		if (obs[key - 1].getX() + 1 != 90 - 15 -1)
			obs[key - 1].setPos(obs[key - 1].getX() + 1, obs[key - 1].getY());
		else
		{
			obs[key - 1].loadImg(key);
		}
		break;
	default:
		break;
	}
}

void CGAME::drawMap()
{
	SetColor(3, 3);
	for (int i = 0; i < cons.getHeight(); i++)
	{
		if (i == 0 || i == cons.getHeight() - 1)
		{
			for (int k = 0; k < cons.getWidth(); k++)
			{
				GoToXY(k, i);
				cout << " ";
			}
		}
		else
		{
			GoToXY(0, i);
			cout << " ";
			GoToXY(cons.getWidth() * 3 / 4, i);
			cout << " ";
			GoToXY(cons.getWidth() - 1, i);
			cout << " ";
		}
	}
	SetColor(15, 0);
}
void CGAME::movePeople()
{
	char movekey = ' ';

	movekey = toupper(_getch());
	for (int i = 0; i < 3; i++)
	{
		GoToXY(people.getX(), people.getY() + i);
		cout << "   ";
	}
	if (movekey == 'A' && people.getX() - 1 > 0)
	{
		people.setPos(people.getX() - 1, people.getY());
	}
	else if (movekey == 'S' && people.getY() + 1 < main_game.cons.getHeight() - 3)
	{
		people.setPos(people.getX(), people.getY() + 1);
	}
	else if (movekey == 'D' && people.getX() + 1 < main_game.cons.getWidth() * 3 / 4 - 2)
	{
		people.setPos(people.getX() + 1, people.getY());
	}
	else if (movekey == 'W' && people.getY() - 1 > 0)
	{
		people.setPos(people.getX(), people.getY() - 1);
	}

}

void CGAME::drawPeople()
{
	for (int i = 0; i < 3; i++)
	{
		GoToXY(people.getX(), people.getY() + i);
		std::cout << people.getShape(i);
	}
}

#include "Obstructor.h"

void Obstructor::loadImg(int key)
{
	SPEED = 1;
	switch (key)
	{
	case 1:
		for (int i = 0; i < 6; i++)
		{
			shape[i] = T_Rex[i];
		}
		setPos(1, 26);
		break;
	case 2:
		for (int i = 0; i < 4; i++)
		{
			shape[i] = Truck[i];
		}
		setPos(90 - 18, 11);
		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{
			shape[i] = Duck[i];
		}
		setPos(90 - 8, 19);
		break;
	case 4:
		for (int i = 0; i < 4; i++)
		{
			shape[i] = Car[i];
		}
		setPos(1, 4);
		break;
	default:
		break;
	}
}




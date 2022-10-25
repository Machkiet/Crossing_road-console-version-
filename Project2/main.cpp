#include "Header.h"
CGAME main_game;
void threadFunc1()
{
	while (true)
	{
		main_game.movePeople();
		main_game.drawPeople();
	}
}

void threadFunc2()
{
	for (int i = 1; i <= 4; i++)
	{
		main_game.moveObs(i);
		main_game.drawObs(i);
	}
		Sleep(100);
}

int main()
{
	while (true)
	{
		if (_kbhit())
		{
			main_game.movePeople();
			main_game.drawPeople();
		}
		else
		{
			thread obstructor(threadFunc2);
			obstructor.join();
		}
	}

	system("pause");
	return 0;
}
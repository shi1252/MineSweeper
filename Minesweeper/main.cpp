#include "GameMap.h"
#include "GameUserMap.h"
#include "MyCursor.h"
#include "util.h"
#include <time.h>
#include <conio.h>
#include <Windows.h>

void main()
{
	time_t curTime, oldTime = clock();
	CGameMap gameMap(10, 10, 10);
	gameMap.Initmap();
	CGameUserMap gameUserMap(gameMap);
	CMyCursor cursor(gameMap.getWidth(), gameMap.getHeight());
	
	ScreenInit();

	bool isContinue = true;
	while (isContinue)
	{
		int nKey;
		if (_kbhit())
		{
			nKey = _getch();
			switch (nKey)
			{
			case UP:
				cursor.goUp();
				break;
			case DOWN:
				cursor.goDown();
				break;
			case LEFT:
				cursor.goLeft();
				break;
			case RIGHT:
				cursor.goRight();
				break;
			case SPACE:
				gameUserMap.open(gameMap, cursor.getX(), cursor.getY());
				cursor.setState(true);
				break;
			case F:
				gameUserMap.flag(cursor.getX(), cursor.getY());
				cursor.setState(true);
				break;
			}
		}
		ScreenClear();
		gameMap.draw();
		gameUserMap.draw(gameMap);
		cursor.draw();
		ScreenFlipping();

		if (gameUserMap.winCheck(gameMap) || gameUserMap.getLose())
			isContinue = false;

		while (1)
		{
			curTime = clock();
			if (curTime - oldTime > 33)
			{
				oldTime = curTime;
				break;
			}
		}
	}
	Sleep(3000);

	ScreenRelease();
}
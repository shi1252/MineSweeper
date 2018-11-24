#include "GameMap.h"
#include <time.h>
#include "util.h"
#include <iostream>

using namespace std;

CGameMap::~CGameMap()
{
	for (int y = 0; y < m_height; y++)
		delete[] m_map[y];
	delete[] m_map;
}

void CGameMap::Initmap()
{
	srand(time(NULL));
	for (int y = 0; y < m_height; y++)
		for (int x = 0; x < m_width; x++)
			m_map[y][x] = 0;

	// fMineX, fMineY : Áö·Ú ÁÖº¯ ÁÂÃø »ó´Ü ÁÂÇ¥
	for (int i = 0; i < m_countMine; i++)
	{
		int x, y, fMineX, fMineY;
		do
		{
			x = rand() % m_width;
			y = rand() % m_height;
			fMineX = x - 1;
			fMineY = y - 1;
		} while (m_map[y][x] == MINE);
		m_map[y][x] = MINE;

		// Áö·Ú ÁÖº¯ 1¾¿ Áõ°¡
		for (int q = fMineY < 0 ? 0 : fMineY; q < (fMineY + 3) && q < m_height; q++)
			for (int r = fMineX < 0 ? 0 : fMineX; r < (fMineX + 3) && r < m_width; r++)
				if (m_map[q][r] != MINE) m_map[q][r]++;
	}
}

void CGameMap::draw()
{
	for (int y=0;y<m_height;y++)
		for (int x = 0; x < m_width; x++)
		{
			switch (m_map[y][x])
			{
			case MINE:
				ScreenPrint(x * 2, y, "¨Ù");
				break;
			case 0:
				ScreenPrint(x * 2, y, "¡à");
				break;
			case 1:
				ScreenPrint(x * 2, y, "¨ç");
				break;
			case 2:
				ScreenPrint(x * 2, y, "¨è");
				break;
			case 3:
				ScreenPrint(x * 2, y, "¨é");
				break;
			case 4:
				ScreenPrint(x * 2, y, "¨ê");
				break;
			case 5:
				ScreenPrint(x * 2, y, "¨ë");
				break;
			case 6:
				ScreenPrint(x * 2, y, "¨ì");
				break;
			case 7:
				ScreenPrint(x * 2, y, "¨í");
				break;
			case 8:
				ScreenPrint(x * 2, y, "¨î");
				break;
			case 9:
				ScreenPrint(x * 2, y, "¨ï");
				break;
			case 10:
				ScreenPrint(x * 2, y, "¨ð");
				break;
			}
		}
}
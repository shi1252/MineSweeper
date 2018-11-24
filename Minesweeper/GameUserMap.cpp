#include "GameUserMap.h"
#include "util.h"
#include "GameMap.h"

CGameUserMap::CGameUserMap(CGameMap & gameMap)
{
	m_width = gameMap.getWidth();
	m_height = gameMap.getHeight();
	m_countFlag = gameMap.getCountMine();
	m_lose = false;

	m_map = new int*[m_height];
	for (int i = 0; i < m_height; i++)
		m_map[i] = new int[m_width];

	for (int y = 0; y < m_height; y++)
		for (int x = 0; x < m_width; x++)
			m_map[y][x] = CLOSE;
}

CGameUserMap::~CGameUserMap()
{
	for (int i = 0; i < m_height; i++)
		delete[] m_map[i];
	delete[] m_map;
}

void CGameUserMap::open(CGameMap &gameMap, int x, int y)
{
	int fMineX = x - 1;
	int fMineY = y - 1;

	if (m_map[y][x] == CLOSE)
	{
		m_map[y][x] = OPEN;
		switch (gameMap.getElement(x, y))
		{
		case MINE:
			AllMineOpen(gameMap);
			m_lose = true;
			break;
		case 0:
			for (int q = fMineY < 0 ? 0 : fMineY; q < (fMineY + 3) && q < m_height; q++)
				for (int r = fMineX < 0 ? 0 : fMineX; r < (fMineX + 3) && r < m_width; r++)
					open(gameMap, r, q);
			break;
		}
	}
}

void CGameUserMap::flag(int x, int y)
{
	if (m_countFlag >= 0)
	{
		if (m_map[y][x] == CLOSE && m_countFlag > 0)
		{
			m_map[y][x] = FLAG;
			m_countFlag--;
		}
		else if (m_map[y][x] == FLAG)
		{
			m_map[y][x] = CLOSE;
			m_countFlag++;
		}
	}
}

void CGameUserMap::AllMineOpen(CGameMap &gameMap)
{
	for (int y = 0; y < m_height; y++)
		for (int x = 0; x < m_width; x++)
			if (gameMap.getElement(x, y) == MINE)
				m_map[y][x] = OPEN;
}

bool CGameUserMap::winCheck(CGameMap &gameMap)
{
	if (m_countFlag != 0)
		return false;
	for (int y = 0; y < m_height; y++)
		for (int x = 0; x < m_width; x++)
			if (m_map[y][x] == FLAG && gameMap.getElement(x, y) != MINE)
				return false;
	return true;
}

void CGameUserMap::draw(CGameMap &gameMap)
{
	for (int y = 0; y < m_height; y++)
		for (int x = 0; x < m_width; x++)
			if (m_map[y][x] == CLOSE)
				ScreenPrint(x * 2, y, "бс");
			else if (m_map[y][x] == FLAG)
				ScreenPrint(x * 2, y, "г└");

	if (m_lose)
		ScreenPrint(2, m_height + 1, "Lose...");

	if (winCheck(gameMap))
		ScreenPrint(2, m_height + 1, "Win...!!");
}
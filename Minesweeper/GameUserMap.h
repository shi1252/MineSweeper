#pragma once
class CGameMap;

class CGameUserMap
{
private:
	int **m_map;
	int m_width;
	int m_height;
	int m_countFlag;
	bool m_lose;
public:
	CGameUserMap(CGameMap &gameMap);
	~CGameUserMap();

	void open(CGameMap &gameMap, int x, int y); 
	void flag(int x, int y); 
	void AllMineOpen(CGameMap &gameMap);
	bool winCheck(CGameMap &gameMap);
	bool getLose() { return m_lose; }
	void draw(CGameMap &gameMap);
};
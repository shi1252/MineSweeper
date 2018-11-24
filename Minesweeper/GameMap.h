#pragma once
class CGameMap
{
private:
	int **m_map;
	int m_width;
	int m_height;
	int m_countMine;
public:
	CGameMap(int w, int h, int m):m_width(w),m_height(h),m_countMine(m)
	{
		m_map = new int*[h];
		for (int i = 0; i < h; i++)
		{
			m_map[i] = new int[w];
		}
	}
	~CGameMap();

	void Initmap();
	int getCountMine() { return m_countMine; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	int getElement(int x, int y) { return m_map[y][x]; }
	void draw();
};


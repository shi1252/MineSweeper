#pragma once
class CMyCursor
{
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	bool m_state;
public:
	CMyCursor(int w, int h) :m_x(0), m_y(0), m_width(w), m_height(h) { m_state = false; }
	~CMyCursor();

	void setState(bool state) { m_state = state; }
	int getX() { return m_x; }
	int getY() { return m_y; }
	void goLeft() { m_x <= 0 ? 0 : m_x--; m_state = false; }
	void goRight() { m_x >= (m_width - 1) ? 0 : m_x++; m_state = false; }
	void goUp() { m_y <= 0 ? 0 : m_y--; m_state = false; }
	void goDown() { m_y >= (m_height - 1) ? 0 : m_y++; m_state = false; }
	void draw();
};
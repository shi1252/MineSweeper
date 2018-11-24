#include "MyCursor.h"
#include "util.h"

CMyCursor::~CMyCursor()
{
}

void CMyCursor::draw()
{
	if (!m_state)
		ScreenPrint(m_x * 2, m_y, "¢Á");
}

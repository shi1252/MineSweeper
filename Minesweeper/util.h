#pragma once

#define ENTER	13
#define LEFT    75
#define RIGHT   77
#define UP		72
#define DOWN	80
#define SPACE	32
#define F		102

enum { BLANK, TARGET, OBJECT };
enum { CLOSE=-4, OPEN, FLAG, MINE };

void gotoxy(int x, int y);

void ScreenInit();
void ScreenFlipping();
void ScreenClear();
void ScreenRelease();
void ScreenPrint(int x, int y, char* string);
void SetColor(unsigned short color);
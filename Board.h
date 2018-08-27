#pragma once
#include "stdafx.h"
#include "defines.h"
#include "Figure.h"
#include "StructWithDataToWnd.h"

class DataForFunc;

struct Node //Node in board
{
	bool isEmpty;
	HBRUSH hBoardElemBrush;
	HPEN hFrameBoardElemPen;

	Node() : isEmpty(0)
	{
		hBoardElemBrush = CreateSolidBrush(BLACK);
		hFrameBoardElemPen = CreatePen(PS_SOLID, 2, BLACK);
	}
};


class Board : public Basic_Figure
{
private:
	Node **mpArBoardElements;  

public:
	Board();
	virtual ~Board();
	void Draw(HDC &hDCfromMain, HWND &hWnd);
	bool IsValidPosition(Figure *pFigure, int checkTop, int checkLeft);
	void AddToBoard(DataForFunc * pData);

};
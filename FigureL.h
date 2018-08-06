#pragma once
#include "stdafx.h"
#include "defines.h"
#include "Figure.h"

class FigureL : public Figure
{

public:
	FigureL();
	virtual ~FigureL();
	int const GetTop();
	int const GetLeft();
	int const GetBottom();
	int const GetRight();
	RECT const GetFigureRect();
	void Draw(HDC &hDC, HWND &hWnd, int iVersion = 0, int x = 0, int y = 0);
	int const GetCurVersion();
	void SetNewYCoordinate(int y);
	//�������� ��� �-���������
};
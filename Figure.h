#pragma once
#include "stdafx.h"
#include "defines.h"


class Figure
{

public:
	Figure(); 
	virtual ~Figure()=0;
	int const GetTop();
	int const GetLeft();
	int const GetBottom();
	int const GetRight();
	int const GetYForDraw(); 
	RECT const GetFigureRect();
	void Draw(HDC &hDC, HWND &hWnd, int iVersion=0, int x = 0, int y = 0, int iCurYForDraw = 0);
	int const GetCurVersion();
	void SetCurVersion(int vers);
	void SetNewYCoordinate(int y, int yForDraw);
	//дописать сет х-координат

protected:
	bool*** pArVersion;
	HBRUSH hRectangelBrush;
	HPEN hFramePen;
	int iCurVersion;
	int iCurTop; 
	int iCurLeft;
	int iCurRight;
	int iCurBottom;
	int iCurYForDraw;//bottom-coordinate of last full box in figure

};

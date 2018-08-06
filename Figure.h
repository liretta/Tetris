#pragma once
#include "stdafx.h"
#include "defines.h"


class Figure
{

public:
	Figure(); 
	virtual ~Figure();
	virtual int const GetTop();
	virtual int const GetLeft();
	virtual int const GetBottom();
	virtual int const GetRight();
	virtual RECT const GetFigureRect();
	virtual void Draw(HDC &hDC, HWND &hWnd, int iVersion=0, int x = 0, int y = 0);
	virtual int const GetCurVersion();
	void SetCurVersion(int vers);
	virtual void SetNewYCoordinate(int y);
	//дописать сет х-координат

protected:
	bool*** pArVersion;
	HBRUSH hRectangelBrush;
	HPEN hFramePen;
	int iCurVersion;
	int iCurTop; //позже заменим на переменную типа rect
	int iCurLeft;
	int iCurRight;
	int iCurBottom;
	int iCurYForDraw;

};

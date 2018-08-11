#pragma once
#include "stdafx.h"
#include "defines.h"
#include "Basic_Figure.h"


class Figure: public Basic_Figure
{

public:
	bool*** pArVersion;
	Figure(); 
	virtual ~Figure()=0;
	int const GetYForDraw(); 
	void Draw(HDC &hDC, HWND &hWnd, int iVersion=0, int x = 0, int y = 0, int iCurYForDraw = 0);
	int const GetCurVersion();
	HBRUSH const GetFigureBrush();
	HPEN const GetFigurePen();
	void SetCurVersion(int vers);
	void SetNewYCoordinate(int y, int yForDraw);
	//дописать сет х-координат

protected:
	//bool*** pArVersion; // переносим в паблик...
	int iCurVersion;
	int iCurYForDraw;//bottom-coordinate of last full box in figure
	HBRUSH hRectangelBrush;
	HPEN hFramePen;
};

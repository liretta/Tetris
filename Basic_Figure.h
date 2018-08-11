#pragma once
#include "stdafx.h"
#include "defines.h"


class Basic_Figure
{

public:
	Basic_Figure(); //дописать как аргументы все члены-переменные
	virtual ~Basic_Figure() = 0;
	int const GetTop();
	int const GetLeft();
	int const GetBottom();
	int const GetRight();
	RECT const GetFigureRect();
	virtual void Draw() {};
	//void Draw(HDC &hDC, HWND &hWnd, int iVersion = 0, int x = 0, int y = 0, int iCurYForDraw = 0); - переопределим в базовом классе для фигурок и отдельно в доске
	//int const GetCurVersion(); - определим в базовом классе для фигурок
	//void SetCurVersion(int vers); - определим в базовом классе для фигурок
	//void SetNewYCoordinate(int y, int yForDraw); - определим в базовом классе для фигурок
	

protected:
	//bool*** pArVersion; - -будет только в базовом классе для фигурок
	//HBRUSH hRectangelBrush;
	//HPEN hFramePen;
	//int iCurVersion; - будет только в базовом классе для фигурок
	int iCurTop;
	int iCurLeft;
	int iCurRight;
	int iCurBottom;
	//int iCurYForDraw;//bottom-coordinate of last full box in figure - - будет только в базовом классе для фигурок

};

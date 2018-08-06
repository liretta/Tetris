#include "stdafx.h"
#include "FigureT.h"
#include "Enumerations.h"


FigureT::FigureT()
{
	//create arrey with versions of figure 
	pArVersion = new bool**[T_VERSION];
	for (int i = 0; i < T_VERSION;++i)
	{
		pArVersion[i] = new bool*[BOXNUMBER]();
		for (int j = 0; j < BOXNUMBER; ++j)
			pArVersion[i][j] = new bool[BOXNUMBER](); //there is one box in template
	}

	//initialize versions of figure (exmpl. figure "I") - указываем, какие "€чейки" будут заполненны цветом
	//version 0 (look on first index)
	pArVersion[0][2][1] = FULL;
	pArVersion[0][2][2] = FULL;
	pArVersion[0][2][3] = FULL;
	pArVersion[0][3][2] = FULL;

	//version 1
	pArVersion[1][1][2] = FULL;
	pArVersion[1][2][2] = FULL;
	pArVersion[1][2][3] = FULL;
	pArVersion[1][3][2] = FULL;

	//version 2
	pArVersion[2][1][2] = FULL;
	pArVersion[2][2][1] = FULL;
	pArVersion[2][2][2] = FULL;
	pArVersion[2][2][3] = FULL;

	//version 3
	pArVersion[3][1][2] = FULL;
	pArVersion[3][2][1] = FULL;
	pArVersion[3][2][2] = FULL;
	pArVersion[3][2][3] = FULL;
	hRectangelBrush = CreateSolidBrush(BLUE);
	hFramePen = CreatePen(PS_SOLID, 2, LIGHTBLUE);
}

FigureT::~FigureT()
{
	if (pArVersion != 0)
	{
		for (int i = 0; i < T_VERSION; ++i)
		{
			for (int j = 0; j < BOXNUMBER; ++j)
			{
				delete[] pArVersion[i][j];
				pArVersion[i][j] = nullptr;
			}
			delete[] pArVersion[i];
			pArVersion[i] = nullptr;
		}

		delete[] pArVersion;
		pArVersion = nullptr;
	}
}

void FigureT::Draw(HDC &hDCfromMain, HWND &hWnd, int iVersion, int left, int right)
{
	//HPEN hInvisiblePen = CreatePen(PS_SOLID, 2, WHITE);
	//HBRUSH hInvisibleBrush = CreateSolidBrush(WHITE);

	iCurVersion = iVersion;

	HDC hDC = hDCfromMain;
	HBRUSH hOldBr = (HBRUSH)SelectObject(hDC, hRectangelBrush);
	HPEN hOldPen = (HPEN)SelectObject(hDC, hFramePen);


	int x = left, y = right;
	iCurTop = y;
	iCurLeft = x;
	for (int i = 0; i < BOXNUMBER; ++i)
	{
		y = right;
		for (int j = 0; j < BOXNUMBER; ++j)
		{
			if (pArVersion[iCurVersion][i][j] == FULL) //if current box isn't empty - draw it
				Rectangle(hDC, x, y, x + BOXSIZE, y + BOXSIZE);
			y += BOXSIZE;
		}
		x += BOXSIZE;
	}

	iCurRight = x;
	iCurBottom = y;

	SelectObject(hDC, hOldBr);
	SelectObject(hDC, hOldPen);
	DeleteObject(hOldBr);
	DeleteObject(hOldPen);
	ReleaseDC(hWnd, hDC);

}

int const FigureT::GetTop() { return iCurTop; };
int const FigureT::GetLeft() { return iCurLeft; };
int const FigureT::GetBottom() { return iCurBottom; };
int const FigureT::GetRight() { return iCurRight; };

RECT const FigureT::GetFigureRect()
{
	RECT temp;
	temp.top = iCurTop;
	temp.left = iCurLeft;
	temp.right = iCurRight;
	temp.bottom = iCurBottom;
	return temp;

};


int const FigureT::GetCurVersion() { return iCurVersion; };
void FigureT::SetNewYCoordinate(int y)
{
	iCurTop = y;
	iCurBottom = y + (BOXNUMBER*BOXSIZE);

};
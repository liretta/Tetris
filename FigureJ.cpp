#include "stdafx.h"
#include "FigureJ.h"
#include "Enumerations.h"


FigureJ::FigureJ()
{
	//create arrey with versions of figure 
	pArVersion = new bool**[J_VERSION];
	for (int i = 0; i < J_VERSION;++i)
	{
		pArVersion[i] = new bool*[BOXNUMBER]();
		for (int j = 0; j < BOXNUMBER; ++j)
			pArVersion[i][j] = new bool[BOXNUMBER](); //there is one box in template
	}

	//initialize versions of figure (exmpl. figure "I") - указываем, какие "€чейки" будут заполненны цветом
	//version 0 (look on first index)
	pArVersion[0][0][2] = FULL;
	pArVersion[0][1][2] = FULL;
	pArVersion[0][2][1] = FULL;
	pArVersion[0][2][2] = FULL;

	//version 1
	pArVersion[1][2][0] = FULL;
	pArVersion[1][2][1] = FULL;
	pArVersion[1][2][2] = FULL;
	pArVersion[1][3][2] = FULL;

	//version 2
	pArVersion[2][2][2] = FULL;
	pArVersion[2][2][3] = FULL;
	pArVersion[2][3][2] = FULL;
	pArVersion[2][4][2] = FULL;

	//version 3
	pArVersion[3][1][2] = FULL;
	pArVersion[3][2][2] = FULL;
	pArVersion[3][2][3] = FULL;
	pArVersion[3][2][4] = FULL;

	hRectangelBrush = CreateSolidBrush(RED);
	hFramePen = CreatePen(PS_SOLID, 2, LIGHTRED);
}

FigureJ::~FigureJ()
{
	if (pArVersion != 0)
	{
		for (int i = 0; i < J_VERSION; ++i)
		{
			for (int j = 0; j < BOXNUMBER; ++j)
			{
				delete [] pArVersion[i][j];
				pArVersion[i][j] = nullptr;
			}
			delete [] pArVersion[i];
			pArVersion[i] = nullptr;
		}

	
		delete[] pArVersion;
		pArVersion = nullptr;
	}

}

void FigureJ::Draw(HDC &hDCfromMain, HWND &hWnd, int iVersion, int left, int right)
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

int const FigureJ::GetTop() { return iCurTop; };
int const FigureJ::GetLeft() { return iCurLeft; };
int const FigureJ::GetBottom() { return iCurBottom; };
int const FigureJ::GetRight() { return iCurRight; };

RECT const FigureJ::GetFigureRect()
{
	RECT temp;
	temp.top = iCurTop;
	temp.left = iCurLeft;
	temp.right = iCurRight;
	temp.bottom = iCurBottom;
	return temp;

};


int const FigureJ::GetCurVersion() { return iCurVersion; };
void FigureJ::SetNewYCoordinate(int y)
{
	iCurTop = y;
	iCurBottom = y + (BOXNUMBER*BOXSIZE);

};
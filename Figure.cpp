#include "stdafx.h"
#include "Figure.h"


Figure::Figure():iCurVersion(0), iCurTop(0), iCurLeft(0), iCurRight(0), iCurBottom(0)
{
	//create arrey with versions of figure 
	pArVersion = new bool** [I_VERSION];
	for (int i = 0; i < I_VERSION;++i)
	{
		pArVersion[i] = new bool*[BOXNUMBER]();
		for (int j = 0; j < BOXNUMBER; ++j)
			pArVersion[i][j] = new bool[BOXNUMBER] (); //there is one box in template
	}

	//initialize versions of figure (exmpl. figure "I") - указываем, какие "€чейки" будут заполненны цветом
	//version 0 (look on first index)
	pArVersion[0][0][2] = 1;
	pArVersion[0][1][2] = 1;
	pArVersion[0][2][2] = 1;
	pArVersion[0][3][2] = 1;

	//version 1
	pArVersion[1][2][0] = 1;
	pArVersion[1][2][1] = 1;
	pArVersion[1][2][2] = 1;
	pArVersion[1][2][3] = 1;

	hRectangelBrush = CreateSolidBrush(GREEN);
	hFramePen = CreatePen(PS_SOLID, 2, LIGHTGREEN);
}

Figure::~Figure()
{
	if (pArVersion != 0)
	{
		for (int i = 0; i < I_VERSION; ++i)
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

void Figure::Draw(HDC &hDCfromMain, HWND &hWnd, int iVersion, int left, int right)
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
			if (pArVersion[iCurVersion][i][j]==1)
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

int const Figure::GetTop() { return iCurTop; };
int const Figure::GetLeft() { return iCurLeft; };
int const Figure::GetBottom() { return iCurBottom; };
int const Figure::GetRight() { return iCurRight; };
RECT const Figure::GetFigureRect()
{
	RECT temp;
	temp.top = iCurTop;
	temp.left = iCurLeft;
	temp.right = iCurRight;
	temp.bottom = iCurBottom;
	return temp;
	
};

int const Figure::GetCurVersion() { return iCurVersion; };
void Figure::SetNewYCoordinate(int y)
{
	iCurTop = y;
	iCurBottom = y + (BOXNUMBER*BOXSIZE);
	
};

void Figure::SetCurVersion(int vers) { iCurVersion = vers; };


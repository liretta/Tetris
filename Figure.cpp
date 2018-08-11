#include "stdafx.h"
#include "Figure.h"


Figure::Figure():iCurVersion(0), iCurTop(0), iCurLeft((BOARDHEIGHT*BOXSIZE)-BOXSIZE), iCurRight(0), iCurBottom(0)
{

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

void Figure::Draw(HDC &hDCfromMain, HWND &hWnd, int iVersion, int left, int right, int iForDraw)
{
	iCurVersion = iVersion;

	HDC hDC = hDCfromMain;
	HBRUSH hOldBr = (HBRUSH)SelectObject(hDC, hRectangelBrush);
	HPEN hOldPen = (HPEN)SelectObject(hDC, hFramePen);

	int x = left, y = right;
	iCurTop = y;
	iCurLeft = x;
	iCurYForDraw = 0;
	for (int i = 0; i < BOXNUMBER; ++i)
	{
		y = right;
		for (int j = 0; j < BOXNUMBER; ++j)
		{
			if (pArVersion[iCurVersion][i][j] == 1)
			{
				Rectangle(hDC, x, y, x + BOXSIZE, y + BOXSIZE);
				iCurYForDraw = (iCurYForDraw> y ? iCurYForDraw : y); 
				//если заполнены 1 и 2, но не заполнен 3 - iCur обнуляется и  теряю строчку...
			}
			y += BOXSIZE;
		}
		
		x += BOXSIZE;
	}
	
	//проверка - если icur не дно, тогда увеличиваем. сделай тернально
	iCurYForDraw = (iCurYForDraw == iCurTop+BOXSIZE* BOXNUMBER ? iCurYForDraw : iCurYForDraw +BOXSIZE);
	 //after loop y = top-point of last box. But we need bottom, so add boxsize if y isn't bottom
	y = (y == iCurTop + BOXSIZE * BOXNUMBER ? y : y + BOXSIZE);
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
int const Figure::GetYForDraw() { return iCurYForDraw; };

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
void Figure::SetNewYCoordinate(int y, int yDraw)
{
	iCurTop = y;
	iCurBottom = y + (BOXNUMBER*BOXSIZE);
	iCurYForDraw = yDraw;
	
};

void Figure::SetCurVersion(int vers) { iCurVersion = vers; };


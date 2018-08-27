#include "stdafx.h"
#include "Basic_Figure.h"
#include "Figure.h"


Figure::Figure() : iCurVersion(0)
{
	iCurLeft = ((BOARDWIDTH * BOXSIZE) / 2) - (BOXNUMBER/2*BOXSIZE); //to place the figure in the board centre, iCurLeft = cent of board - half-figure

	//todo: need to align figure. Add iCurXFor Draw - start left-coordinate by first full box in figure
};

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
				
			}
			y += BOXSIZE;
		}
		
		x += BOXSIZE;
	}
	
	//проверка - если icur не дно, тогда увеличиваем. 
	iCurYForDraw = (iCurYForDraw == iCurTop+BOXSIZE*BOXNUMBER ? iCurYForDraw : iCurYForDraw +BOXSIZE);
	 //after loop y = top-point of last box. But we need bottom, so add boxsize if "y" isn't bottom
	y = (y == iCurTop + BOXSIZE * BOXNUMBER ? y : y + BOXSIZE);
	iCurRight = x;
	iCurBottom = y;

	SelectObject(hDC, hOldBr);
	SelectObject(hDC, hOldPen);
	DeleteObject(hOldBr);
	DeleteObject(hOldPen);
	ReleaseDC(hWnd, hDC);

}


int const Figure::GetYForDraw() { return iCurYForDraw; };
int const Figure::GetCurVersion() { return iCurVersion; };
HBRUSH const Figure::GetFigureBrush() { return hRectangelBrush; };
HPEN const Figure::GetFigurePen() { return hFramePen; };

void Figure::SetNewYCoordinate(int y, int yDraw)
{
	iCurTop = y;
	iCurBottom = y + (BOXNUMBER*BOXSIZE);
	iCurYForDraw = yDraw;
	
};

void Figure::SetCurVersion(int vers) { iCurVersion = vers; };


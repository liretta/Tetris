#include "stdafx.h"
#include "Figure.h"
#include "Board.h"
#include "StructWithDataToWnd.h"
#include "Enumerations.h"


Board::Board()
{
	//create array with empty board
	mpArBoardElements = new Node*[BOARDHEIGHT] ();
	for (int i = 0; i < BOARDHEIGHT;++i)
	{
		mpArBoardElements[i] = new Node[BOARDWIDTH]();
	}
	iCurRight = BOARDWIDTH * BOXSIZE;
	iCurBottom = BOARDHEIGHT * BOXSIZE;

};

Board::~Board()
{
	if (mpArBoardElements != 0)
		for (int i = 0; i < BOARDHEIGHT; ++i)
			delete[] mpArBoardElements[i];

	delete[] mpArBoardElements;
};

void Board::Draw(HDC &hDCfromMain, HWND &hWnd)
{
	HDC hDC = hDCfromMain;
	HBRUSH hOldBr;
	HPEN hOldPen;

	int x = iCurTop, y = iCurLeft;

	for (int i = 0; i < BOARDHEIGHT; ++i)
	{
		y = iCurLeft;
		for (int j = 0; j < BOARDWIDTH; ++j)
		{
			if (mpArBoardElements[i][j].isEmpty == false)
			{	
				hOldBr = (HBRUSH)SelectObject(hDC, mpArBoardElements[i][j].hBoardElemBrush);
				hOldPen = (HPEN)SelectObject(hDC, mpArBoardElements[i][j].hFrameBoardElemPen);
				Rectangle(hDC, x, y, x + BOXSIZE, y + BOXSIZE);
				SelectObject(hDC, hOldBr);
				SelectObject(hDC, hOldPen);
				DeleteObject(hOldBr);
				DeleteObject(hOldPen);
			}
			y += BOXSIZE;
		}
		x += BOXSIZE;
	}

	ReleaseDC(hWnd, hDC);
}

//example code from simple WinProj

//hBr = CreateSolidBrush(RGB(pNodesAr[i].R, pNodesAr[i].G, pNodesAr[i].B));
//hOldBr = (HBRUSH)SelectObject(hdc, hBr);
//
//hPen = CreatePen(PS_SOLID, 3, RGB(pNodesAr[i].penR, pNodesAr[i].penG, pNodesAr[i].penB));
//hOldPen = (HBRUSH)SelectObject(hdc, hPen);
//
//Rectangle(hdc, pNodesAr[i].x - pNodesAr[i].nShift,
//	pNodesAr[i].y - pNodesAr[i].nShift,
//	pNodesAr[i].x + pNodesAr[i].nShift,
//	pNodesAr[i].y + pNodesAr[i].nShift);
//
///*SelectObject(hdc, hOldBr);
//DeleteObject(hBr);*/
//
//SelectObject(hdc, hOldBr);
//SelectObject(hdc, hOldPen);
//DeleteObject(hBr);
//DeleteObject(hPen);

bool Board::IsValidPosition(Figure *pFigure, int checkTop, int checkLeft)
{
	//figure coordinate
	int figureTop = checkTop;
	int figureLeft = checkLeft;
	int figureVersion = pFigure->GetCurVersion();
	int k=0, m=0; //counter for figure-boxes

	//HBRUSH hTempBrash = pFigure->GetFigureBrush(); - перенесем в адд
	//HPEN hTempPen = pFigure->GetFigurePen(); - перенесем в адд

	int x = iCurLeft, y = iCurTop; //board coordinate
	bool bCoincidence = false;

	//first checking board bottom and figure bottom-coordinate
	int tempY = pFigure->GetYForDraw() + BOXSIZE;
	if (tempY > BOARDHEIGHT*BOXSIZE)
		return false;

		//	until we reach the end of the figure - compare board coordinate & status (empty/full) with coordinate & board 
	for (int i = 0; (k != BOXSIZE && i < BOARDHEIGHT) ; ++i)
	{
		for (int j = 0; (m != BOXSIZE && j < BOARDWIDTH); ++j)
		{
			bCoincidence = false;
			//if (figureTop == x && figureLeft == y && pFigure->pArVersion[figureVersion][i][j] == FULL && mpArBoardElements[i][j].isEmpty == false)//нужно обратиться к конкретному элементу массива фигура и сверить его с элементом доски
			//думаем, как это сделать, т.к. массивы протектед. Пока сделала их доступными...
			//если совпали координаты фигуры с координатами доски (а это рано или поздно случиться), а также квадратик фигурки в этом месте не пустой, а 
			//квадратик доски уже занят
			//возвращаем  false
			if (x == figureLeft && y == figureTop)
			{
				bCoincidence = true;
				if (pFigure->pArVersion[figureVersion][k][m] == FULL && mpArBoardElements[i][j].isEmpty == false)
					return false;
			}
			y += BOXSIZE;

			if (bCoincidence)
			{
				figureTop += BOXSIZE;
				++m;
			}
		}
		
		x += BOXSIZE;
		if (bCoincidence)
		{
			figureLeft += BOXSIZE;
			++k;
		}
	}
	
	return true;
}

void Board::AddToBoard(DataForFunc * pData)
{
	int iVersion = pData->fCurFigure->GetCurVersion();
	int topFigure = pData->fCurFigure->GetTop();
	int leftFigure = pData->fCurFigure->GetLeft();
	HBRUSH hBrush = pData->fCurFigure->GetFigureBrush();
	HPEN hPen = pData->fCurFigure->GetFigurePen();

	for (int i = 0; i < BOXNUMBER; ++i)
	{
		for (int j = 0; j < BOXNUMBER; ++j)//??разве до бокснамбер??
		{
			if (pData->fCurFigure->pArVersion[iVersion][i][j] == FULL)
			{

				mpArBoardElements[(topFigure / BOXSIZE)][(leftFigure / BOXSIZE)].isEmpty = false;
				mpArBoardElements[(topFigure / BOXSIZE)][(leftFigure / BOXSIZE)].hBoardElemBrush = hBrush;
				mpArBoardElements[(topFigure / BOXSIZE)][(leftFigure / BOXSIZE)].hFrameBoardElemPen = hPen;
			}

		}
	}
				
}

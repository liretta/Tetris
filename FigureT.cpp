#include "stdafx.h"
#include "FigureT.h"
#include "Enumerations.h"


FigureT::FigureT()
{
	//create array with versions of figure 
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

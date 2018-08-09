#include "stdafx.h"
#include "FigureL.h"
#include "Enumerations.h"


FigureL::FigureL()
{
	//create arrey with versions of figure 
	pArVersion = new bool**[L_VERSION];
	for (int i = 0; i < L_VERSION;++i)
	{
		pArVersion[i] = new bool*[BOXNUMBER]();
		for (int j = 0; j < BOXNUMBER; ++j)
			pArVersion[i][j] = new bool[BOXNUMBER](); //there is one box in template
	}

	//initialize versions of figure (exmpl. figure "I") - указываем, какие "€чейки" будут заполненны цветом
	//version 0 (look on first index)
	pArVersion[0][0][2] = FULL;
	pArVersion[0][1][2] = FULL;
	pArVersion[0][2][2] = FULL;
	pArVersion[0][2][3] = FULL;

	//version 1
	pArVersion[1][1][2] = FULL;
	pArVersion[1][2][0] = FULL;
	pArVersion[1][2][1] = FULL;
	pArVersion[1][2][2] = FULL;

	//version 2
	pArVersion[2][2][1] = FULL;
	pArVersion[2][2][2] = FULL;
	pArVersion[2][3][2] = FULL;
	pArVersion[2][4][2] = FULL;

	//version 3
	pArVersion[3][2][2] = FULL;
	pArVersion[3][2][3] = FULL;
	pArVersion[3][2][4] = FULL;
	pArVersion[3][3][2] = FULL;

	hRectangelBrush = CreateSolidBrush(RED);
	hFramePen = CreatePen(PS_SOLID, 2, LIGHTRED);
}

FigureL::~FigureL()
{
	if (pArVersion != 0)
	{
		for (int i = 0; i < L_VERSION; ++i)
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

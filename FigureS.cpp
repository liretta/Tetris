#include "stdafx.h"
#include "FigureS.h"
#include "Enumerations.h"


FigureS::FigureS()
{
	//create arrey with versions of figure 
	pArVersion = new bool**[S_VERSION];
	for (int i = 0; i < S_VERSION;++i)
	{
		pArVersion[i] = new bool*[BOXNUMBER]();
		for (int j = 0; j < BOXNUMBER; ++j)
			pArVersion[i][j] = new bool[BOXNUMBER](); //there is one box in template
	}

	//initialize versions of figure (exmpl. figure "I") - указываем, какие "€чейки" будут заполненны цветом
	//version 0 (look on first index)
	pArVersion[0][2][2] = FULL;
	pArVersion[0][2][3] = FULL;
	pArVersion[0][3][1] = FULL;
	pArVersion[0][3][2] = FULL;

	//version 1
	pArVersion[1][1][2] = FULL;
	pArVersion[1][2][2] = FULL;
	pArVersion[1][2][3] = FULL;
	pArVersion[1][3][3] = FULL;

	hRectangelBrush = CreateSolidBrush(YELLOW);
	hFramePen = CreatePen(PS_SOLID, 2, LIGHTYELLOW);
}

FigureS::~FigureS()
{
	if (pArVersion != 0)
	{
		for (int i = 0; i < S_VERSION; ++i)
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

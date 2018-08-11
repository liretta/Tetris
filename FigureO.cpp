#include "stdafx.h"
#include "FigureO.h"
#include "Enumerations.h"


FigureO::FigureO()
{
	//create array with versions of figure 
	pArVersion = new bool**[O_VERSION];
	for (int i = 0; i < O_VERSION;++i)
	{
		pArVersion[i] = new bool*[BOXNUMBER]();
		for (int j = 0; j < BOXNUMBER; ++j)
			pArVersion[i][j] = new bool[BOXNUMBER](); //there is one box in template
	}

	//initialize versions of figure (exmpl. figure "I") - указываем, какие "€чейки" будут заполненны цветом
	//version 0 (look on first index)
	pArVersion[0][2][1] = FULL;
	pArVersion[0][2][2] = FULL;
	pArVersion[0][3][1] = FULL;
	pArVersion[0][3][2] = FULL;

	hRectangelBrush = CreateSolidBrush(GREEN);
	hFramePen = CreatePen(PS_SOLID, 2, LIGHTGREEN);
}

FigureO::~FigureO()
{
	if (pArVersion != 0)
	{
		for (int i = 0; i < O_VERSION; ++i)
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

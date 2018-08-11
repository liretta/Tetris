#include "stdafx.h"
#include "FigureI.h"
#include "Enumerations.h"

FigureI::FigureI()
{
	//create array with versions of figure 
	pArVersion = new bool**[I_VERSION];
	for (int i = 0; i < I_VERSION;++i)
	{
		pArVersion[i] = new bool*[BOXNUMBER]();
		for (int j = 0; j < BOXNUMBER; ++j)
			pArVersion[i][j] = new bool[BOXNUMBER](); //there is one box in template
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

FigureI::~FigureI()
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

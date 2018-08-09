#include "stdafx.h"
#include "StructWithDataToWnd.h"

DataForFunc::DataForFunc() : fCurFigure(nullptr), fNextFigure(nullptr), IsFigureFalling(0), isGameOn(0)
{
	/*fCurFigure = new Figure;
	fNextFigure = new Figure;*/

};

DataForFunc::~DataForFunc()
{
	if(fCurFigure != nullptr)
	delete fCurFigure;
	fCurFigure = nullptr;
	
	if(fNextFigure !=nullptr)
	delete fNextFigure;
	fNextFigure = nullptr;
}
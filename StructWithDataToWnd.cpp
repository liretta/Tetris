#include "stdafx.h"
#include "StructWithDataToWnd.h"

DataForFunc::DataForFunc() : fCurFigure(0), fNextFigure(0), IsFigureFalling(0), isGameOn(0)
{
	fCurFigure = new Figure;
	fNextFigure = new Figure;

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
#include "stdafx.h"
#include "StructWithDataToWnd.h"

DataForFunc::DataForFunc() : fCurFigure(nullptr), fNextFigure(nullptr), IsFigureFalling(0), isGameOn(0), mpBoard(nullptr)
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

	if (mpBoard != 0)
		delete mpBoard;
}
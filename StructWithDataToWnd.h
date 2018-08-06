#pragma once
#include "stdafx.h"
#include "Figure.h"

class  DataForFunc
{
public:
	Figure * fCurFigure;
	Figure * fNextFigure;
	bool IsFigureFalling;
	bool isGameOn;

	DataForFunc();
	~DataForFunc();	
};

#pragma once
#include "stdafx.h"
#include "Figure.h"
#include "Board.h"

class Board;

class  DataForFunc
{
public:
	Figure * fCurFigure;
	Figure * fNextFigure;
	bool IsFigureFalling;
	bool isGameOn;
	Board * mpBoard;

	DataForFunc(); 
	~DataForFunc();	
	
};



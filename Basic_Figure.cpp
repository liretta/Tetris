#include "stdafx.h"
#include "Basic_Figure.h"

Basic_Figure::Basic_Figure() :
	iCurTop(0), iCurLeft(0), iCurRight(0), iCurBottom(0) {};

Basic_Figure::~Basic_Figure() {};


int const Basic_Figure::GetTop() { return iCurTop; };
int const Basic_Figure::GetLeft() { return iCurLeft; };
int const Basic_Figure::GetBottom() { return iCurBottom; };
int const Basic_Figure::GetRight() { return iCurRight; };

RECT const Basic_Figure::GetFigureRect()
{
	RECT temp;
	temp.top = iCurTop;
	temp.left = iCurLeft;
	temp.right = iCurRight;
	temp.bottom = iCurBottom;
	return temp;
};


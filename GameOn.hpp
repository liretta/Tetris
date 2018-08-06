#pragma once
#include "IncludedMyFiles.h"
#include "Enumerations.h"

void GetNewFigure(DataForFunc *data);

void GameOn(DataForFunc *data)
{
	//потом тут будет "пока дата.фигуркаПадает = да и дата.ДоскаЗаполнена != да повторяем:
	//SendMessage(0, SET_STRUCT, (WPARAM)data, NULL);
	GetNewFigure(data);
	data->isGameOn = true;
	
}

void GetNewFigure(DataForFunc *data)
{
	int iForRand;
	static int iCounter = 0;
	iCounter++;
	srand((unsigned int)time(0));
	//srand((unsigned int)time);
	iForRand = rand() % COUNTFIGURE + 1;

	delete data->fCurFigure;

	switch (iForRand)
	{
	case S_FIGURE:
		data->fCurFigure = new FigureS;
		data->fCurFigure->SetCurVersion(rand() % S_VERSION);
		break;
	case T_FIGURE:
		data->fCurFigure = new FigureT;
		data->fCurFigure->SetCurVersion(rand() % T_VERSION);
		break;
	case Z_FIGURE:
		data->fCurFigure = new FigureZ;
		data->fCurFigure->SetCurVersion(rand() % Z_VERSION);
		break;
	case J_FIGURE:
	{
		data->fCurFigure = new FigureJ;
		data->fCurFigure->SetCurVersion(rand() % J_VERSION);
		break;
	}
	case L_FIGURE:
		data->fCurFigure = new FigureL;
		data->fCurFigure->SetCurVersion(rand() % L_VERSION);
		break;
	case I_FIGURE:
	{
		data->fCurFigure = new FigureI;
		data->fCurFigure->SetCurVersion(rand() % I_VERSION);
		break;
	}
	case O_FIGURE:
		data->fCurFigure = new FigureO;
		data->fCurFigure->SetCurVersion(O_VERSION - 1);
		break;
	default:
		data->fCurFigure = new FigureI;
		data->fCurFigure->SetCurVersion(rand() % I_VERSION);
		break;
	}

	data->IsFigureFalling = true;

	//WARNING!!! ТУТ ОБЯЗАТЕЛЬНО СДЕЛАЕМ ПРЕСВОЕНИЕ NEXT FIGURE!! а когда curFigure перестанет падать, тогда перенесем в нее 
	//фигурку из некста


}

//bool IsPisitionValid(DataForFunc *data, int y, int x = 0)
//{
//	int tempY = data->fCurFigure->GetBottom();
//
//	if()
//
//	тут будет проверка на наличие свободного места при повороте
//	
//}

//void GetNewFigure(DataForFunc *data)
//{
//	Figure *pTemp;
//	int iForRand;
//	static int iCounter = 0;
//	iCounter++;
//	srand((unsigned int)time);
//	iForRand = rand() % COUNTFIGURE + 1;
//
//	delete data->fCurFigure;
//
//	switch (iForRand)
//	{
//	case S_FIGURE:
//		pTemp = new FigureS;
//		pTemp->SetCurVersion(rand() % S_VERSION);
//		break;
//	case T_FIGURE:
//		pTemp = new FigureT;
//		pTemp->SetCurVersion(rand() % T_VERSION);
//		break;
//	case Z_FIGURE:
//		pTemp = new FigureZ;
//		pTemp->SetCurVersion(rand() % Z_VERSION);
//		break;
//	case J_FIGURE:
//	{
//		pTemp = new FigureJ;
//		pTemp->SetCurVersion(rand() % J_VERSION);
//		break;
//	}
//	case L_FIGURE:
//		pTemp = new FigureL;
//		pTemp->SetCurVersion(rand() % L_VERSION);
//		break;
//	case I_FIGURE:
//	{
//		pTemp = new FigureI;
//		pTemp->SetCurVersion(rand() % I_VERSION);
//		break;
//	}
//	case O_FIGURE:
//		pTemp = new FigureO;
//		pTemp->SetCurVersion(O_VERSION-1);
//		break;
//	default:
//		pTemp = new FigureI;
//		pTemp->SetCurVersion(rand() % I_VERSION);
//		break;
//	}
//
//	
//	data->fCurFigure = pTemp;
//	data->IsFigureFalling = true;
//
//	WARNING!!! ТУТ ОБЯЗАТЕЛЬНО СДЕЛАЕМ ПРЕСВОЕНИЕ NEXT FIGURE!! а когда curFigure перестанет падать, тогда перенесем в нее 
//	фигурку из некста
//	
//		
//}

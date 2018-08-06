#define _CRTDBG_MAP_ALLOC	
#include <stdlib.h> 
#include <crtdbg.h>

using std::vector;

#define SET_STRUCT WM_USER+1 //our message TO WndProc

#define FPS 25
#define BOXSIZE 20 //������ ������ ����������
#define BOXNUMBER 5 // ���������� ����������� � ������, ������� ������ 
#define BOARDWIDHT 20 //������ ����� - 20 �����������
#define BOARDHEIGHT 10 //������ ����� - 10 �����������
#define WINDOWWIDTH 640 //���������� �������� � ������ 
#define WINDOWHEIGHT 480 //���������� �������� � ������


//������ �������� ���� � �������� = BOARDWIDHT * BOXSIZE = 400
//������� ���� 
#define XMARGIN = int ((WINDOWWIDTH - BOARDWIDHT * BOXSIZE)/2)
//(640 - 400)/2 = 120 - ������ ������� � ������ ���� ������ ��������

//������ ������
#define TOPMARGIN = WINDOWWIDTH - (BOARDWIDHT * BOXSIZE)-5

//quontity of version for each figure
#define COUNTFIGURE 7 //���������� �������
#define S_VERSION 2 //YELLOW
#define T_VERSION 4 //BLUE
#define Z_VERSION 2 //YELLOW
#define J_VERSION 4 //RED
#define L_VERSION 4 //RED
#define I_VERSION 2 //GREEN
#define O_VERSION 1 //green

#define FIGURESPEED 1,5

//?? ��������� ������� - ���� ����� ����� �������, ������� ������ ������ 1,5 ���
#define MOVESIDEWAYSFREQ 0,15

//���� ����� ����� ������� ����, � ����� ��������� ������� ������:
#define MOVEDOWNFREQ 0,1


// rgb colors

#define WHITE RGB(255, 255, 255)
#define GREY RGB (185, 185, 185)
#define BLACK RGB (0, 0, 0)
#define RED RGB (155, 0, 0) //RED FOR J-FIGURE
#define LIGHTRED RGB (175, 20, 20)
#define GREEN RGB (0, 155, 0) //FOR I-FIGURE
#define LIGHTGREEN RGB (20, 175, 20)
#define BLUE RGB (0, 0, 155) //FOR T-FIGURE
#define LIGHTBLUE RGB (20, 20, 175)
#define YELLOW RGB (155, 155, 0) //FOR S-FIGURE & Z-FiGURE
#define LIGHTYELLOW RGB (175, 175, 20)
#define BORDERCOLOR BLUE
#define BGCOLOR  BLACK
#define TEXTCOLOR  WHITE
#define TEXTSHADOWCOLOR GREY
#define COLORS { BLUE, GREEN, RED, YELLOW }
#define LIGHTCOLORS { LIGHTBLUE, LIGHTGREEN, LIGHTRED, LIGHTYELLOW }




//key kode
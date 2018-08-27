// Tetris.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Tetris.h"
#include "IncludedMyFiles.h"
#include "GameOn.hpp"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
//void				TestFuns(const char * test);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TETRIS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

	 // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TETRIS));

    MSG msg;
		
    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {	
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
			DispatchMessage(&msg);
        }
    }
	
    return (int) msg.wParam;
}


//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TETRIS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = CreateSolidBrush(BGCOLOR); 
	wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TETRIS);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   //there is correctly rectangle: 20*10 board and two left&right zone with score and next figure
 /*  int iWindSize = (BOARDHEIGHT * BOXSIZE) * 2; 
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   CW_USEDEFAULT, CW_USEDEFAULT, iWindSize, BOARDWIDHT * BOXSIZE, nullptr, nullptr, hInstance, nullptr);*/
  

	//there is current rectangle: only 20*10 board; 
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, //WS_MAXIMIZEBOX && WS_MINIMIZEBOX, - resize lock 
			 CW_USEDEFAULT, CW_USEDEFAULT, WINDOWWIDTH, WINDOWHEIGHT, nullptr, nullptr, hInstance, nullptr);
   
  
   //there is big square
   /*HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, BOARDHEIGHT*BOXSIZE, 500, BOARDWIDHT*BOXSIZE, nullptr, nullptr, hInstance, nullptr);
*/
   //there is rectangle 10/20
   /*HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   CW_USEDEFAULT, 0, (BOARDHEIGHT*BOXSIZE), (BOARDWIDHT*BOXSIZE), nullptr, nullptr, hInstance, nullptr);*/
  
   if (!hWnd)
   {
      return FALSE;
   }
   
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static DataForFunc * tempData = nullptr;
	int y;
	int x; 
	int version; 
	//RECT tempRect; 
	RECT mainRect;
	static int widht;
	static int height=500;

    switch (message)
    {
	case WM_CREATE:
	{
		SetTimer(hWnd, 77, 200, NULL);
		tempData = new DataForFunc;
		
		break;
	}
	case WM_SIZE:
		widht = LOWORD(lParam);
		height = HIWORD(lParam);
	/*case SET_STRUCT:
	{
		MessageBox(hWnd, (LPCWSTR)L"Get structure", (LPCWSTR)L"Get", MB_OK);
		break;
	}*/
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case ID_PLAY:
				GameOn(tempData);
				break;
			case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
			{
				tempData->isGameOn = false;
				/*if (_CrtDumpMemoryLeaks())
					MessageBox(hWnd, (LPCTSTR)L"MEMORY lEAKS!!", (LPCWSTR)L"Mem check", MB_OK);
				else
					MessageBox(hWnd, (LPCTSTR)L"MEMORY OK :-)", (LPCWSTR)L"Mem check", MB_OK);*/

				DestroyWindow(hWnd);
				break;
			}
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hDC = BeginPaint(hWnd, &ps);
			
			mainRect.left = 0;
			mainRect.top = 0;
			mainRect.right = widht;
			mainRect.bottom = height;
			
			if (tempData == nullptr)
			{
				MessageBox(hWnd, (LPCWSTR)"Data is empty", 0, MB_OK);
				EndPaint(hWnd, &ps);
			}

			if (tempData->isGameOn != true)
				//тут будем рисовать заставку
				//пока просим начать игру
				MessageBox(hWnd, (LPCWSTR)L"Press play", (LPCWSTR)L"", MB_OK);
			else
			{
				y = tempData->fCurFigure->GetTop();
				x = tempData->fCurFigure->GetLeft();
				version = tempData->fCurFigure->GetCurVersion();

				//tempData->mpBoard->Draw(hDC, hWnd);
				tempData->fCurFigure->Draw(hDC, hWnd, version, x, y);
				//InvalidateRect(hWnd, NULL, FALSE);
				
			}

			EndPaint(hWnd, &ps);
        }
        break;
	case WM_TIMER:
		if (LOWORD(wParam) == 77&& tempData != nullptr)
		{
			MoveDown(hWnd, tempData);
		}
		break;
    case WM_DESTROY:
	{	
		//KillTimer(hWnd, 77);
		tempData->~DataForFunc();
		delete tempData;
		PostQuitMessage(0);
	}
		break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

//VOID CALLBACK Test (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

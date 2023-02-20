#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include<tchar.h>
#include<windows.h>

#define ID_EQUAL_BUTTON 1001
#define ID_CLEAR_BUTTON 1002
#define ID_PLUS_BUTTON 1003
#define ID_MINUS_BUTTON 1004
#define ID_MULTIPLY_BUTTON 1005
#define ID_DIVIDE_BUTTON 1006
#define ID_POINT_BUTTON 1007
#define ID_ZERO_BUTTON 1008
#define ID_ONE_BUTTON 1009
#define ID_TWO_BUTTON 1010
#define ID_THREE_BUTTON 1011
#define ID_FOUR_BUTTON 1012
#define ID_FIVE_BUTTON 1013
#define ID_SIX_BUTTON 1014
#define ID_SEVEN_BUTTON 1015
#define ID_EIGHT_BUTTON 1016
#define ID_NINE_BUTTON 1017
#define ID_NEGATE_BUTTON 1018
#define ID_BACKSPACE_BUTTON 1019
#define ID_TWOELEVATESQUAREROOT_BUTTON 1020
#define ID_TWOELEVATEX_BUTTON 1021
#define ID_CANCELENTRY_BUTTON 1022
#define ID_PORCENT_BUTTON 1023
#define ID_FRACTION_BUTTON 1024

HWND hwndButtonEqual;
HWND hwndButtonClear;
HWND hwndButtonPlus;
HWND hwndButtonMinus;
HWND hwndButtonMultiply;
HWND hwndButtonDivide;
HWND hwndButtonPoint;
HWND hwndButtonZero;
HWND hwndButtonOne;
HWND hwndButtonTwo;
HWND hwndButtonThree;
HWND hwndButtonFour;
HWND hwndButtonFive;
HWND hwndButtonSix;
HWND hwndButtonSeven;
HWND hwndButtonEight;
HWND hwndButtonNine;
HWND hwndEdit;
HWND hwndStatic;
HWND hwndButtonNegate;
HWND hwndButtonBackspace;
HWND hwndButtonTwoElevateSquareRoot;
HWND hwndButtoonTwoElevateX;
HWND hwndButtonCancelEntry;
HWND hwndButtonPorcent;
HWND hwndButtonFraction;

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
TCHAR szClassName[] = _T("Calculator");

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance,LPSTR lpszArgument, int nCmdShow){
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;

    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;                
    wincl.cbSize = sizeof(WNDCLASSEX);
    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx (&wincl)){
        return 0;
    }

    hwnd = CreateWindowEx (NULL, szClassName, _T("Caculadora"), WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 336, 518, HWND_DESKTOP, NULL, hThisInstance,NULL);
    ShowWindow (hwnd, nCmdShow);

    while (GetMessage (&messages, NULL, 0, 0)){
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
 switch (message)
    {
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case ID_EQUAL_BUTTON:
                {
                    //aqui você pode colocar a lógica para operação matemática
                    break;
                }
            }
            break;
        }
        case WM_DESTROY:
            PostQuitMessage (0);
            break;
        case WM_CREATE:
            hwndEdit = CreateWindowEx(WS_EX_CLIENTEDGE, _T("EDIT"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL, 3, 90, 323, 50, hwnd, NULL, GetModuleHandle(NULL), NULL);
            hwndButtonEqual = CreateWindowEx(NULL, _T("BUTTON"), _T("="), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            247, 435, 77, 50, hwnd, (HMENU)ID_EQUAL_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonPlus = CreateWindowEx(NULL, _T("BUTTON"), _T("+"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            247, 382, 77, 50, hwnd, (HMENU)ID_PLUS_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonMinus = CreateWindowEx(NULL, _T("BUTTON"), _T("-"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            247, 329, 77, 50, hwnd, (HMENU)ID_MINUS_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonMultiply = CreateWindowEx(NULL, _T("BUTTON"), _T("*"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            247, 276, 77, 50, hwnd, (HMENU)ID_MULTIPLY_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonDivide = CreateWindowEx(NULL, _T("BUTTON"), _T("/"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                            247, 223, 77, 50, hwnd, (HMENU)ID_DIVIDE_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonTwoElevateSquareRoot = CreateWindowEx(NULL, _T("BUTTON"), _T("2^Vx"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                            166, 223, 77, 50, hwnd, (HMENU)ID_TWOELEVATESQUAREROOT_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtoonTwoElevateX = CreateWindowEx(NULL, _T("BUTTON"), _T("X^2"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                            85, 223, 77, 50, hwnd, (HMENU)ID_TWOELEVATESQUAREROOT_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonFraction = CreateWindowEx(NULL, _T("BUTTON"), _T("1/x"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                            4, 223, 77, 50, hwnd, (HMENU)ID_FRACTION_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonClear = CreateWindowEx(NULL, _T("BUTTON"), _T("C"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                            166, 170, 77, 50, hwnd, (HMENU)ID_CLEAR_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonCancelEntry = CreateWindowEx(NULL, _T("BUTTON"), _T("CE"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                            85, 170, 77, 50, hwnd, (HMENU)ID_CANCELENTRY_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonPorcent = CreateWindowEx(NULL, _T("BUTTON"), _T("%"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                            4, 170, 77, 50, hwnd, (HMENU)ID_PORCENT_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonPoint = CreateWindowEx(NULL, _T("BUTTON"), _T("."), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            166, 435, 77, 50, hwnd, (HMENU)ID_POINT_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonZero = CreateWindowEx(NULL, _T("BUTTON"), _T("0"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            85, 435, 77, 50, hwnd, (HMENU)ID_ZERO_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonOne = CreateWindowEx(NULL, _T("BUTTON"), _T("1"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            4, 382, 77, 50, hwnd, (HMENU)ID_ONE_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonTwo = CreateWindowEx(NULL, _T("BUTTON"), _T("2"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                            85, 382, 77, 50, hwnd, (HMENU)ID_TWO_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonThree = CreateWindowEx(NULL, _T("BUTTON"), _T("3"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,    
                            166, 382, 77, 50, hwnd, (HMENU)ID_THREE_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonFour = CreateWindowEx(NULL, _T("BUTTON"), _T("4"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            4, 329, 77, 50, hwnd, (HMENU)ID_FOUR_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonFive = CreateWindowEx(NULL, _T("BUTTON"), _T("5"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            85, 329, 77, 50, hwnd, (HMENU)ID_FIVE_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonSix = CreateWindowEx(NULL, _T("BUTTON"), _T("6"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  
                            166, 329, 77, 50, hwnd, (HMENU)ID_SIX_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonSeven = CreateWindowEx(NULL, _T("BUTTON"), _T("7"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            4, 276, 77, 50, hwnd, (HMENU)ID_SEVEN_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonEight = CreateWindowEx(NULL, _T("BUTTON"), _T("8"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            85, 276, 77, 50, hwnd, (HMENU)ID_EIGHT_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonNine = CreateWindowEx(NULL, _T("BUTTON"), _T("9"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            166, 276, 77, 50, hwnd, (HMENU)ID_NINE_BUTTON, GetModuleHandle(NULL), NULL);
            hwndButtonBackspace = CreateWindowEx(NULL, _T("BUTTON"), _T("<-"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                            247, 170, 77, 50, hwnd, (HMENU)ID_BACKSPACE_BUTTON, GetModuleHandle(NULL), NULL);       
            hwndButtonNegate = CreateWindowEx(NULL, _T("BUTTON"), _T("+/-"), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
                    4, 435, 77, 50, hwnd, (HMENU)ID_NEGATE_BUTTON, GetModuleHandle(NULL), NULL);
            break;
        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

#include "MyWindow.h"
#include <iostream>
#include "define.h"
#include "SceneManager.h"
#define MAX_LOADSTRING 100
#define ID_INPUTNAME 11
#define ID_NAMEBUTTON 12


LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 전역 변수:
//HINSTANCE Window::hInst;
HWND Window::hWnd;
int Window::width, Window::height;
LPWSTR Window::title;

WCHAR szWindowClass[100];

bool Window::InitWindow() {
    return Window::InitWindow(hInst,L"Title");
}
bool Window::InitWindow(
    HINSTANCE hInstance,
    const WCHAR* Title,
    int Width, int Height
    
) {

    Window::width = Width;
    Window::height = Height;
    //lstrcpy(Window::title, Title);

    WNDCLASSEXW wcex;
    ZeroMemory(&wcex, sizeof(wcex));

    LoadStringW(hInstance, IDC_SOCKETPINGPONG, szWindowClass, MAX_LOADSTRING);

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_SOCKETPINGPONG));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_SOCKETPINGPONG);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));


    if (!RegisterClassExW(&wcex)) exit(-1);

    RECT rect = { 0, 0, width, height };
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
    Window::width = rect.right - rect.left;
    Window::height = rect.bottom - rect.top;

    hWnd = CreateWindowW(wcex.lpszClassName, Title, WS_OVERLAPPEDWINDOW,
        0, 0, Window::width, Window::height, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd) exit(-1);
    //Core::Instance()->Init(hWnd, POINT{ Window::width,Window::height });
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);
    
    return true;
}

HWND nameFieldWnd, nameBt;
/// //Proc
/*
static RECT rt;
const int nameField_x = 160;
const int nameField_y = 20;
const WCHAR* nameFieldText = L"닉네임:";
HWND nameFieldWnd, nameBt;
HDC hdc;
PAINTSTRUCT ps;

WCHAR name[24];
bool hasName;


int fps=120, frameCount=0;
//WCHAR timerStr[24];
RECT timerRt;
#define TIMERID_FPS_CHECK 101
#define TIMERID_FPS 102
*/
//HDC hdc;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    
    switch (message)
    {
    case WM_CREATE: {

        break;
    }

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case BUTTON_CREATEROOM:
            SceneManager::Instance()->ChangeScene(SCENE_TYPE::GAME);
            break;
        }
        break;
    }
    case WM_DESTROY:

        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    /*
    switch (message)
    {
    case WM_CREATE: {
        //프로그램 실행시. 닉네임 입력
        GetClientRect(hWnd, &rt);
        //name Input Field
        nameFieldWnd = CreateWindow(
            L"edit",
            NULL,
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
            rt.right / 2 - nameField_x / 2, rt.bottom / 2 - nameField_y / 2, nameField_x, nameField_y,
            hWnd,
            (HMENU)ID_INPUTNAME,
            hInst, NULL
        );
        SendMessage(nameFieldWnd, EM_LIMITTEXT, 23, 0); //입력 글자수 제한
        //// 시작후 동작
        //SetTimer(hWnd, TIMERID_FPS_CHECK, 1000, NULL);
        //SetTimer(hWnd, TIMERID_FPS, 1000/fps, NULL);
       // swprintf_s(timerStr, L"fps: %d", frameCount);
        timerRt = { rt.right - 100 , rt.top + 20 ,rt.right,rt.top + 40 };
        
        //==버튼
        nameBt = CreateWindow(
            L"button",
            L"확인",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            rt.right / 2 + nameField_x / 2 + 5, rt.bottom / 2 - nameField_y / 2,
            80, 20,
            hWnd,
            (HMENU)ID_NAMEBUTTON,
            hInst, NULL
        );
        hdc = GetDC(hWnd);
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    }
    case WM_TIMER:
    {
        switch (wParam) {
        case TIMERID_FPS:
            frameCount++;
            break;
        case TIMERID_FPS_CHECK:
            //swprintf_s(timerStr, L"fps: %d", frameCount);
            //hdc = GetDC(hWnd);
            SetTextAlign(hdc, TA_LEFT | TA_TOP);
           // TextOut(hdc, rt.right - 100, rt.top + 20, timerStr, wcslen(timerStr));
            
            ReleaseDC(hWnd, hdc);
            
            
            frameCount = 0;
            
            break;
        }
    }
    case WM_SIZE:
    {
        //창크기 변할때
        GetClientRect(hWnd, &rt);
        timerRt = { rt.right - 100 , rt.top + 20 ,rt.right,rt.top + 40 };
        
        SetWindowPos(nameFieldWnd, HWND_TOPMOST, rt.right / 2 - nameField_x / 2, rt.bottom / 2 - nameField_y / 2, nameField_x, nameField_y, SWP_NOZORDER);
        SetWindowPos(nameBt, HWND_TOPMOST, rt.right / 2 + nameField_x / 2 + 5, rt.bottom / 2 - nameField_y / 2,80, 20, SWP_NOZORDER);
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    }
    case WM_PAINT: {
        
        //hdc = BeginPaint(hWnd, &ps);
        SetTextAlign(hdc, TA_RIGHT | TA_TOP);
        TextOut(hdc, 1000, 600, nameFieldText, wcslen(nameFieldText));
        //if (hasName)TextOut(hdc, rt.right / 2 - nameField_x / 2 - 5, rt.bottom / 2 - nameField_y / 2, name, wcslen(name));
        //else TextOut(hdc, rt.right / 2 - nameField_x / 2 - 5, rt.bottom / 2 - nameField_y / 2, nameFieldText, wcslen(nameFieldText));
        SetTextAlign(hdc, TA_LEFT | TA_TOP);
        Rectangle(hdc, 1000, 300, 1100, 400);
        //TextOut(hdc, rt.right - 100, rt.top + 20, timerStr, wcslen(timerStr));
        //EndPaint(hWnd, &ps);
        

        
        break;
    }

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {

        case ID_NAMEBUTTON:
            GetWindowText(nameFieldWnd, name, sizeof(name));
            hasName = true;
    
            break;
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_DESTROY:
        KillTimer(hWnd, TIMERID_FPS_CHECK);
        KillTimer(hWnd, TIMERID_FPS);
        PostQuitMessage(0);
        ReleaseDC(hWnd, hdc);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    */
    return 0;
}

void Window::SetWidth(int width)
{
    Window::width = width;
}

void Window::SetHeight(int height)
{
    Window::height = height;
}

void Window::SetTitle(const WCHAR* Title)
{
    lstrcpy(Window::title, Title);
}

// 정보 대화 상자의 메시지 처리기입니다.
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

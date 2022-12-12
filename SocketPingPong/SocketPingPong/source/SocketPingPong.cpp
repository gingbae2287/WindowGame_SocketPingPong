// SocketChat.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

//#include "MyWindow.h"
#include "Core.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    if (!Window::InitWindow(hInstance, L"엔진테스트", 1280, 800)) {
        exit(-1);
    }
    if (FAILED((Core::Instance()->Init(Window::hWnd, POINT{ Window::Width(),Window::Height()})))) {
        MessageBox(nullptr, L"core 객체 초기화실패", L"error", MB_OK);
       return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SOCKETPINGPONG));

    MSG msg;


    // 기본 메시지 루프입니다:
    //GetMessage(&msg, nullptr, 0, 0)
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (WM_QUIT == msg.message) break;
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            
        }
        else {
            
        }
        Core::Instance()->Progress();
    }

    return (int) msg.wParam;
}






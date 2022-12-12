#include "Scene0.h"
#include "MyWindow.h"
#include "define.h"

void Scene0::Start() {
	button_test=CreateWindow(L"button", L"방만들기", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 1280 / 2 - 40, 200 - 20, 80, 40,
		Window::hWnd, (HMENU)BUTTON_CREATEROOM, hInst, NULL);
}
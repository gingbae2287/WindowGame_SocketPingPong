#include "Core.h"

int Core::Init(HWND HWnd, POINT Resolution) {
	//this->hWnd = hWnd;
	this->resolution = Resolution;
	rt = { 0,0,this->resolution.x,this->resolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	//SetWindowPos(hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);	//HWND_TOPMOST

	//Timer
	timerRt = { rt.right - 100 , rt.top + 20 ,rt.right,rt.top + 40 };

	hdc = GetDC(Window::hWnd);
	memDC = CreateCompatibleDC(hdc);
	backDC= CreateCompatibleDC(hdc);
	hBit = CreateCompatibleBitmap(hdc, resolution.x, resolution.y);
	oldBit = (HBITMAP)SelectObject(memDC, hBit);
	backBit= CreateCompatibleBitmap(hdc, resolution.x, resolution.y);
	backOldBit= (HBITMAP)SelectObject(backDC, backBit);
	FillRect(backDC, &rt, (HBRUSH)GetStockObject((WHITE_BRUSH)));

	swprintf_s(timerStr, L"fps: %d", fps);

	obj.transform.SetSize(100, 100);
	obj.transform.MoveTo(100, 100);
	
	return S_OK;
}
void Core::Progress() {
	
	Update();
	Render();
	frame++;
	sec += Time::deltaTime;
	if (sec < 1) return;
	sec--;
	fps = frame;
	swprintf_s(timerStr, L"fps: %d", fps);
	frame = 0;
	
	
	
}
void Core::Update() {
	Time::Instance()->Update();
	obj.Update();
	
	
}
void Core::Render() {
	BitBlt(memDC, 0, 0, resolution.x, resolution.y, backDC, 0, 0, SRCCOPY);
	//Rectangle(hdc,0, 0, 200, 200);
	//SetTextAlign(hdc, TA_LEFT | TA_TOP);
	obj.Render(memDC);
	TextOut(memDC, resolution.x-100, 30, timerStr, wcslen(timerStr));

	BitBlt(hdc, 0, 0, resolution.x, resolution.y, memDC, 0, 0, SRCCOPY);
}

Core::~Core() {
	SelectObject(memDC, oldBit);
	SelectObject(backDC, backOldBit);
	ReleaseDC(Window::hWnd, hdc);
	DeleteDC(memDC);
	DeleteDC(backDC);
	DeleteObject(hBit);
	DeleteObject(backBit);
}
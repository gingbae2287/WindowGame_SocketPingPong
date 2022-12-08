#include "Core.h"
#include "Player.h"
#include "ball.h"
Player a;
Ball b;
Core::Core()
	:hdc(0), memDC(0), hBit(0), oldBit(0), backBit(0), backOldBit(0)
{

	fps = 0; sec = 0; frame = 0; frameTime = 1 / 150.f; timeCount = 0;
}
int Core::Init(HWND HWnd, POINT Resolution) {
	//this->hWnd = hWnd;
	this->resolution = Resolution;
	rt = { 0,0,this->resolution.x,this->resolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	
	GDI::Instance()->Init();
	hdc = GetDC(Window::hWnd);
	memDC = CreateCompatibleDC(hdc);
	backDC= CreateCompatibleDC(hdc);
	hBit = CreateCompatibleBitmap(hdc, resolution.x, resolution.y);
	oldBit = (HBITMAP)SelectObject(memDC, hBit);
	backBit= CreateCompatibleBitmap(hdc, resolution.x, resolution.y);
	backOldBit= (HBITMAP)SelectObject(backDC, backBit);
	//==stock resources
	FillRect(backDC, &rt, (HBRUSH)GetStockObject((WHITE_BRUSH)));

	InitGDI();
	swprintf_s(fpsStr, L"fps: %d", fps);

	b.SetPos(1000, 600);
	a.SetPos(400, 600);
	return S_OK;
}
void Core::InitGDI() {
	
	
}
void Core::Progress() {
	
	Update();
	Render();
	frame++;
	sec += Time::deltaTime;
	if (sec < 1) return;
	sec--;
	fps = frame;
	swprintf_s(fpsStr, L"fps: %d", fps);
	frame = 0;
	
	
	
}
void Core::Update() {
	Time::Instance()->Update();
	
	a.Update();
	b.Update();
	ColliderManager::Instance()->Update();
	
}
void Core::Render() {
	BitBlt(memDC, 0, 0, resolution.x, resolution.y, backDC, 0, 0, SRCCOPY);
	//Rectangle(hdc,0, 0, 200, 200);
	//SetTextAlign(hdc, TA_LEFT | TA_TOP);
	TextOut(memDC, resolution.x-100, 30, fpsStr, wcslen(fpsStr));
	a.Render(memDC);
	b.Render(memDC);
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
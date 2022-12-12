
#include "Core.h"
#include "MyTools.h"

Core::Core()
	:hdc(0), memDC(0), hBit(0), oldBit(0), backBit(0), backOldBit(0)
{

	fps = 0; sec = 0; frame = 0; frameTime = 1 / 150.f; timeCount = 0;
}
int Core::Init(HWND HWnd, POINT Resolution) {
	this->resolution = Resolution;
	rt = { 0,0,this->resolution.x,this->resolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	

	GDI::Instance()->Init();
	SceneManager::Instance()->Init();
	NetworkManager::Instance()->Init();

	hdc = GetDC(Window::hWnd);
	memDC = CreateCompatibleDC(hdc);
	backDC= CreateCompatibleDC(hdc);
	hBit = CreateCompatibleBitmap(hdc, resolution.x, resolution.y);
	oldBit = (HBITMAP)SelectObject(memDC, hBit);
	backBit= CreateCompatibleBitmap(hdc, resolution.x, resolution.y);
	backOldBit= (HBITMAP)SelectObject(backDC, backBit);
	//==stock resources
	FillRect(backDC, &rt, (HBRUSH)GetStockObject((WHITE_BRUSH)));

	swprintf_s(fpsStr, L"fps: %d", fps);


	return S_OK;
}

void Core::Progress() {
	if (SceneManager::Instance()->IsStartScene()) return;
	if (!SceneManager::Instance()->isRun) return;
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
	SceneManager::Instance()->Update();
	
}
void Core::Render() {
	BitBlt(memDC, 0, 0, resolution.x, resolution.y, backDC, 0, 0, SRCCOPY);
	/// <summary>
	/// ¿©±â¿¡ render
	/// </summary>
	SceneManager::Instance()->Render(memDC);
	TextOut(memDC, resolution.x-100, 30, fpsStr, wcslen(fpsStr));

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
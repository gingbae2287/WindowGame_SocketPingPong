#pragma once
#include <windows.h>
#include "MyWindow.h"
#include <tchar.h>
#include "MyTools.h"

class Core
{
public:
	//Timer
	int fps,frame;
	float sec,frameTime,timeCount;
	WCHAR timerStr[24];
	RECT timerRt;

	//
	OBJ obj;
	//
	RECT rt;
	static Core* Instance() {
		static Core core;
		//MessageBox(nullptr, L"core °´Ã¼ »ý¼º", L"error", MB_OK);
		return &core;
	}
	
	int Init(HWND ,POINT);
	void Progress();

private:
	//HWND hWnd;
	HDC hdc,memDC,backDC;
	HBITMAP hBit,oldBit,backBit,backOldBit;
	POINT resolution;
	Core() { fps = 0; sec = 0; frame = 0; frameTime = 1 / 150.f; timeCount = 0; }
	~Core();
	void Update();
	void Render();
	
};


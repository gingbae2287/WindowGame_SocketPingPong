#pragma once

#include "MyWindow.h"



class Core
{
public:
	//Timer
	int fps,frame;
	float sec,frameTime,timeCount;
	WCHAR fpsStr[24];

	//
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

	

	Core();
	~Core();
	void Update();
	void Render();
	
};


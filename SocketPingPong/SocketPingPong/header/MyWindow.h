#pragma once
#include "framework.h"
#include "resource.h"
//#include "Core.h"
static HINSTANCE hInst;
//static HWND hWnd;
class Window
{
public:
	static HWND hWnd;
	static bool InitWindow();
	static bool InitWindow(
		HINSTANCE hInstance,
		const WCHAR* Title,
		int =1280, int Height=80
	);

	static int Width() { return width; }
	static void SetWidth(int width);

	static int Height() { return height; }
	static void SetHeight(int height);

	static LPWSTR Title() { return title; }
	static void SetTitle(const WCHAR* Title);
private:
	
	static int width, height;
	static LPWSTR title;

};


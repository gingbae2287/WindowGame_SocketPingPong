#pragma once
#include <windows.h>
#include "define.h"
class GDI
{
	SINGLETON(GDI)
private:
	GDI();
	~GDI();
	// GDI
	HBRUSH brushs[(UINT)BRUSH_TYPE::END];
	HPEN pens[(UINT)PEN_TYPE::END];
public:
	
	void Init();
	HBRUSH GetBrush(BRUSH_TYPE type) { return brushs[(UINT)type]; }
	HPEN GetPen(PEN_TYPE type) { return pens[(UINT)type]; }
	
	
	//GDI(HDC, BRUSH_TYPE);
	//GDI(HDC, PEN_TYPE);
};

class SelectGDI {
public:

	SelectGDI(HDC,BRUSH_TYPE);
	SelectGDI(HDC, PEN_TYPE);
	~SelectGDI();
private:
	HDC hdc;
	HPEN defaultPen;
	HBRUSH defaultBrush;
};


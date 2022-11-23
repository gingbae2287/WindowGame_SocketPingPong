#include "MyGDI.h"

SelectGDI::SelectGDI(HDC dc, BRUSH_TYPE brush_type)
:hdc(dc), defaultPen(nullptr), defaultBrush(nullptr)
{
	HBRUSH brush = GDI::Instance()->GetBrush(brush_type);
	defaultBrush = (HBRUSH)SelectObject(dc, brush);
}
SelectGDI::SelectGDI(HDC dc, PEN_TYPE pen_type)
	:hdc(dc), defaultPen(nullptr), defaultBrush(nullptr)
{
	HPEN pen = GDI::Instance()->GetPen(pen_type);
	defaultPen = (HPEN)SelectObject(dc, pen);
}
SelectGDI::~SelectGDI() {
	//임시객체로 생성하여 stack에 할당되고 함수 종료시 해제되는 성질 이용.
	SelectObject(hdc, defaultBrush);
	SelectObject(hdc, defaultPen);
}
GDI::GDI()
:brushs{}, pens{} 
{

}
void GDI::Init() { 
	//hdc = dc; 

	brushs[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	pens[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	pens[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	pens[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}
GDI::~GDI() {
	for (int i = 0; i < (UINT)PEN_TYPE::END; i++) DeleteObject(pens[i]);
}
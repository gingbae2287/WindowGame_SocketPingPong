#include "Wall.h"
#include "MyGDI.h"
Wall::Wall() {
	CreateCollider(BOX);
}



void Wall::Render(HDC hdc) {
	SelectGDI tmpGdi(hdc, PEN_TYPE::HOLLOW);
	SelectGDI tmpGdi2(hdc, BRUSH_TYPE::BLACK);
	Rectangle(
		hdc,
		transform.pos.x - transform.size.hx,
		transform.pos.y - transform.size.hy,
		transform.pos.x + transform.size.hx,
		transform.pos.y + transform.size.hy);
}
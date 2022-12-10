#include "Wall.h"
Wall::Wall() {
	CreateCollider(BOX);
}



void Wall::Render(HDC hdc) {
	SelectGDI tmpGdi2(hdc, BRUSH_TYPE::YELLOW);
	Rectangle(
		hdc,
		transform.pos.x - transform.size.hx,
		transform.pos.y - transform.size.hy,
		transform.pos.x + transform.size.hx,
		transform.pos.y + transform.size.hy);
}
#pragma once
#include "OBJ.h"
#include "MyGDI.h"
class Collider {
private:
	OBJ* owner;
	friend class OBJ;
	Vector2 offset;
	Vector2 pos;
	Size size;
public:
	
	//==state var
	bool enable;
	//OBJ* obj; //부모 오브젝트
	
	Collider() {
		enable = true;
		offset = { 0,0 };
		size.SetSize(120, 80);
		//owner = nullptr;

	}
	void Update() {
		if (owner == nullptr) return;
		pos = owner->GetPosition() + offset;
	}
	void Render(HDC hdc) {
		if (!enable) return;
		SelectGDI tmpGdi(hdc, PEN_TYPE::GREEN);
		SelectGDI tmpGdi2(hdc, BRUSH_TYPE::HOLLOW);
		Rectangle(
			hdc,
			pos.x - size.hx,
			pos.y - size.hy,
			pos.x +size.hx,
			pos.y + size.hy);
	}
	~Collider() {}
};
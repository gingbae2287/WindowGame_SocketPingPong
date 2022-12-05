#pragma once
#include "OBJ.h"

class Player :public OBJ {
private:
	const float speed = 300;
public:
	//BoxCollider* col = new BoxCollider;
	Player();
	~Player();
	virtual void Update() {
		/*if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			transform.pos.x -= speed * Time::deltaTime;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			transform.pos.x += speed * Time::deltaTime;
		}*/
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			transform.pos.y -= speed * Time::deltaTime;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			transform.pos.y += speed * Time::deltaTime;
		}
		if (collider) collider->Update();
		//col->Update();
	}

	virtual void Render(HDC hdc) {
		if (!isActive) return;
		//object render
		Rectangle(
			hdc,
			transform.pos.x - transform.size.hx,
			transform.pos.y - transform.size.hy,
			transform.pos.x + transform.size.hx,
			transform.pos.y + transform.size.hy);
		//component render====
		if (collider) collider->Render(hdc);
		//col->Render(hdc);
	}
};
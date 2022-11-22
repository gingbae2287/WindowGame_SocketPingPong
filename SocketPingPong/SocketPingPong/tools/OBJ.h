#pragma once
#include "Transform.h"
#include <Windows.h>
#include "GingTime.h""
class OBJ
{
public:
	Transform transform;
	//HDC *hdc;
	//OBJ(HDC *hdc) { this->hdc = hdc; }
	//OBJ(HDC* hdc, int X, int Y) { this->hdc = hdc; transform.position.MoveTo(X, Y); }
	//HDC hdc;
	OBJ() {}
	//OBJ(HDC hdc) { this->hdc = hdc; }
	//void Init(HDC hdc) { this->hdc = hdc; }
	~OBJ() {
		//hdc = nullptr;
	}
	void Update() {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			transform.position.x -= 100*Time::deltaTime;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			transform.position.x += 100 * Time::deltaTime;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			transform.position.y -= 100 * Time::deltaTime;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			transform.position.y += 100 * Time::deltaTime;
		}
	}
	void Render(HDC hdc) {
		Rectangle(
			hdc,
			transform.position.x - transform.size.hx,
			transform.position.y - transform.size.hy,
			transform.position.x + transform.size.hx,
			transform.position.y + transform.size.hy );
	}

private:
};


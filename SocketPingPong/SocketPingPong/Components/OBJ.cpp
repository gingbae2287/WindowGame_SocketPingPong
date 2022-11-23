#include "OBJ.h"
#include "Collider.h"
void OBJ::CreateCollider() {
	if (collider != nullptr) return;
	collider = new Collider;
	collider->owner = this;
}

void OBJ::Update() {
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		transform.pos.x -= speed * Time::deltaTime;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		transform.pos.x += speed * Time::deltaTime;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		transform.pos.y -= speed * Time::deltaTime;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		transform.pos.y += speed * Time::deltaTime;
	}
	if (collider) collider->Update();
}
void OBJ::Render(HDC hdc) {
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
}

OBJ::~OBJ() {
	if (collider != nullptr) delete collider;
}
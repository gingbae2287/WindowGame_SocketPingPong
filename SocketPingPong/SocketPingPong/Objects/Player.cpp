#include "Player.h"
#include "SceneManager.h"
#include "GingTime.h"
#include "MyGDI.h"
Player::Player() {
	SetSize(100, 100);
	CreateCollider(ColliderType::BOX);

	//swprintf_s(text, L"충돌 없음");
	isCollision = false;
	
}

Player::~Player() {
	//delete(col);
}

void Player::Update() {
	if (!isActive) return;
	
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
	//if (rigid) rigid->Update();
	//if (collider) collider->Update();

	//col->Update();
}

void Player::Render(HDC hdc){
	if (!isActive) return;
	//object render
	SelectGDI tmpGdi2(hdc, BRUSH_TYPE::YELLOW);
	Rectangle(
		hdc,
		transform.pos.x - transform.size.hx,
		transform.pos.y - transform.size.hy,
		transform.pos.x + transform.size.hx,
		transform.pos.y + transform.size.hy);
	//component render====
	//if (collider) collider->Render(hdc);

	//TextOut(hdc, 1280/2, 100, text, wcslen(text));
	//col->Render(hdc);
}

void Player::OnCollisionEnter(Collider* other)
{
	if (!isCollision) {
		isCollision = true;
		//swprintf_s(text, L"충돌중!!!");
	}
}
void Player::OnCollisionStay(Collider* other)
{

}
void Player::OnCollisionExit(Collider* other)
{
	if (isCollision) {
		isCollision = false;
		//swprintf_s(text, L"충돌 없음");
	}


}
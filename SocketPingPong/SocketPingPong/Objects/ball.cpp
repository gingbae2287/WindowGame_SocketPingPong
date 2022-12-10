#include "ball.h"

Ball::Ball():
isCollision(false)
{
	colCount = 0;
	swprintf_s(text, L"Ãæµ¹È½¼ö: %d", colCount);
	r = 30;
	speed = 200; 
	
	CreateCollider(ColliderType::CIRCLE);
	CreateRigidbody();
	((CircleCollider*)collider)->SetRadius(r-10);
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 100);
	int rand = dis(gen);
	if (rand % 2) rigid->vel = { speed * (-1),(float)rand };
	else rigid->vel = { speed ,(float)rand };
	
	
}
void Ball::Update() {
	//if (collider) collider->Update();
	if (rigid) rigid->Update();
}
void Ball::Render(HDC hdc){
	Ellipse(hdc, transform.pos.x - r, transform.pos.y - r, transform.pos.x + r, transform.pos.y + r);
	if (collider) collider->Render(hdc);

	TextOut(hdc, 1280 / 2, 100, text, wcslen(text));
}

void Ball::OnCollisionEnter(Collider* other)
{
	if (!isCollision) {
		isCollision = true;
		colCount++;
		swprintf_s(text, L"Ãæµ¹È½¼ö: %d",colCount);
	}
}
void Ball::OnCollisionStay(Collider* other)
{

}
void Ball::OnCollisionExit(Collider* other)
{
	if (isCollision) {
		isCollision = false;
		//swprintf_s(text, L"Ãæµ¹ ¾øÀ½");
	}


}
#include "OBJ.h"
//#include "Rigidbody.h"
Rigidbody::Rigidbody():
	freezeX(false),freezeY(false), isReaction(false)
{
	mass = 1;
	vel = { 0,0 };
	
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::Update() {
	if (vel == 0) return;
	owner->transform.pos += vel * Time::deltaTime;
}
void Rigidbody::Collision(Collider* other) {

	if (owner->GetCollider() == nullptr) return;
	ColliderType type = owner->GetCollider()->colType;
	ColliderType type2 = other->colType;
	Vector2 pos1, pos2;
	//충돌시에만 호출되므로 충돌조건을 만족한다고 가정
	//한쪽만 rigidbody가 있는 상황만 구현
	if (type == ColliderType::CIRCLE && type2 == ColliderType::BOX) {
		CircleCollider* cir = (CircleCollider * )owner->GetCollider();
		BoxCollider* box = (BoxCollider*)other;
		pos1 = cir->GetPos();
		pos2 = box->GetPos();
		if ((pos1.x - pos2.x) * (pos1.x - pos2.x) > (box->size.hx * box->size.hx)) {
			//(pos1.x-pos2.x) 방향으로 x축 속도 전환 =>튕긴거니 x축속도 부호변경
			vel.x *= -1;
		}
		if ((pos1.y - pos2.y) * (pos1.y - pos2.y) > (box->size.hy * box->size.hy)) {
			//(pos1.y-pos2.y) 방향으로 y축 속도 전환 =>튕긴거니 y축속도 부호변경
			vel.y *= -1;
		}
	}

}

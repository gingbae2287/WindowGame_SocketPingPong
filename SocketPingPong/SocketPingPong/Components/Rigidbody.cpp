#include "Rigidbody.h"
#include "GingTime.h"
#include "Collider.h"

#include "OBJ.h"
#include <cmath>
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
	//�浹�ÿ��� ȣ��ǹǷ� �浹������ �����Ѵٰ� ����
	//���ʸ� rigidbody�� �ִ� ��Ȳ�� ����
	if (type == ColliderType::CIRCLE && type2 == ColliderType::BOX) {
		CircleCollider* cir = (CircleCollider * )owner->GetCollider();
		BoxCollider* box = (BoxCollider*)other;
		pos1 = cir->GetPos();
		pos2 = box->GetPos();
		/*
		if (pos1.x > pos2.x - box->size.hx && pos1.x < pos2.x + box->size.hx) {
			//���� �߽� x��ǥ�� �簢�� ���� ���� �����϶�
			
			//(pos1.y-pos2.y) �������� y�� �ӵ� ��ȯ 
			if (pos1.y > pos2.y) vel.y = abs(vel.y);
			else if (pos1.y < pos2.y) vel.y = (-1) * abs(vel.y);
		}
		if (pos1.y > pos2.y - box->size.hy && pos1.y < pos2.y + box->size.hy) {
			if (pos1.x > pos2.x) vel.x = abs(vel.x);
			else if (pos1.x < pos2.x) vel.x = (-1) * abs(vel.x);
		}*/
		
		if ((pos1.x - pos2.x) * (pos1.x - pos2.x) > (box->size.hx * box->size.hx)) {
			//(pos1.x-pos2.x) �������� x�� �ӵ� ��ȯ
			if (pos1.x > pos2.x) vel.x = abs(vel.x);
			else if(pos1.x<pos2.x) vel.x = (-1)*abs(vel.x);
		}

		if ((pos1.y - pos2.y) * (pos1.y - pos2.y) > (box->size.hy * box->size.hy)) {
				//y���� �浹: ���� �߽��� �簢�� ���϶�
			//(pos1.y-pos2.y) �������� y�� �ӵ� ��ȯ =>ƨ��Ŵ� y��ӵ� ��ȣ����
			if (pos1.y > pos2.y) vel.y = abs(vel.y);
			else if (pos1.y < pos2.y) vel.y = (-1) * abs(vel.y);
		}
	}

}

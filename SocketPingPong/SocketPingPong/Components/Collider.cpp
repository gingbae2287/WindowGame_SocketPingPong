
#include "OBJ.h"

void ColliderManager::NewCollider(Collider* col) {
	colliders.push_back(col);
}

void ColliderManager::DeleteCollider(Collider* col) {
	for (std::vector<Collider*>::iterator it = colliders.begin(); it != colliders.end(); it++) {
		if (*it == col) {
			colliders.erase(it);
			break;
		}
	}
}

void ColliderManager::Update() {
	if (colliders.size() < 2) return;
	for (std::vector<Collider*>::iterator it = colliders.begin(); it != colliders.end() - 1; it++) {
		if (!(*it)->enable) continue;
		//충돌인지 판별후, Oncollision은 collider enter인 경우만 다룸.
		for (std::vector<Collider*>::iterator it2 = it + 1; it2 != colliders.end(); it2++) {
			if (!(*it2)->enable) continue;
			if (!CheckCollision(*it, *it2)) continue;
			(*it)->OnCollision(*it2);
			(*it2)->OnCollision(*it);
		}

		(*it)->CheckCollisionState();
		//이미 충돌했던 것들을 검사해 stay, exit 경우 체크
	}
}
bool ColliderManager::CheckCollision(Collider* col1, Collider* col2) {
	if (col1->colType == CIRCLE && col2->colType == CIRCLE) {
		CircleCollider* cir1 = (CircleCollider*)col1;
		CircleCollider* cir2 = (CircleCollider*)col2;
		float r1 = cir1->GetRadius();
		float r2 = cir2->GetRadius();
		return (r1 + r2) * (r1 + r2)
			>= (cir1->GetPos() - cir2->GetPos()).sqrMagnitude();
	}

	else if (col1->colType == CIRCLE && col2->colType == BOX) {
		CircleCollider* cir1 = (CircleCollider*)col1;
		BoxCollider* box1 = (BoxCollider*)col2;
		float r1 = cir1->GetRadius();
		return (r1 + box1->hWidth()) >= (cir1->GetPos().x - box1->GetPos().x) && (r1 + box1->hHeight()) >= (cir1->GetPos().y - box1->GetPos().y);
	}
	else if (col1->colType == BOX && col2->colType == CIRCLE) {
		CircleCollider* cir1 = (CircleCollider*)col2;
		BoxCollider* box1 = (BoxCollider*)col1;
		float r1 = cir1->GetRadius();
		return (r1 + box1->hWidth()) >= (cir1->GetPos().x - box1->GetPos().x) && (r1 + box1->hHeight()) >= (cir1->GetPos().y - box1->GetPos().y);
	}

	else if (col1->colType == BOX && col2->colType == BOX) {
		BoxCollider* box1 = (BoxCollider*)col1;
		BoxCollider* box2 = (BoxCollider*)col2;
		float w1 = box1->hWidth();
		float w2 = box2->hWidth();
		float h1 = box1->hHeight();
		float h2 = box2->hHeight();
		if (box1->GetPos().x - w1<box2->GetPos().x + w2 &&
			box1->GetPos().x + w1 > box2->GetPos().x - w2 &&
			box1->GetPos().y - h1 < box2->GetPos().y + h2 &&
			box1->GetPos().y + h1 > box2->GetPos().y - h2)	return true;



	}
	return false;
}

void Collider::OnCollision(Collider* other) {
	if (!isCollision) {
		curCollisions.push_back(other);
		isCollision = true;
		return;
	}
	auto it = find(curCollisions.begin(), curCollisions.end(), other);
	if (it == curCollisions.end()) {
		//전프레임에 other와 충돌 x
		curCollisions.push_back(other);
		//this collider의 owner만 호출한다. (othercollider에서도 똑같은 작업이 manager에서 호출된다)
		owner->OnCollisionEnter(other);
	}
}
void Collider::CheckCollisionState() {
	//exit의 경우 vector erase를 하므로 for문 조건식 끝에 ++을 안씀
	for (std::vector<Collider*>::iterator it = curCollisions.begin(); it != curCollisions.end();) {
		if (ColliderManager::Instance()->CheckCollision(this, *it)) {
			owner->OnCollisionStay(*it);
			it++;
		}
		else {
			owner->OnCollisionExit(*it);
			curCollisions.erase(it);
		}
	}
	if (curCollisions.empty()) isCollision = false;
}



Collider::Collider()
:isCollision(false), enable(true)
{
	
	offset = { 0,0 };
	ColliderManager::Instance()->NewCollider(this);
	//owner = nullptr;
}

Collider::~Collider() {
	ColliderManager::Instance()->DeleteCollider(this);
}
void Collider::Update() {
	if (owner == nullptr) return;
	pos = owner->GetPosition() + offset;
}

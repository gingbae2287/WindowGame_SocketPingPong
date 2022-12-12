
#include "Collider.h"
#include "Rigidbody.h"
#include "OBJ.h"
#include "Scene.h"
#include "SceneManager.h"
#include "MyGDI.h"


ColliderManager::ColliderManager()
:curScene(nullptr)
{

}
void ColliderManager::Update() {
	if (curScene->colliders.size() < 2) return;
	for (std::vector<Collider*>::iterator it = curScene->colliders.begin(); it != curScene->colliders.end() - 1; it++) {
		if (!(*it)->enable) continue;
		//충돌인지 판별후, Oncollision은 collider enter인 경우만 다룸.
		for (std::vector<Collider*>::iterator it2 = it + 1; it2 != curScene->colliders.end(); it2++) {
			if (!(*it2)->enable) continue;
			if (!CheckCollision(*it, *it2)) continue;
			(*it)->OnCollision(*it2);
			(*it2)->OnCollision(*it);
		}
	}
	for (std::vector<Collider*>::iterator it = curScene->colliders.begin(); it != curScene->colliders.end(); it++) (*it)->Update();
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
		return (r1 + box1->hWidth())* (r1 + box1->hWidth()) >= (cir1->GetPos().x - box1->GetPos().x) * (cir1->GetPos().x - box1->GetPos().x) && 
			(r1 + box1->hHeight())* (r1 + box1->hHeight()) >= (cir1->GetPos().y - box1->GetPos().y) * (cir1->GetPos().y - box1->GetPos().y);
	}
	else if (col1->colType == BOX && col2->colType == CIRCLE) {
		CircleCollider* cir1 = (CircleCollider*)col2;
		BoxCollider* box1 = (BoxCollider*)col1;
		float r1 = cir1->GetRadius();
		return (r1 + box1->hWidth()) * (r1 + box1->hWidth()) >= (cir1->GetPos().x - box1->GetPos().x) * (cir1->GetPos().x - box1->GetPos().x) &&
			(r1 + box1->hHeight()) * (r1 + box1->hHeight()) >= (cir1->GetPos().y - box1->GetPos().y) * (cir1->GetPos().y - box1->GetPos().y);
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
		isCollision = true;
		//this collider의 owner만 호출한다. (othercollider에서도 똑같은 작업이 manager에서 호출된다)
		//OnColliderEnter
		curCollisions.push_back(other);
		if (owner->GetRigidbody() != nullptr) owner->GetRigidbody()->Collision(other);
		owner->OnCollisionEnter(other);
		///======
		return;
	}
	auto it = find(curCollisions.begin(), curCollisions.end(), other);
	if (it == curCollisions.end()) {
		//전프레임에 other와 충돌 x
		//OnColliderEnter
		curCollisions.push_back(other);
		if (owner->GetRigidbody() != nullptr) owner->GetRigidbody()->Collision(other);
		owner->OnCollisionEnter(other);
		///======
		
	}
	
}
void Collider::CheckCollisionState() {
	//collider의 stay, exit 판별
	//exit의 경우 vector erase를 하므로 for문 조건식 끝에 ++을 안씀
	
	if (curCollisions.empty()) return;
	for (std::vector<Collider*>::iterator it = curCollisions.begin(); it != curCollisions.end();) {

		if (ColliderManager::Instance()->CheckCollision(this, *it)) {
			if (owner->GetRigidbody()!=nullptr) owner->GetRigidbody()->Collision(*it);
			owner->OnCollisionStay(*it);
			++it;
		}
		
		else {
			owner->OnCollisionExit(*it);
			it=curCollisions.erase(it);
		}
	}
	if (curCollisions.empty()) isCollision = false;
	
}



Collider::Collider()
:isCollision(false), enable(true),owner(nullptr),colType()
{
	
	offset = { 0,0 };
}

Collider::~Collider() {
	owner->GetObjectScene()->DeleteCollider(this);
}
void Collider::Update() {
	if (owner == nullptr) return;
	pos = owner->GetPosition() + offset;
	CheckCollisionState();
}


void Collider::SetSize(Vector2 v) {
	size.SetSize(v);
}
void Collider::SetSize(int x, int y) {
	size.SetSize(x, y);
}

void BoxCollider::Render(HDC hdc) {
	if (!enable) return;
	SelectGDI tmpGdi(hdc, PEN_TYPE::GREEN);
	SelectGDI tmpGdi2(hdc, BRUSH_TYPE::HOLLOW);
	Rectangle(
		hdc,
		pos.x - size.hx,
		pos.y - size.hy,
		pos.x + size.hx,
		pos.y + size.hy);
}

void CircleCollider::Render(HDC hdc) {
	if (!enable) return;
	SelectGDI tmpGdi(hdc, PEN_TYPE::GREEN);
	SelectGDI tmpGdi2(hdc, BRUSH_TYPE::HOLLOW);
	//Ellipse(hdc, pos.x - r, pos.y - r, pos.x + r, pos.y + r);
	Ellipse(hdc, pos.x - size.hx, pos.y - size.hx, pos.x + size.hx, pos.y + size.hx);
}

void CircleCollider::SetSize(Vector2 v) {
	size.SetSize(v.x,v.x);
	r = v.x / 2;
}
void CircleCollider::SetSize(int x, int y) {
	size.SetSize(x, x);
	r = x / 2;
}
float CircleCollider::GetRadius() { 
	return size.hx;
}
void CircleCollider::SetRadius(int r2) {
	size = { 2*r2,2*r2 }; 
	r = r2;
}
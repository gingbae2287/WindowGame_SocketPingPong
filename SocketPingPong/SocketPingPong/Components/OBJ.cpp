#include "OBJ.h"
//#include "Collider.h"
OBJ::OBJ() {
	collider = nullptr;
	isActive = true;
}
void OBJ::CreateCollider(ColliderType type= ColliderType::BOX) {
	if (collider != nullptr) return;
	if(type==BOX) collider = new BoxCollider;
	if(type==CIRCLE) collider = new CircleCollider;
	collider->owner = this;
}

void OBJ::CreateRigidbody() {
	if (rigid != nullptr) return;
	rigid = new Rigidbody;
	rigid->owner = this;
}

void OBJ::Collision(Collider* other) {
	OnCollision(other);
	if (rigid != nullptr) rigid->Collision(other);
}

OBJ::~OBJ() {
	if (collider != nullptr) delete collider;
	if (rigid != nullptr) delete rigid;
}

void OBJ::SetSize(int x, int y) {
	transform.size = { x,y };
}

void OBJ::SetPos(float x, float y) {
	transform.pos = { x,y };
}
void OBJ::SetPos(Vector2 v) {
	transform.pos = { v.x,v.y };
}
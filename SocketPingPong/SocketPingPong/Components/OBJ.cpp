#include "OBJ.h"
#include "SceneManager.h"
#include "Scene.h"
OBJ::OBJ() 
:collider(nullptr), rigid(nullptr), isActive(true),scene(nullptr)
{
	//SceneManager::Instance()->AddObject(this);
	//scene = SceneManager::Instance()->curScene;
}
/*
OBJ::OBJ(SCENE_TYPE SceneNum)
	:collider(nullptr), rigid(nullptr), isActive(true)
{
	SceneManager::Instance()->AddObject(this, SceneNum);
	scene = SceneManager::Instance()->curScene;
}*/

OBJ::~OBJ() {
	if (collider != nullptr) delete collider;
	if (rigid != nullptr) delete rigid;
	scene->DeleteObject(this);
}

Scene* OBJ::GetObjectScene() {
	return scene;
}
void OBJ::CreateCollider(ColliderType type= ColliderType::BOX) {
	if (collider != nullptr) return;
	if(type==BOX) collider = new BoxCollider;
	if(type==CIRCLE) collider = new CircleCollider;
	collider->owner = this;
	if(scene!=nullptr) scene->AddCollider(collider);

	collider->SetSize(transform.size.x+10,transform.size.y+10);
}

void OBJ::DeleteCollider() {
	if (collider == nullptr) return;
	scene->DeleteCollider(collider);
	delete(collider);
	collider = nullptr;
}

void OBJ::CreateRigidbody() {
	if (rigid != nullptr) return;
	rigid = new Rigidbody;
	rigid->owner = this;
}



void OBJ::SetSize(int x, int y) {
	transform.size = { x,y };
}
Vector2 OBJ::GetSize() {
	return { transform.size.x,transform.size.y };
}

void OBJ::SetPos(float x, float y) {
	transform.pos = { x,y };
}
void OBJ::SetPos(Vector2 v) {
	transform.pos = { v.x,v.y };
}
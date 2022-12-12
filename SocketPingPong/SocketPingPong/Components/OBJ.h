#pragma once
//
//#include "Component.h"
#include "Transform.h"
#include <windows.h>
//class Collider;
class Scene;
class Collider;
class Rigidbody;
enum ColliderType;
class OBJ
{
	
protected:
	friend class Scene;
	Scene* scene;
	//==state var
	
	//===component==
	Collider* collider;
	Rigidbody* rigid;
public:
	//===state func
	Scene* GetObjectScene();
	bool isActive;
	void SetActive(bool act) { isActive = act; }

	Transform transform;
	//==component func
	//collider
	void CreateCollider(ColliderType);
	Collider* GetCollider() { return collider; }
	void DeleteCollider();

	//Rigidbody
	void CreateRigidbody();
	Rigidbody* GetRigidbody() { return rigid; }
	
public:
	

	OBJ();
	//OBJ(SCENE_TYPE);
	~OBJ();
	Vector2 GetPosition() { return transform.GetPosition(); }
	virtual void Update() = 0;
		
	virtual void Render(HDC) = 0;

	virtual void OnCollisionEnter(Collider* other) {}
	virtual void OnCollisionStay(Collider* other) {}
	virtual void OnCollisionExit(Collider* other) {}

	void SetSize(int, int);
	Vector2 GetSize();
	void SetPos(float, float);
	void SetPos(Vector2);
	
	
	
};


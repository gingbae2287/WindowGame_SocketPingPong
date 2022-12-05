#pragma once
//#include "Transform.h"
//#include <Windows.h>
#include "GingTime.h"
#include "Component.h"
//class Collider;
enum ColliderType;
class OBJ
{
protected:
	//==state var
	bool isActive;
	
	

	//===component==
	Collider* collider;
public:
	
	//===state func
	void SetActive(bool act) { isActive = act; }
	//==component func
	void CreateCollider(ColliderType);
public:
	Transform transform;

	OBJ();
	Vector2 GetPosition() { return transform.GetPosition(); }
	virtual void Update() {}
		
	virtual void Render(HDC) {}

	void SetSize(int, int);
	void SetPos(float, float);
	void SetPos(Vector2);
	~OBJ();
	
	
};


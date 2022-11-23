#pragma once
#include "Transform.h"
//#include <Windows.h>
#include "GingTime.h"

class Collider;
class OBJ
{
private:
	//==state var
	bool isActive;
	
	

	//===component==
	Collider* collider;
public:
	
	//===state func
	void SetActive(bool act) { isActive = act; }
	//==component func
	void CreateCollider();
public:
	Transform transform;

	OBJ() {
		collider = nullptr;
		isActive = true;
	}
	Vector2 GetPosition() { return transform.GetPosition(); }
	void Update();
		
	void Render(HDC);
	~OBJ();

	
private:
	const int speed = 300;
	
	
};


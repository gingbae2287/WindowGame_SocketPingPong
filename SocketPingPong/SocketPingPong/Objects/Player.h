#pragma once
#include "OBJ.h"

class Player :public OBJ {
private:
	const float speed = 300;
	//WCHAR text[48];
	bool isCollision;
	
public:
	//BoxCollider* col = new BoxCollider;
	Player();
	~Player();
	virtual void Update();
	virtual void Render(HDC);

	void OnCollisionEnter(Collider*);
	void OnCollisionStay(Collider*);
	void OnCollisionExit(Collider*);
};
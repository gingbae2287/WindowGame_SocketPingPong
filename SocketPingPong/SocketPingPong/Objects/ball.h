#pragma once
#include "OBJ.h"
#include <windows.h>
#include <random>
class Ball :public OBJ {
private:
	bool isCollision;
	//WCHAR text[48];
	int colCount;
public:
	int r;
	float speed;
	Ball();
	virtual void Update();
	virtual void Render(HDC hdc);

	void OnCollisionEnter(Collider*);
	void OnCollisionStay(Collider*);
	void OnCollisionExit(Collider*);
};
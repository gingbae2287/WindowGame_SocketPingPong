#pragma once
#include "OBJ.h"
#include <random>
class Ball :public OBJ {
public:
	int r;
	float speed;
	Ball();
	~Ball();
	virtual void Update();
	virtual void Render(HDC hdc) {
		Ellipse(hdc, transform.pos.x - r, transform.pos.y - r, transform.pos.x + r, transform.pos.y + r);
		if (collider) collider->Render(hdc);
	}
};
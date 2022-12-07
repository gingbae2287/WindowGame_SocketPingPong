#pragma once
#include "Vector2.h"
class OBJ;
class Collider;
class Rigidbody {
public:
	float mass;
	Vector2 vel;
	bool freezeX, freezeY;
	Rigidbody();
	~Rigidbody();
	void Collision(Collider*);

	void Update();

private:
	OBJ* owner;
	friend class OBJ;
	friend class Collider;
	
	bool isReaction;
};
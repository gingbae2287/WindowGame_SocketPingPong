#pragma once
//#include "OBJ.h"
#include "MyGDI.h"
#include "Transform.h"
#include <vector>
#include <algorithm>
class OBJ;
class Collider;
class Rigidbody;
enum ColliderType {
	BOX,
	CIRCLE,
};
class ColliderManager {
	SINGLETON(ColliderManager)
public:
	void NewCollider(Collider*);
	void DeleteCollider(Collider*);
	bool CheckCollision(Collider*, Collider*);
	void Update();
private:
	std::vector<Collider*> colliders;
	ColliderManager() {
		colliders.reserve(20);
	}

};
class Collider {
protected:
	OBJ* owner;
	friend class OBJ;
	friend class Rigidbody;
	Vector2 offset;
	Vector2 pos;
	
	friend class ColliderManager;
	
public:
	//==state var
	ColliderType colType;
	bool enable;
	//collision 판정 관련
	std::vector<Collider*> curCollisions;
	bool isCollision;
	void CheckCollisionState();
	void OnCollision(Collider*);
	/// 
	Collider();
	void Update();
	virtual void Render(HDC hdc) = 0;
	~Collider();
	Vector2 GetPos() { return pos; }

};

class BoxCollider :public Collider {
private:
	
public:
	Size size;
	BoxCollider() {
		size.SetSize(120, 80);
		colType = BOX;
		
	}
	virtual void Render(HDC hdc) {
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
	float Width() { return size.x; }
	float hWidth() { return size.hx; }
	float Height() { return size.y; }
	float hHeight() { return size.hy; }
};

class CircleCollider :public Collider {
private:
	
public:
	float r;
	CircleCollider() {
		r = 100;
		colType = CIRCLE;
	}
	virtual void Render(HDC hdc) {
		if (!enable) return;
		SelectGDI tmpGdi(hdc, PEN_TYPE::GREEN);
		SelectGDI tmpGdi2(hdc, BRUSH_TYPE::HOLLOW);
		Ellipse(hdc, pos.x - r, pos.y - r, pos.x + r, pos.y + r);
	}
	float GetRadius() {return r;}
	void SetRadius(float r2) {r = r2;}
};

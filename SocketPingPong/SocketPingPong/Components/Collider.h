#pragma once
//#include "OBJ.h"
#include "MyGDI.h"
#include "Transform.h"
#include <vector>
#include <algorithm>
class OBJ;
class Collider;
class Rigidbody;
class Scene;
enum ColliderType {
	BOX,
	CIRCLE,
};
class ColliderManager {
	SINGLETON(ColliderManager)
public:
	bool CheckCollision(Collider*, Collider*);
	void Update();
	Scene* curScene;
	void ChangeScene(Scene* scene) { curScene = scene; }
	//void ChangeScene(std::vector<Collider*>*);
private:
	//std::vector<Collider*> *colliders;

	ColliderManager() {
	}

};
class Collider {
protected:
	OBJ* owner;
	friend class OBJ;
	friend class Rigidbody;
	Vector2 offset;
	Vector2 pos;
	std::vector<Collider*> curCollisions;
	friend class ColliderManager;
	
public:
	Size size;
	//==state var
	ColliderType colType;
	bool enable;
	//collision 판정 관련
	
	bool isCollision;
	void CheckCollisionState();
	void OnCollision(Collider*);
	/// 
	Collider();
	~Collider();

	void Update();
	virtual void Render(HDC hdc) {}
	
	Vector2 GetPos() { return pos; }

	virtual void SetSize(Vector2);
	virtual void SetSize(int, int);

};

class BoxCollider :public Collider {
private:
	
public:
	
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
		//Ellipse(hdc, pos.x - r, pos.y - r, pos.x + r, pos.y + r);
		Ellipse(hdc, pos.x - size.hx, pos.y - size.hx, pos.x + size.hx, pos.y + size.hx);
	}
	//타원이 아닌 원으로만 인식하도록 재정의. 반지름은 size의 x로 인식. y는 무시
	//충돌처리 때문
	virtual void SetSize(Vector2);
	virtual void SetSize(int, int);
	float GetRadius();
	void SetRadius(int r2);
};

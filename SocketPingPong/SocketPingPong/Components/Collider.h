#pragma once
#include <windows.h>
#include "define.h"
#include "Transform.h"
#include <vector>
#include <algorithm>
class OBJ;
class Collider;
class Rigidbody;
class Scene;

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

	ColliderManager();

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
	//collision ���� ����
	
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
	virtual void Render(HDC);
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
	virtual void Render(HDC);
	//Ÿ���� �ƴ� �����θ� �ν��ϵ��� ������. �������� size�� x�� �ν�. y�� ����
	//�浹ó�� ����
	virtual void SetSize(Vector2);
	virtual void SetSize(int, int);
	float GetRadius();
	void SetRadius(int r2);
};

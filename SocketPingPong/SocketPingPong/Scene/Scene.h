#pragma once
#include "windows.h"
#include <vector>
using namespace std;
class OBJ;
class Collider;
class Scene {
private:
	vector<OBJ*> objs;
	vector<Collider*> colliders;
	friend class ColliderManager;
protected:

public:
	Scene();
	~Scene();
	virtual void Start() = 0;
	void Update();
	void Render(HDC hdc);

	void AddObject(OBJ* obj);
	void DeleteObject(OBJ* obj);
	void AddCollider(Collider* col);
	void DeleteCollider(Collider* col);

};
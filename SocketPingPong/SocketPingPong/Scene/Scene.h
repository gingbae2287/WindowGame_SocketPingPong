#pragma once
#include "OBJ.h"
#include <vector>
using namespace std;

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
	void Update() {
		for (vector<OBJ*>::iterator it = objs.begin(); it != objs.end(); it++) {
			(*it)->Update();
		}
		ColliderManager::Instance()->Update();
	}
	void Render(HDC hdc) {
		for (vector<OBJ*>::iterator it = objs.begin(); it != objs.end(); it++) {
			(*it)->Render(hdc);
		}
		for (vector<Collider*>::iterator it = colliders.begin(); it != colliders.end(); it++) {
			(*it)->Render(hdc);
		}
	}
	void AddObject(OBJ* obj);
	void DeleteObject(OBJ* obj);
	void AddCollider(Collider* col);
	void DeleteCollider(Collider* col);

};
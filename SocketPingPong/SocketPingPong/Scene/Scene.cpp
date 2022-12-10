#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {
	/*for (vector<OBJ*>::iterator it = objs.begin(); it != objs.end(); it++) {
		if ((*it) != nullptr) delete((*it));
	}*/
	for (int i = 0; i < objs.size(); i++) delete(objs[i]);
}


void Scene::AddObject(OBJ* obj) { 
	for (std::vector<OBJ*>::iterator it = objs.begin(); it != objs.end(); it++) {
		if (*it == obj) {
			//중복방지
			return;
		}
	}
	objs.push_back(obj);
	obj->scene = this;
	if (obj->GetCollider() != nullptr) colliders.push_back(obj->GetCollider());
}
void Scene::DeleteObject(OBJ* obj) {

	for (std::vector<OBJ*>::iterator it = objs.begin(); it != objs.end(); it++) {
		if (*it == obj) {
			objs.erase(it);
			break;
		}
	}
}

void Scene::AddCollider(Collider* col) {
	for (std::vector<Collider*>::iterator it = colliders.begin(); it != colliders.end(); it++) {
		if (*it == col) {
			//중복방지
			return;
		}
	}
	colliders.push_back(col);
}
void Scene::DeleteCollider(Collider* col) {
	for (std::vector<Collider*>::iterator it = colliders.begin(); it != colliders.end(); it++) {
		if (*it == col) {
			colliders.erase(it);
			break;
		}
	}
}
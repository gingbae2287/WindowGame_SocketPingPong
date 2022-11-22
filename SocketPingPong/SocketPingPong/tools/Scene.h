#pragma once
#include "OBJ.h"
#include <vector>
using namespace std;
class Scene {
private:
	vector<OBJ*> objs;
public:
	Scene() {}
	~Scene() {}
	void Update() {}
	void Render() {}

};
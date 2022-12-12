#pragma once
#include "OBJ.h"
#include "windows.h"

class Wall :public OBJ
{
public:
	Wall();
	virtual void Update() {}
	virtual void Render(HDC);
};


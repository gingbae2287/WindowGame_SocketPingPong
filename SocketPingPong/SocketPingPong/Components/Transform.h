#pragma once
#include "Vector2.h"
struct Position {
	float x, y;
	Position() { x = 0; y = 0; }
	Position(float X, float Y) { x = X; y = Y; }
	~Position() {}
	void Move(float X, float Y) { x += X; y += Y; }
	void Move(Vector2 v) { x += v.x; y += v.y; }
	void MoveTo(float X, float Y) { x = X; y = Y; }
	void MoveTo(Vector2 v) { x = v.x; y = v.y; }
};

struct  Size
{
	int x,y;
	int hx, hy;	//half
	Size() { x = 2; y = 2; hx = 1; hy = 1; }
	Size(int X, int Y) { x = X; y = Y; hx = (int)x / 2; hy = (int)y / 2; }

	~Size() {}

	void SetSize(int X, int Y) { x = X; y = Y; hx = (int)x / 2; hy = (int)y / 2;}
};
class Transform
{
public:
	//Position position;
	Position pos;
	Size size;
	Transform(){}
	~Transform(){}
	void SetSize(int X, int Y) { size.SetSize(X, Y); }
	void Move(float X, float Y) { pos.Move(X, Y); }
	void Move(Vector2 v) { pos.Move(v); }
	void MoveTo(float X, float Y) { pos.MoveTo(X,Y); }
	void MoveTo(Vector2 v) { pos.MoveTo(v); }

	Vector2 GetPosition() { return Vector2(pos.x, pos.y); }
	//Transform(int X, int Y) {position.}
};






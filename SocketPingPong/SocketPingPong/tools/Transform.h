#pragma once

struct Position {
	float x;
	float y;
	Position() { x = 0; y = 0; }
	Position(float X, float Y) { x = X; y = Y; }
	~Position() {}
	void Move(float X, float Y) { x += X; y += Y; }
	void MoveTo(float X, float Y) { x = X; y = Y; }
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
	Position position;
	Size size;
	Transform(){}
	~Transform(){}
	void SetSize(float X, float Y) { size.SetSize(X, Y); }
	void Move(float X, float Y) { position.x += X; position.y += Y; }
	void MoveTo(float X, float Y) { position.x = X; position.y = Y; }
	//Transform(int X, int Y) {position.}
};






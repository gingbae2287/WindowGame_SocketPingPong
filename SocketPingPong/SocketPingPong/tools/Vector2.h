#pragma once
#include <cmath>



struct Vector2{
  
public:
    float x;
    float y;
	Vector2() { x = 0; y = 0; }
    template <typename T>
	Vector2(T X, T Y) { x = X; y = Y; }
	~Vector2() {}

    Vector2(const Vector2& v) {
        this->x = v.x;
        this->y = v.y;
    }
	//===overriding
    Vector2 operator+(const Vector2& v){
        return { x + v.x, y + v.y };
    }
    Vector2 operator-(const Vector2& v){
        return { x - v.x, y - v.y };
    }
    template <typename T>
    Vector2 operator*(T value){
        return { x * value, y * value };
    }
    float operator*(const Vector2& v){
        return x * v.x+ y * v.y ;
    }
    Vector2 operator+=(const Vector2& v) {
        return *this = *this + v;
    }
    Vector2 operator-=(const Vector2& v) {
        return *this = *this - v;
    }

    bool operator==(const Vector2& v){
        return x == v.x && y == v.y;
    }
    bool operator==(const int a) {
        return x == a && y ==a;
    }
    bool operator!=(const Vector2& v){
        return !(*this == v);
    }
    //method
    float sqrMagnitude() {
        return x * x + y * y;
    }
    float Distance() {
        return sqrt(sqrMagnitude());
    }
    Vector2 Normalize() {
        float dis = Distance();
        if (dis == 0.f) return{ 0.f,0.f };
        return{ x / dis,y / dis };
    }
    float Dot(Vector2 v1, Vector2 v2) { //³»Àû
        return v1.x * v2.x + v1.y * v2.y;
    }
    
};


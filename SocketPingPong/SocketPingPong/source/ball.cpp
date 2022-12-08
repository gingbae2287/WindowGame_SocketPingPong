#include "ball.h"

Ball::Ball() {
	r = 30;
	speed = 200; 

	
	CreateCollider(ColliderType::CIRCLE);
	CreateRigidbody();
	((CircleCollider*)collider)->SetRadius(r-10);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 100);
	int rand = dis(gen);
	if (rand % 2) rigid->vel = { speed * (-1),(float)rand };
	else rigid->vel = { speed ,(float)rand };

	rigid->vel = { -300,0 };

	
}
Ball::~Ball() {

}
void Ball::Update() {
	if (rigid) rigid->Update();
	if (collider) collider->Update();
}
#include "Player.h"

Player::Player() {
	SetSize(100, 100);
	SetPos(500, 500);
	CreateCollider(ColliderType::BOX);
	//col->size.x = transform.size.x - 10;
	//col->size.y = transform.size.y - 10;
}

Player::~Player() {
	//delete(col);
}
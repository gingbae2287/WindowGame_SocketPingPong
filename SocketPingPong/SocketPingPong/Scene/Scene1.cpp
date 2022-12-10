#include "Scene1.h"
#include "Player.h"
#include "ball.h"
#include "Wall.h"
void Scene1::Start() {
	Wall* wall[4];
	
	
	for (int i = 0; i < 2; i++) {
		wall[i] = new Wall;
		wall[i]->SetSize(1280, 50);
		wall[i]->CreateCollider(BOX);
		wall[i]->GetCollider()->SetSize(wall[i]->GetSize());
		
		AddObject(wall[i]);
	}
	wall[0]->SetPos(1280 / 2, 780);
	wall[1]->SetPos(1280 / 2, 20);
	
	for (int i = 2; i < 4; i++) {
		wall[i] = new Wall;
		wall[i]->SetSize(50, 800);
		wall[i]->CreateCollider(BOX);
		wall[i]->GetCollider()->SetSize(wall[i]->GetSize());

		AddObject(wall[i]);
	}
	wall[2]->SetPos(20, 400);
	wall[3]->SetPos(1260, 400);
	

	Player* player = new Player;
	player->SetPos(500, 600);
	AddObject(player);

	Ball* ball = new Ball;
	AddObject(ball);
	ball->SetPos(1000, 600);

	



}
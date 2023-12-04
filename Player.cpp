#include "Player.h"
#include "KeyInput.h"
#include "Novice.h"
#include "StageScene.h"
void Player::Initialize(Vector3 pos)
{
	position_ = { pos.x,pos.y };
	color_ = WHITE;
}

void Player::Update()
{
	
}


void Player::Draw()
{
	const int offset = 5;
	Novice::DrawBox(((int)position_.x * StageScene::kChipSize) + offset, ((int)position_.y * StageScene::kChipSize) + offset, 20, 20,0.0f, color_, kFillModeSolid);
}


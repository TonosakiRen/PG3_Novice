#include "Select.h"
#include "KeyInput.h"
#include "Novice.h"
#include "Player.h"
#include "StageScene.h"

void Select::Update()
{
	SerchPlayer();
	position_.x = clamp(position_.x, 0.0f, StageScene::kWidthNum - 1);
	position_.y = clamp(position_.y, 0.0f, StageScene::kHeightNum);
	if (selectPlayer_) {
		selectPlayer_->SetPos(position_);
	}
}

void Select::Draw()
{
	Novice::DrawBox(int(position_.x * StageScene::kChipSize), int(position_.y * StageScene::kChipSize), StageScene::kChipSize, StageScene::kChipSize,0.0f,RED,kFillModeWireFrame);
}

void Select::SerchPlayer()
{
	if (KeyInput::IsTrigger(DIK_SPACE)) {

		if (selectPlayer_) {
			selectPlayer_->SetColor(WHITE);
			selectPlayer_ = nullptr;
		}
		else {
			for (auto& player : *players_) {
				if (player->GetPos().x == position_.x && player->GetPos().y == position_.y) {
					selectPlayer_ = player.get();
					selectPlayer_->SetColor(RED);
				}
			}
		}
	}
	
}

void Select::MoveLeft()
{
	position_.x -= 1.0f;
}

void Select::MoveRight()
{
	position_.x += 1.0f;
}

void Select::MoveUp()
{
	position_.y -= 1.0f;
}

void Select::MoveDown()
{
	position_.y += 1.0f;
}

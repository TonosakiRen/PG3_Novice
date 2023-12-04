#include "StageScene.h"
#include "Novice.h"
#include "KeyInput.h"
#include "WinApp.h"

#include "Player.h"
#include "Select.h"
#include "Command.h"
#include "InputHandle.h"

StageScene::StageScene()
{
	players_.resize(4);

	for (auto& player : players_) {
		player = std::make_unique<Player>();
	}

}

void StageScene::Init()
{
	for (int i = 0; auto & player : players_) {
		player->Initialize(Vector3{float(i),0,0});
		i++;
	}
	select_ = std::make_unique<Select>();
	select_->SetPlayers(&players_);
	inputHandler_ = std::make_unique<InputHandle>();
	inputHandler_->AssignMoveDownCommandToTriggerKeyS();
	inputHandler_->AssignMoveUpCommandToTriggerKeyW();
	inputHandler_->AssignMoveLeftCommandToTriggerKeyA();
	inputHandler_->AssignMoveRightCommandToTriggerKeyD();

}

void StageScene::Update()
{

	command_ = inputHandler_->HandleInput();

	if (this->command_) {
		command_->Exec(select_.get());
	}

	//自キャラ更新
	for (auto& player : players_) {
		player->Update();
	}
	select_->Update();
}

void StageScene::Draw()
{

	//横線
	for (int i = 0; i < kHeightNum; i++) {
		int y = (i + 1) * kChipSize;
		Novice::DrawLine(0, y, WinApp::kWindowWidth, y,WHITE);
	}

	//縦線
	for (int i = 0; i < kWidthNum; i++) {
		int x = (i + 1) * kChipSize;
		Novice::DrawLine(x, 0, x, WinApp::kWindowHeight, WHITE);
	}

	select_->Draw();
	Novice::ScreenPrintf(0, 0, "Stage");

	// 自キャラ描画
	for (auto& player : players_) {
		player->Draw();
	}
	
}



#include "GameManager.h"
GameManager::GameManager() {
	sceneArr_[Title] = std::make_unique<TitleScene>();
	sceneArr_[Stage] = std::make_unique<StageScene>();
	sceneArr_[Clear] = std::make_unique<ClearScene>();
	sceneArr_[currentScene_]->Init();
}

void GameManager::Run() {
	if (IScene::sceneRequest_) {
		currentScene_ = IScene::sceneRequest_.value();

		sceneArr_[currentScene_]->Init();

		IScene::sceneRequest_ = std::nullopt;
	}

	sceneArr_[currentScene_]->Update();
	sceneArr_[currentScene_]->Draw();
}



GameManager::~GameManager() {};
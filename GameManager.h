#pragma once

#include <memory>

#include "IScene.h"
#include "StageScene.h"
#include "StageScene.h"
#include "TitleScene.h"
#include "ClearScene.h"
class GameManager
{
private:
	//シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[SceneNum];
	Scene currentScene_ = Stage;

public:
	GameManager();
	~GameManager();

	void Run();

};


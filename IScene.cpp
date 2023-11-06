#include "IScene.h"
std::optional<Scene>  IScene::sceneRequest_ = std::nullopt;

void IScene::ChangeScene(Scene nextScene)
{
	sceneRequest_ = nextScene;
}

IScene::~IScene() {};
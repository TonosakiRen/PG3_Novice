#include "ClearScene.h"
#include "Novice.h"
#include "KeyInput.h"

void ClearScene::Init()
{

}

void ClearScene::Update()
{
	if (KeyInput::IsTrigger(DIK_SPACE)) {
		ChangeScene(Title);
	}
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Clear");
}

#include "TitleScene.h"
#include "Novice.h"
#include "KeyInput.h"

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	if (KeyInput::IsTrigger(DIK_SPACE)) {
		ChangeScene(Stage);
	}
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Title");
}

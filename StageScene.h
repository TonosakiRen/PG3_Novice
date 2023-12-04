#pragma once
#include "WinApp.h"
#include "IScene.h"

#include <memory>
#include <vector>
#include <list>

class Player;
class Select;
class Command;
class InputHandle;

class StageScene :
    public IScene
{
public:
    StageScene();
    void Init() override;
    void Update() override;
    void Draw() override;

    static const int kChipSize = 30;

    static const int kHeightNum = int(WinApp::kWindowHeight / kChipSize);
    static const int kWidthNum = int(WinApp::kWindowWidth / kChipSize);

private:
   
private:
    //自キャラ
    std::vector<std::unique_ptr<Player>> players_;
    std::unique_ptr<Select> select_ = nullptr;
    Command* command_ = nullptr;
    std::unique_ptr<InputHandle> inputHandler_ = nullptr;
};


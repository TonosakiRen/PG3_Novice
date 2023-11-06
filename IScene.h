#pragma once
#include <optional>

enum Scene {
	Title,Stage,Clear,SceneNum
};
class IScene
{

friend class GameManager;

protected:
	//どのステージを呼び出すかを管理する変数
	static std::optional<Scene> sceneRequest_;
public:
	//継承先で実装される関数
	virtual void Init() = 0;
	virtual void Update() = 0;
	void ChangeScene(Scene nextScene);
	virtual void Draw() = 0;

	virtual ~IScene();
};


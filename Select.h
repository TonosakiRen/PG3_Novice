#pragma once
#include "Mymath.h"
#include <vector>
#include <memory>
class Player;
class Select
{
public:
	void Update();
	void Draw();

	void SetPlayers(std::vector<std::unique_ptr<Player>>* players) {
		players_ = players;
	}

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
private:
	void SerchPlayer();
private:
	Vector3 position_ = {0.0f,0.0f,0.0f};
	std::vector<std::unique_ptr<Player>>* players_;
	Player* selectPlayer_ = nullptr;
};


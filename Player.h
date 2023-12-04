#pragma once
#include "Mymath.h"

#include <memory>
#include <vector>
#include <list>
class Player
{
public:
	void Initialize(Vector3 pos);
	void Update();
	void Draw();

	Vector3 GetPos() { return position_; }
	void SetPos(Vector3 pos) {
		position_ = pos;
	}
	void SetColor(int color) {
		color_ = color;
	}
private:
	//座標
	Vector3 position_;
	//色
	int color_;
};


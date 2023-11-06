#pragma once
#include "Mymath.h"

class EnemyBullet
{
public:
	void Initialize(Vector3 position);
	void Update();
	void OnCollision();
	void Draw();

	bool IsDead() const { return isDead_; }
	Vector3 GetPos() { return position_; }
private:

private:
	//座標
	Vector3 position_;
	//速度
	float speed_ = 3.0f;
	// デスフラグ
	bool isDead_ = false;
};


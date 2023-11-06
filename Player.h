#pragma once
#include "Mymath.h"

#include <memory>
#include <vector>
#include <list>
class Player
{
public:
	void Initialize();
	void Update();
	void Draw();

	bool IsDead() const { return isDead_; }
	Vector3 GetPos() { return position_; }

	struct Bullet {
		Vector3 position_;
		bool isDead_;
	};
	
	std::list<std::unique_ptr<Bullet>>& GetBullets() {
		return bullets_;
	}

private:
	void Move();
	void Fire();
	void BulletUpdate();
	void PopBullet();
private:
	//座標
	Vector3 position_;
	//デスフラグ
	bool isDead_ = false;

	//弾
	std::list<std::unique_ptr<Bullet>> bullets_;

	//弾クールタイム
	int bulletCoolTime_ = 0;
};


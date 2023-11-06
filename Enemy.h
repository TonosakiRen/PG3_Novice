#pragma once
#include "MyMath.h"

class EnemyBulletManager;

class Enemy
{
public:
	static uint32_t deadEnemyNum;

	void Initialize(Vector3 position, EnemyBulletManager* enemyBulletManager);
	void Update();
	void OnCollision();
	void Draw();

	bool IsDead() const { return isDead_; }
	Vector3 GetPos() {return position_;}
private:
	/// <summary>
	/// 攻撃
	/// </summary>
	void Fire();
private:
	//enemyBulletManager
	EnemyBulletManager* enemyBulletManager_;
	//座標
	Vector3 position_;
	//速度
	float speed_ = 3.0f;
	// デスフラグ
	bool isDead_ = false;
	//Fireのフレーム
	uint32_t fireFrame_ = 0;
};


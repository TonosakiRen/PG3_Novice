#include "Enemy.h"
#include <Novice.h>
#include "EnemyBulletManager.h"

uint32_t Enemy::deadEnemyNum = 0;

void Enemy::Initialize(Vector3 position, EnemyBulletManager* enemyBulletManager)
{
	position_ = position;
	enemyBulletManager_ = enemyBulletManager;
}

void Enemy::Update()
{
	if (position_.x > 1280 - 30 || position_.x < 0) {
		speed_ *= -1.0f;
	}
	position_.x += speed_;

	const uint32_t fireInterval = 30;
	if (fireFrame_ <= 0) {
		fireFrame_ = fireInterval;
		Fire();
	}
	fireFrame_--;
}

void Enemy::OnCollision()
{
	isDead_ = true;
	deadEnemyNum++;
}

void Enemy::Draw()
{
	Novice::DrawBox((int)position_.x, (int)position_.y,30,30, 0.0f, BLACK, kFillModeSolid);
}

void Enemy::Fire()
{
	enemyBulletManager_->PopEnemyBullet(position_);
}


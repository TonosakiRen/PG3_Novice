#include "EnemyBulletManager.h"

void EnemyBulletManager::Initialize()
{
	enemyBullets_.clear();
}

void EnemyBulletManager::Update()
{

	//敵更新
	for (const std::unique_ptr<EnemyBullet>& enemyBullet : enemyBullets_) {
		enemyBullet->Update();
	}

	// デスフラグの立った敵を削除
	enemyBullets_.remove_if([](std::unique_ptr<EnemyBullet>& enemyBullet) {
		if (enemyBullet->IsDead()) {
			return true;
		}
		return false;
	});
}

void EnemyBulletManager::PopEnemyBullet(Vector3 position)
{
	// 敵弾を生成、初期化
	std::unique_ptr<EnemyBullet> newEnemyBullet = std::make_unique<EnemyBullet>();
	// 敵弾初期化
	newEnemyBullet->Initialize(position);
	// 敵弾を登録する
	enemyBullets_.push_back(std::move(newEnemyBullet));
}

void EnemyBulletManager::Draw()
{
	//敵更新
	for (const std::unique_ptr<EnemyBullet>& enemyBullet : enemyBullets_) {
		enemyBullet->Draw();
	}
}

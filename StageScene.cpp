#include "StageScene.h"
#include "Novice.h"
#include "KeyInput.h"

StageScene::StageScene()
{
	player_ = std::make_unique<Player>();
	enemyBulletManager_ = std::make_unique<EnemyBulletManager>();
}

void StageScene::Init()
{
	player_->Initialize();	
	enemies_.clear();
	enemyBulletManager_->Initialize();
	Enemy::deadEnemyNum = 0;
}

void StageScene::Update()
{
	//自キャラ更新
	player_->Update();

	//敵出現
	const int spawnInterval = 30;
	if (enemySpawnFrame_ <= 0) {
		enemySpawnFrame_ = spawnInterval;
		EnemySpawn({ 30.0f,60.0f,0.0f });
	}
	enemySpawnFrame_--;

	//敵更新
	for (const std::unique_ptr<Enemy>& enemy : enemies_) {
		enemy->Update();
	}

	// デスフラグの立った敵を削除
	enemies_.remove_if([](std::unique_ptr<Enemy>& enemy) {
		if (enemy->IsDead()) {
			return true;
		}
		return false;
	});

	//敵弾更新
	enemyBulletManager_->Update();

	//当たり判定
	CheckAllCollision();

	if (Enemy::deadEnemyNum >= 10) {
		ChangeScene(Clear);
	}
	
}

void StageScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Stage");

	// 自キャラ描画
	player_->Draw();
	//敵描画
	for (const std::unique_ptr<Enemy>& enemy : enemies_) {
		enemy->Draw();
	}

	enemyBulletManager_->Draw();
	
}

void StageScene::EnemySpawn(Vector3 position)
{
	// 敵を生成、初期化
	std::unique_ptr<Enemy> newEnemy = std::make_unique<Enemy>();
	// 敵キャラに自キャラのアドレスを渡す
	newEnemy->Initialize(position, enemyBulletManager_.get());
	// 敵を登録する
	enemies_.push_back(std::move(newEnemy));
}

void StageScene::CheckAllCollision()
{
	//敵当たり判定
	for (const std::unique_ptr<Enemy>& enemy : enemies_) {
		for (const std::unique_ptr<Player::Bullet>& playerBullet : player_->GetBullets()) {
			float length = Length(enemy->GetPos() - playerBullet->position_);
			if (length <= 15) {
				enemy->OnCollision();
			}
		}
	}

	//自機当たり判定
	for (const std::unique_ptr<EnemyBullet>& enemyBullet : enemyBulletManager_->GetEnemyBullets()) {
		float length = Length(enemyBullet->GetPos() - player_->GetPos());
		if (length <= 15) {
			enemyBullet->OnCollision();
		}
	}
}


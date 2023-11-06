#pragma once
#include "IScene.h"

#include <memory>
#include <vector>
#include <list>

#include "Player.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "EnemyBulletManager.h"

class StageScene :
    public IScene
{
public:
    StageScene();
    void Init() override;
    void Update() override;
    void Draw() override;
private:
    void EnemySpawn(Vector3 position);
    void CheckAllCollision();
private:
    //自キャラ
    std::unique_ptr<Player> player_ = nullptr;
    //Enemy
    std::list<std::unique_ptr<Enemy>> enemies_;
    //EnemyBullets
    std::unique_ptr<EnemyBulletManager> enemyBulletManager_;
    //Enemyの数
    uint32_t enemyNum_ = 0;
    //Enemyが出現するフレーム
    uint32_t enemySpawnFrame_ = 0;
};


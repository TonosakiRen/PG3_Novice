#include "EnemyBullet.h"
#include <Novice.h>

void EnemyBullet::Initialize(Vector3 position)
{
	position_ = position;
}

void EnemyBullet::Update()
{
	position_.y += 3;
	if (position_.y >= 720 + 15) {
		isDead_ = true;
	}
}

void EnemyBullet::OnCollision()
{
	isDead_ = true;
}

void EnemyBullet::Draw()
{
	Novice::DrawBox((int)position_.x, (int)position_.y, 15, 15,0.0f,BLACK,kFillModeSolid );
}

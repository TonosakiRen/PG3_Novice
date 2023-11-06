#include "Player.h"
#include "KeyInput.h"
#include "Novice.h"
void Player::Initialize()
{
	position_ = { 1280.0f / 2.0f , 720.0f / 2.0f };
	bullets_.clear();
	isDead_ = false;
}

void Player::Update()
{
	Move();
	BulletUpdate();
	const int bulletCoolTime = 3;

	if (KeyInput::IsPressed(DIK_SPACE) != 0 && bulletCoolTime_ <= 0) {
		bulletCoolTime_ = bulletCoolTime;
		Fire();
	}
	bulletCoolTime_--;
	
}

void Player::BulletUpdate()
{

	//弾更新
	for (const std::unique_ptr<Bullet>& bullet : bullets_) {
		bullet->position_.y -= 3.0f;
		if (position_.y <= -15) {
			bullet->isDead_ = true;
		}
	}

	// デスフラグの立った敵を削除
	bullets_.remove_if([](std::unique_ptr<Bullet>& bullet) {
		if (bullet->isDead_) {
			return true;
		}
		return false;
	});
}

void Player::PopBullet()
{
	// 敵弾を生成、初期化
	std::unique_ptr<Bullet> newBullet = std::make_unique<Bullet>();
	// 敵弾初期化
	newBullet->position_ = position_;
	// 敵弾を登録する
	bullets_.push_back(std::move(newBullet));
}

void Player::Draw()
{
	Novice::DrawBox((int)position_.x, (int)position_.y, 20, 20,0.0f, WHITE, kFillModeSolid);

	//弾更新
	for (const std::unique_ptr<Bullet>& bullet : bullets_) {
		Novice::DrawBox((int)bullet->position_.x, (int)bullet->position_.y, 15, 15, 0.0f, BLUE, kFillModeSolid);
	}
}

void Player::Move()
{

	const float speed = 2.0f;

	if (KeyInput::IsPressed(DIK_W)) {
		position_.y -= speed;
	}
	if (KeyInput::IsPressed(DIK_A)) {
		position_.x -= speed;
	}
	if (KeyInput::IsPressed(DIK_S)) {
		position_.y += speed;
	}
	if (KeyInput::IsPressed(DIK_D)) {
		position_.x += speed;
	}
}

void Player::Fire()
{
	PopBullet();
}

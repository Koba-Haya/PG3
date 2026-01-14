#include "Player.h"
#include "InputManager.h"
#include "Vector2.h"
#include <Novice.h>

void Player::Init(const Vector2& pos, float radius) {
	pos_ = pos;
	radius_ = radius;

	bullets_.clear();
	bullets_.resize(maxBullets_);

	fireCooldown_ = 0.0f;
}

void Player::Update(float dt, int screenW, int screenH) {
	Vector2 move{0.0f, 0.0f};

	if (gInput->IsDown(DIK_A))
		move.x -= 1.0f;
	if (gInput->IsDown(DIK_D))
		move.x += 1.0f;
	if (gInput->IsDown(DIK_W))
		move.y -= 1.0f;
	if (gInput->IsDown(DIK_S))
		move.y += 1.0f;

	pos_ = pos_ + move * (speed_ * dt);

	pos_.x = Clamp(pos_.x, radius_, (float)screenW - radius_);
	pos_.y = Clamp(pos_.y, radius_, (float)screenH - radius_);

	// クールダウン更新
	if (fireCooldown_ > 0.0f) {
		fireCooldown_ -= dt;
		if (fireCooldown_ < 0.0f)
			fireCooldown_ = 0.0f;
	}

	// 長押し連射：押されていて、クールダウン0なら撃つ
	if (gInput->IsDown(DIK_SPACE) && fireCooldown_ <= 0.0f) {
		FireStraight();
		fireCooldown_ = fireInterval_;
	}

	for (Bullet& b : bullets_) {
		b.Update(dt, screenW, screenH);
	}
}

void Player::Draw() const {
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, 0x00FF00FF, kFillModeSolid);

	for (const Bullet& b : bullets_) {
		b.Draw();
	}
}

void Player::FireStraight() {
	// プレイヤーの上から真上に1発
	const Vector2 spawnPos = Vector2(pos_.x, pos_.y - radius_ - 4.0f);
	const Vector2 vel = Vector2(0.0f, -700.0f);

	for (Bullet& b : bullets_) {
		if (!b.IsAlive()) {
			b.Spawn(spawnPos, vel, 6.0f);
			break;
		}
	}
}
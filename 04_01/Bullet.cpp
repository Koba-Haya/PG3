#include "Bullet.h"
#include <Novice.h>

void Bullet::Spawn(const Vector2& pos, const Vector2& vel, float radius) {
	alive_ = true;
	pos_ = pos;
	vel_ = vel;
	radius_ = radius;
}

void Bullet::Update(float dt, int screenW, int screenH) {
	if (!alive_)
		return;

	pos_ = pos_ + vel_ * dt;

	// 画面外で消す（少し余裕）
	if (pos_.x < -50.0f || pos_.x > static_cast<float>(screenW) + 50.0f || pos_.y < -50.0f || pos_.y > static_cast<float>(screenH) + 50.0f) {
		alive_ = false;
	}
}

void Bullet::Draw() const {
	if (!alive_)
		return;
	Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, 0xFFFFFFFF, kFillModeSolid);
}

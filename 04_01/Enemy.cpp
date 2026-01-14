#include "Enemy.h"
#include <Novice.h>

void Enemy::Init(const Vector2& spawnPos, float radius) {
	pos_ = spawnPos;
	radius_ = radius;

	vx_ = 220.0f;
	alive_ = true;

	respawning_ = false;
	respawnTimer_ = 0.0f;
}

void Enemy::Update(float dt, int screenW) {
	if (!alive_)
		return;

	pos_.x += vx_ * dt;

	// 円なので「半径」を考慮して左右反転
	if (pos_.x - radius_ < 0.0f) {
		pos_.x = radius_;
		vx_ *= -1.0f;
	}
	if (pos_.x + radius_ > (float)screenW) {
		pos_.x = (float)screenW - radius_;
		vx_ *= -1.0f;
	}
}

void Enemy::Draw() const {
	if (!alive_)
		return;

	// 見た目も円にしておく（矩形でもOK）
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, 0xFF0000FF, kFillModeSolid);
}

void Enemy::Kill(float respawnSeconds) {
	alive_ = false;
	respawning_ = true;
	respawnTimer_ = respawnSeconds;
}

void Enemy::UpdateRespawn(float dt, const Vector2& spawnPos) {
	if (!respawning_)
		return;

	respawnTimer_ -= dt;
	if (respawnTimer_ <= 0.0f) {
		respawning_ = false;
		alive_ = true;
		pos_ = spawnPos;
		vx_ = 220.0f;
	}
}

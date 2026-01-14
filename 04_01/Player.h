#pragma once
#include "Bullet.h"
#include "Vector2.h"
#include <vector>

class Player {
public:
	void Init(const Vector2& pos, float radius = 18.0f);

	void Update(float dt, int screenW, int screenH);
	void Draw() const;

	const Vector2& GetPos() const { return pos_; }
	float GetRadius() const { return radius_; }

	std::vector<Bullet>& GetBullets() { return bullets_; }

private:
	void FireStraight();

private:
	Vector2 pos_{0.0f, 0.0f};
	float radius_ = 18.0f;

	float speed_ = 360.0f;

	std::vector<Bullet> bullets_;
	int maxBullets_ = 64;

	float fireCooldown_ = 0.0f;
	float fireInterval_ = 0.12f;
};

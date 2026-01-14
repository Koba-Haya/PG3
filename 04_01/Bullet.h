#pragma once
#include "Vector2.h"

class Bullet {
public:
	void Spawn(const Vector2& pos, const Vector2& vel, float radius = 6.0f);
	void Update(float dt, int screenW, int screenH);
	void Draw() const;

	bool IsAlive() const { return alive_; }
	void Kill() { alive_ = false; }

	const Vector2& GetPos() const { return pos_; }
	float GetRadius() const { return radius_; }

private:
	bool alive_ = false;
	Vector2 pos_{0.0f, 0.0f};
	Vector2 vel_{0.0f, 0.0f};
	float radius_ = 6.0f;
};

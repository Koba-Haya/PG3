#pragma once
#include "Vector2.h"

class Enemy {
public:
	void Init(const Vector2& spawnPos, float radius = 22.0f);
	void Update(float dt, int screenW);
	void Draw() const;

	bool IsAlive() const { return alive_; }
	const Vector2& GetPos() const { return pos_; }
	float GetRadius() const { return radius_; }

	void Kill(float respawnSeconds);
	void UpdateRespawn(float dt, const Vector2& spawnPos);

private:
	Vector2 pos_{0.0f, 0.0f};
	float radius_ = 22.0f;

	float vx_ = 220.0f; // px/s
	bool alive_ = true;

	bool respawning_ = false;
	float respawnTimer_ = 0.0f;
};

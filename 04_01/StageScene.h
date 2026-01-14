#pragma once
#include "Enemy.h"
#include "IScene.h"
#include "Player.h"

class StageScene : public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	static constexpr int kScreenW = 1280;
	static constexpr int kScreenH = 720;

	Player player_;
	Enemy enemy_;

	float enemySpawnX_ = 100.0f;
	float enemySpawnY_ = 60.0f;
	float enemyRespawnSeconds_ = 2.0f;

	int score_ = 0;
};

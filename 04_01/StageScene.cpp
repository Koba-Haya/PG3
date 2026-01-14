#include "StageScene.h"
#include "Collision.h"
#include "InputManager.h"
#include <Novice.h>

void StageScene::Init() {
	player_.Init({600.0f, 600.0f});
	enemy_.Init({enemySpawnX_, enemySpawnY_});
	score_ = 0;
}

void StageScene::Update() {
	const float dt = 1.0f / 60.0f;

	// 敵の移動とリスポーン管理
	enemy_.Update(dt, kScreenW);
	enemy_.UpdateRespawn(dt, {enemySpawnX_, enemySpawnY_});

	// プレイヤー移動＆弾更新（Spaceで複数弾）
	player_.Update(dt, kScreenW, kScreenH);

	// 当たり判定：弾（円）×敵（円）
	if (enemy_.IsAlive()) {
		auto& bullets = player_.GetBullets();
		for (Bullet& b : bullets) {
			if (!b.IsAlive())
				continue;

			if (HitCircleCircle(b.GetPos(), b.GetRadius(), enemy_.GetPos(), enemy_.GetRadius())) {
				b.Kill();
				enemy_.Kill(enemyRespawnSeconds_);
				score_ += 1;
				break;
			}
		}
	}

	// クリア条件例：スコア5でクリア
	if (score_ >= 3) {
		sceneNo_ = Scene::CLEAR;
	}

	// Esc でタイトルへ戻る
	if (gInput->IsPressed(DIK_ESCAPE)) {
		sceneNo_ = Scene::TITLE;
	}
}

void StageScene::Draw() {
	Novice::ScreenPrintf(20, 20, "GAME SCENE");
	Novice::ScreenPrintf(20, 40, "Score: %d (Clear at 3)", score_);
	Novice::ScreenPrintf(20, 60, "WASD: Move / SPACE: Shoot(3) / ESC: Title");

	player_.Draw();
	enemy_.Draw();
}

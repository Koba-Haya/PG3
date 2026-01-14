#include "GameManager.h"

GameManager::GameManager() {
	sceneArr_[Scene::TITLE] = std::make_unique<TitleScene>();
	sceneArr_[Scene::STAGE] = std::make_unique<StageScene>();
	sceneArr_[Scene::CLEAR] = std::make_unique<ClearScene>();

	prevSceneNo_ = Scene::TITLE;
	currentSceneNo_ = Scene::TITLE;

	sceneArr_[currentSceneNo_]->Init();
}

GameManager::~GameManager() {}

void GameManager::Run() {
	// 現在のシーン番号を取得
	prevSceneNo_ = currentSceneNo_;
	currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

	// シーンが変わったら初期化
	if (prevSceneNo_ != currentSceneNo_) {
		sceneArr_[currentSceneNo_]->Init();
	}

	// 更新と描画
	sceneArr_[currentSceneNo_]->Update();
	sceneArr_[currentSceneNo_]->Draw();
}

#pragma once
// 各シーン
#include "ClearScene.h"
#include "StageScene.h"
#include "TitleScene.h"
// シーン基底クラス
#include "IScene.h"
#include <memory>

class GameManager {
public:
	// コンストラクタ
	GameManager();
	// デストラクタ
	~GameManager();

	void Run();

private:
	// シーンメンバ配列
	std::unique_ptr<IScene> sceneArr_[3];

	// どのステージを呼び出すかの変数
	int currentSceneNo_; // 現在のシーン
	int prevSceneNo_;    // 前のシーン
};

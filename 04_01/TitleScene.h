#pragma once
#include "IScene.h"

class TitleScene : public IScene {
public:
	// シーン初期化処理
	void Init() override;
	// シーン更新処理
	void Update() override;
	// シーン描画処理
	void Draw() override;
};

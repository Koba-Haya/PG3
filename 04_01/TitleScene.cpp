#include "TitleScene.h"
#include "InputManager.h"
#include <Novice.h>

void TitleScene::Init() {}

void TitleScene::Update() {
	// SPACEキーが押されたらゲームシーンへ遷移
	if (gInput->GetPreKeys()[DIK_SPACE] == 0 && gInput->GetKeys()[DIK_SPACE] != 0) {
		sceneNo_ = STAGE;
	}
}

void TitleScene::Draw() {
	// タイトル画面の描画処理
	Novice::ScreenPrintf(600, 360, "TITLE SCENE");
	Novice::ScreenPrintf(540, 400, "PRESS SPACE TO START");
}

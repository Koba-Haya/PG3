#include "ClearScene.h"
#include "InputManager.h"
#include <Novice.h>

void ClearScene::Init() {
	// クリアシーンの初期化処理（必要ならここに追加）
}

void ClearScene::Update() {
	// SPACEキーが押されたらタイトルシーンへ遷移
	if (gInput->GetPreKeys()[DIK_SPACE] == 0 && gInput->GetKeys()[DIK_SPACE] != 0) {
		sceneNo_ = TITLE;
	}
}

void ClearScene::Draw() {
	// クリア画面の描画処理
	Novice::ScreenPrintf(600, 360, "CLEAR SCENE");
	Novice::ScreenPrintf(540, 400, "PRESS SPACE TO TITLE");
}
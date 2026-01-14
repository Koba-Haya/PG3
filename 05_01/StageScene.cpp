#include "StageScene.h"

StageScene::~StageScene() {
  delete inputHandler_;
  delete player_;
}

void StageScene::Init() {
  // 入力ハンドラの初期化
  inputHandler_ = new InputHandler();

  // 入力ハンドラにコマンドを割り当てる
  inputHandler_->AssignMoveLeftCommand2PressKeyA();
  inputHandler_->AssignMoveRightCommand2PressKeyD();

  // プレイヤーの初期化
  player_ = new Player();
}

void StageScene::Update() {
  // 入力ハンドラからコマンドを取得
  iCommand_ = inputHandler_->HandleInput();

  // コマンドが存在する場合、プレイヤーに対してコマンドを実行
  if (this->iCommand_) {
    iCommand_->Exec(*player_);
  }

  // プレイヤーの更新
  player_->Update();
}

void StageScene::Draw() {
  // プレイヤーの描画
  player_->Draw();
}
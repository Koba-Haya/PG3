#pragma once
#include "InputHandler.h"
#include "Player.h"

class StageScene{
public:
  ~StageScene();
  void Init();
  void Update();
  void Draw();

private:
  InputHandler *inputHandler_ = nullptr; // 入力ハンドラ
  ICommand *iCommand_ = nullptr;         // コマンド
  Player *player_ = nullptr;             // プレイヤー
};

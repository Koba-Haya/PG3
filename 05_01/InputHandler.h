#pragma once
#include "Command.h"

class InputHandler {
public:
  // コンストラクタ
  InputHandler();

  // 入力処理関数
  ICommand *HandleInput();

  // 左コマンド割り当て関数
  void AssignMoveLeftCommand2PressKeyA();

  // 右コマンド割り当て関数
  void AssignMoveRightCommand2PressKeyD();

private:
  ICommand *pressKeyA_; // Aキー押下コマンド
  ICommand *pressKeyD_; // Dキー押下コマンド
};

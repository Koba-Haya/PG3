#include "InputHandler.h"
#include <Novice.h>

InputHandler::InputHandler() {
  // コンストラクタでコマンドをnullptrに初期化
  this->pressKeyA_ = nullptr;
  this->pressKeyD_ = nullptr;

  // コマンドの割り当てを行う
  AssignMoveLeftCommand2PressKeyA();
  AssignMoveRightCommand2PressKeyD();
}

void InputHandler::AssignMoveLeftCommand2PressKeyA() {
  // MoveLeftCommandのインスタンスを生成してAキー押下コマンドに割り当てる
  ICommand *command = new MoveLeftCommand();
  this->pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommand2PressKeyD() {
  // MoveRightCommandのインスタンスを生成してDキー押下コマンドに割り当てる
  ICommand *command = new MoveRightCommand();
  this->pressKeyD_ = command;
}

ICommand *InputHandler::HandleInput() {
  // 入力処理を行い、対応するコマンドを返す
  if (Novice::CheckHitKey(DIK_A)) {
    // Aキーが押された場合、Aキー押下コマンドを返す
    return this->pressKeyA_;
  } else if (Novice::CheckHitKey(DIK_D)) {
    // Dキーが押された場合、Dキー押下コマンドを返す
    return this->pressKeyD_;
  }
  return nullptr; // どちらのキーも押されていない場合nullptrを返す
}
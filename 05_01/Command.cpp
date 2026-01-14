#include "Command.h"
#include "Player.h"

void MoveLeftCommand::Exec(Player &player) {
  // 左移動コマンドの実行
  player.MoveLeft();
}

void MoveRightCommand::Exec(Player &player) {
  // 右移動コマンドの実行
  player.MoveRight();
}
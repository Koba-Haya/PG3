#pragma once
#include "Vector2.h"

class Player {
public:
  Player();

  void Init();
  void Update();
  void Draw();

  // メンバ関数
  void MoveLeft();  // 左移動関数
  void MoveRight(); // 右移動関数

private:
  // メンバ変数
  Vector2 pos_;  // 位置
  float speed_;  // 速度
  float radius_; // 半径
};

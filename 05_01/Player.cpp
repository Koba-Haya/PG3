#include "Player.h"
#include <Novice.h>

Player::Player() { Init(); }

void Player::Init() {
  // プレイヤーの初期化処理
  pos_ = {50.0f, 50.0f};
  speed_ = 5.0f;
  radius_ = 16.0f;
}

void Player::Update() {
  // プレイヤーの更新処理
}

void Player::Draw() {
  // プレイヤーの描画処理
  Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
                      static_cast<int>(radius_), static_cast<int>(radius_),
                      0.0f, WHITE, kFillModeSolid);
}

void Player::MoveLeft() {
  // 左に移動する処理
  this->pos_.x -= this->speed_;
}

void Player::MoveRight() {
  // 右に移動する処理
  this->pos_.x += this->speed_;
}

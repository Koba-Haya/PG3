#pragma once
class Player;

class ICommand {
public:
  virtual ~ICommand() {}
  virtual void Exec(Player &player) = 0;
};

class MoveLeftCommand : public ICommand {
public:
  // 左移動コマンドの実行
  void Exec(Player &player) override;
};

class MoveRightCommand : public ICommand {
public:
  // 右移動コマンドの実行
  void Exec(Player &player) override;
};
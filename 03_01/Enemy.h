#pragma once
#include <cstddef>

class Enemy {
public:
	// フェーズ（enum class）
	enum class Phase : std::size_t {
		Approach, // 接近
		Attack,   // 攻撃
		Withdrawal, // 撤退
		Num       // 要素数
	};

	Enemy();

	// 毎フレーム呼ばれる想定
	void Update();

private:
	using PhaseFunc = void (Enemy::*)();  // メンバ関数ポインタ型

	// 現在のフェーズ
	Phase phase_;
	int   counter_;   // 各フェーズ内で使うカウンタ

	// 各フェーズの処理
	void Phase_Approach(); // 接近
	void Phase_Attack();   // 攻撃
	void Phase_Withdrawal();     // 離脱

	// ① フェーズの関数テーブル
	static PhaseFunc s_phaseTable_[static_cast<std::size_t>(Phase::Num)];
};

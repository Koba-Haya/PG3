#include "Enemy.h"
#include <iostream>

// ① フェーズの関数テーブルの定義
Enemy::PhaseFunc Enemy::s_phaseTable_[] = {
	&Enemy::Phase_Approach, // Approach
	&Enemy::Phase_Attack,   // Attack
	&Enemy::Phase_Withdrawal, // Withdrawal
};

Enemy::Enemy()
	: phase_(Phase::Approach),
	counter_(0) {
}

void Enemy::Update() {
	// ② 現在フェーズの関数を実行
	(this->*s_phaseTable_[static_cast<std::size_t>(phase_)])();

	// ③ 行列を更新 …ゲームならここで座標や行列を更新する想定
	// （今回はコンソール課題なので特に何もしない）

	// ④ デバッグ用表示 …今回は各フェーズ関数内で printf 代わりに cout している
}

// --- 各フェーズの処理 -----------------------------

// 接近
void Enemy::Phase_Approach() {
	std::cout << "[接近] 敵がプレイヤーに近づいている... (" << counter_ << ")\n";
	++counter_;

	// 3カウント経ったら攻撃へ
	if (counter_ >= 3) {
		std::cout << "  → 一定距離まで接近したので「攻撃」へ\n\n";
		phase_ = Phase::Attack;
		counter_ = 0;
	}
}

// 攻撃
void Enemy::Phase_Attack() {
	std::cout << "[攻撃] プレイヤーを攻撃！ (" << counter_ << ")\n";
	++counter_;

	// 1回攻撃したら離脱する
	if (counter_ >=1) {
		std::cout << "  → 攻撃が終わったので「離脱」する\n\n";
		phase_ = Phase::Withdrawal;
		counter_ = 0;
	}
}

// 離脱
void Enemy::Phase_Withdrawal() {
	std::cout << "[離脱] 敵が遠ざかっていく... (" << counter_ << ")\n";
	++counter_;

	// 2カウント経ったら再び接近へ
	if (counter_ >= 2) {
		std::cout << "  → タイミングを見計らって「接近」へ\n\n";
		phase_ = Phase::Approach;
		counter_ = 0;
	}
}

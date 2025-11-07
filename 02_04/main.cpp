#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <functional>

// ---- 遅延実行関数 ----
// fn       : 呼び出したい関数（std::function<void(int,int)>）
// delayMs  : 待機時間(ミリ秒)
// roll     : サイコロの出目(1〜6)
// userGuess: 入力(1=奇数, 0=偶数)
void DelayReveal(std::function<void(int, int)> fn, unsigned int delayMs, int roll, int userGuess) {
	// ミリ秒待機
	Sleep(delayMs);

	// コールバック実行
	fn(roll, userGuess);
}

int main() {
	// ---- 乱数初期化 ----
	srand((unsigned)time(NULL));

	int userGuess = -1;
	printf("奇数か偶数かを予想してください。\n");
	printf("奇数なら 1、偶数なら 0 を入力して Enter: ");

	// ---- 入力受け付け ----
	if (scanf_s("%d", &userGuess) != 1) {
		fprintf(stderr, "入力エラーです。\n");
		return 1;
	}

	// ---- サイコロ(1〜6)の出目を rand() で生成 ----
	int roll = (rand() % 6) + 1;

	// ---- 判定ロジックをラムダ式で定義（型はstd::function<void(int,int)>）----
	std::function<void(int, int)> showResult = [](int roll, int userGuess) {
		int parity = (roll % 2 == 1) ? 1 : 0; // 1=奇数, 0=偶数
		printf("出目は %d でした。\n", roll);
		if (parity == userGuess) {
			printf("【正解】\n");
		} else {
			printf("【不正解】\n");
		}
	};

	// ---- 3秒(3000ms)の演出を入れてから結果表示 ----
	printf("\n判定中...（3秒お待ちください）\n\n");
	DelayReveal(showResult, 3000, roll, userGuess);

	return 0;
}

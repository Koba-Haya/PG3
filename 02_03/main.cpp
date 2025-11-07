#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// ---- 判定関数 ----
// 出目と入力を比較して結果を2行で出力する
void ShowResult(int roll, int userGuess) {
	int parity = (roll % 2 == 1) ? 1 : 0; // 1=奇数, 0=偶数
	printf("出目は %d でした。\n", roll);
	if (parity == userGuess) {
		printf("【正解】\n");
	} else {
		printf("【不正解】\n");
	}
}

// ---- 遅延実行関数 ----
// fn       : 呼び出したい関数へのポインタ（int,intを取りvoidを返す関数）
// delayMs  : 待機時間(ミリ秒)
// roll     : サイコロの出目(1〜6)
// userGuess: 入力(1=奇数, 0=偶数)
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
	// 指定ミリ秒だけ待つ
	Sleep(delayMs);

	// 待機後にコールバックを実行
	fn(roll, userGuess);
}

int main(void) {
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

	// ---- 3秒(3000ms)の演出を入れてから結果表示 ----
	printf("\n判定中...（3秒お待ちください）\n\n");
	DelayReveal(ShowResult, 3000, roll, userGuess);

	return 0;
}

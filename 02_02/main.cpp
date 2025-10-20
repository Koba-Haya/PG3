#include <stdio.h>

const int hourlyWage = 1226; // 一般的な時給

int Recursive(int hour, int rec, int recSum, int hourlySum) {
  if (recSum > hourlySum) { // 再帰的賃金体系が一般的賃金体系を超えた場合
    printf("%d時間働くと再帰的賃金体系のほうが儲かる\n", hour);
    printf("一般的賃金体系   %d   ,   再帰的賃金体系   %d", hourlySum, recSum);

    return hour; // 再帰終了
  } else {
    hourlySum += hourlyWage;    // 一般的な賃金体系の計算
    recSum += rec;              // 再帰的賃金体系の計算
    int nextRec = rec * 2 - 50; // 次の時間の再帰的賃金体系の計算
    return Recursive(hour + 1, nextRec, recSum, hourlySum); // 再帰呼び出し
  }
}

int main() {
  Recursive(0, 100, 0, 0); // 1時間目は100円からスタート

  return 0;
}
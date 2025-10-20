# 賃金体系比較（再帰的賃金 vs 一般的賃金）

## 前提条件

- 一般的賃金体系：時給 1,226 円（固定）
- 再帰的賃金体系：
  - 1時間目：100円
  - 2時間目以降：`前の時給 * 2 - 50`

## 計算方法

1. 両方の賃金を1時間ごとに加算
2. 再帰的賃金の累計が一般的賃金の累計を超えた時点で終了
3. 計算は再帰関数で実施

## 結果

- **8時間働くと再帰的賃金体系のほうが儲かる**
- 一般的賃金体系： 9,808 円
- 再帰的賃金体系：13,150 円

## 各時間の内訳

| 時間 | 再帰的時給 | 再帰的累計  | 一般的累計 |
|-----|------------|------------|-----------|
|  1  |    100     |    100     |   1,226   |
|  2  |    150     |    250     |   2,452   |
|  3  |    250     |    500     |   3,678   |
|  4  |    450     |    950     |   4,904   |
|  5  |    850     |   1,800    |   6,130   |
|  6  |   1,650    |   3,450    |   7,356   |
|  7  |   3,250    |   6,700    |   8,582   |
|  8  |   6,450    |   13,150   |   9,808   |

---

## 実装コード（再帰関数）

```c
#include <stdio.h>
#include <stdint.h>

const int HOURLY = 1226;

int solve_recursive(int hour, long long recWage, long long recSum, long long genSum) {
    recSum += recWage;
    genSum += HOURLY;
    if (recSum > genSum) {
        printf("%d時間働くと再帰的賃金体系のほうが儲かる\n", hour);
        printf("一般的賃金体系   %lld円   ,   再帰的賃金体系   %lld円\n", genSum, recSum);
        return hour;
    }
    long long nextRecWage = recWage * 2 - 50;
    return solve_recursive(hour + 1, nextRecWage, recSum, genSum);
}

int main(void) {
    solve_recursive(1, 100, 0, 0);
    return 0;
}
```

---

## 結論

- 時給 1,226 円固定の一般的賃金体系よりも、再帰的賃金体系のほうが **8時間目で逆転**する。
- それ以降は再帰的賃金が急速に増えるため、長時間労働では再帰的賃金体系が圧倒的に有利になる。

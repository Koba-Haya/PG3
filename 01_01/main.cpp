#include <list>
#include <stdio.h>
using namespace std;

int main() {

  list<const char *> stations{
      "Tokyo",        "Kanda",     "Akihabara", "Okachimachi",  "Ueno",
      "Uguisudani",   "Nippori",   "Tabata",    "Komagome",     "Sugamo",
      "Otsuka",       "Ikebukuro", "Mejiro",    "Takadanobaba", "Shin-Okubo",
      "Shinjuku",     "Yoyogi",    "Harajuku",  "Shibuya",      "Ebisu",
      "Meguro",       "Gotanda",   "Osaki",     "Shinagawa",    "Tamachi",
      "Hamamatsucho", "Shimbashi", "Yurakucho"};

  printf("1970年\n");
  for (auto s : stations) {
    printf("%s ", s);
  }

  // 西日暮里は田端の前に挿入
  for (auto itr = stations.begin(); itr != stations.end(); ++itr) {
    if (std::strcmp(*itr, "Tabata") == 0) {
      itr = stations.insert(itr, "Nishi-Nippori");
      ++itr; // 挿入した要素をスキップ
    }
  }

  printf("\n\n2019年\n");
  for (auto s : stations) {
    printf("%s ", s);
  }

  // 高輪ゲートウェイは田町の前に挿入
  for (auto it = stations.begin(); it != stations.end(); ++it) {
    if (std::strcmp(*it, "Tamachi") == 0) {
      it = stations.insert(it, "Takanawa-Gateway");
      ++it;
    }
  }

  printf("\n\n2022年\n");
  for (auto s : stations) {
    printf("%s ", s);
  }

  return 0;
}
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {

  list<string> stations{"Tokyo",    "Kanda",        "Akihabara",  "Okachimachi",
                        "Ueno",     "Uguisudani",   "Nippori",    "Tabata",
                        "Komagome", "Sugamo",       "Otsuka",     "Ikebukuro",
                        "Mejiro",   "Takadanobaba", "Shin-Okubo", "Shinjuku",
                        "Yoyogi",   "Harajuku",     "Shibuya",    "Ebisu",
                        "Meguro",   "Gotanda",      "Osaki",      "Shinagawa",
                        "Tamachi",  "Hamamatsucho", "Shimbashi",  "Yurakucho"};

  printf("1970年\n");
  for (auto &s : stations) {
    cout << s << '\n';
  }

  // 西日暮里は田端の前に挿入
  for (auto itr = stations.begin(); itr != stations.end(); ++itr) {
    if (*itr == "Tabata") {
      itr = stations.insert(itr, "Nishi-Nippori");
      ++itr; // 挿入した要素をスキップ
    }
  }

  printf("\n\n2019年\n");
  for (auto &s : stations) {
    cout << s << '\n';
  }

  // 高輪ゲートウェイは田町の前に挿入
  for (auto itr = stations.begin(); itr != stations.end(); ++itr) {
    if (*itr == "Tamachi") {
      itr = stations.insert(itr, "Takanawa Gateway");
      ++itr;
    }
  }

  printf("\n\n2022年\n");
  for (auto &s : stations) {
    cout << s << '\n';
  }

  return 0;
}
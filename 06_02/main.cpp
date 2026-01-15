#include <atomic>
#include <chrono>
#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

// マップ（0/1のみ）
struct TileMap {
  std::vector<std::vector<int>> tiles;
  int width = 0;
  int height = 0;
};

// 共有データ（メインスレッドとワーカースレッドで共有）
static std::mutex g_mutex;
static TileMap g_map;

// 状態共有
static std::atomic<bool> g_loading{false};
static std::atomic<bool> g_loaded{false};
static std::atomic<bool> g_error{false};

// 0/1以外が来たら0扱いにする
static int ToTile01(const std::string &cell) {
  // 空なら0
  if (cell.empty()) {
    return 0;
  }
  // 先頭文字が '1' なら1、それ以外は0
  return (cell[0] == '1') ? 1 : 0;
}

// マップチップ表示
static void DrawMapToConsole(const TileMap &map) {
  std::cout << "Map: " << map.width << " x " << map.height << "\n\n";

  for (int y = 0; y < map.height; ++y) {
    for (int x = 0; x < map.width; ++x) {
      const int id = map.tiles[y][x];
      // 0: 空, 1: ブロック
      std::cout << (id == 1 ? '#' : '.');
    }
    std::cout << "\n";
  }
}

// CSVを別スレッドで読み込んで TileMap を作る
static void LoadCsvAsync(const std::string &path) {
  g_loading = true;
  g_loaded = false;
  g_error = false;

  TileMap local;

  std::ifstream file(path);
  if (!file.is_open()) {
    g_error = true;
    g_loading = false;
    g_loaded = true;
    return;
  }

  std::string line;
  int maxWidth = 0;

  // 1行ずつ読む
  while (std::getline(file, line)) {
    std::vector<int> row;

    std::stringstream ss(line);
    std::string cell;

    // カンマ区切りでセルを読む（0/1）
    while (std::getline(ss, cell, ',')) {
      row.push_back(ToTile01(cell));
    }

    // 空行は無視
    if (!row.empty()) {
      if (static_cast<int>(row.size()) > maxWidth) {
        maxWidth = static_cast<int>(row.size());
      }
      local.tiles.push_back(std::move(row));
    }
  }

  local.height = static_cast<int>(local.tiles.size());
  local.width = maxWidth;

  // 行の長さを揃える（足りない分は0で埋める）
  for (int y = 0; y < local.height; ++y) {
    if (static_cast<int>(local.tiles[y].size()) < local.width) {
      local.tiles[y].resize(local.width, 0);
    }
  }

  // 完成品を一気に共有データへ反映（この瞬間だけmutex）
  {
    std::lock_guard<std::mutex> lock(g_mutex);
    g_map = std::move(local);
  }

  g_loading = false;
  g_loaded = true;
}

int main() {
  const std::string csvPath = "test.csv";

  // CSVバックグラウンド読み込み
  std::thread th(LoadCsvAsync, csvPath);

  // メインループ
  while (true) {
    // 読み込みが完了したか
    if (g_loaded.load()) {
      if (g_error.load()) {
        std::cout << "CSV open failed: " << csvPath << "\n";
      } else {
        // 共有データを表示
        TileMap snapshot;
        {
          std::lock_guard<std::mutex> lock(g_mutex);
          snapshot = g_map;
        }
        DrawMapToConsole(snapshot);
      }
      break;
    }

    // 読み込み中の表示
    if (g_loading.load()) {
      std::cout << "Loading...\n";
    }

    // ループが速すぎないように待機
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  // 実行中に止めないで終了時にjoinする
  if (th.joinable()) {
    th.join();
  }

  return 0;
}

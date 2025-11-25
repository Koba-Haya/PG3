#include "Enemy.h"
#include <thread>
#include <chrono>
#include <iostream>

int main() {
    Enemy enemy;

    for (int frame = 0; frame < 15; ++frame) {
        std::cout << "=== フレーム " << frame << " ===\n";
        enemy.Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

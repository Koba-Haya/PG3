#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex g_mtx;
std::condition_variable g_cv;
int g_turn = 1;

void PrintThreadLine(int id) {
  std::unique_lock<std::mutex> lock(g_mtx);
  g_cv.wait(lock, [&] { return g_turn == id; });

  std::cout << "thread " << id << std::endl;

  ++g_turn;
  lock.unlock();
  g_cv.notify_all();
}

int main() {
  std::thread t1(PrintThreadLine, 1);
  std::thread t2(PrintThreadLine, 2);
  std::thread t3(PrintThreadLine, 3);

  t1.join();
  t2.join();
  t3.join();
  return 0;
}

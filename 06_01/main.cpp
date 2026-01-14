#include <iostream>
#include <stdio.h>
#include <thread>

void Triple(int num) {
  num *= 3;
  std::cout << "num * 3 = " << num << std::endl;
}

void AddFifth(int num) {
  num += 5;
  std::cout << "num + 5 = " << num << std::endl;
}

void SubtractThree(int num) {
  num -= 3;
  std::cout << "num - 3 = " << num << std::endl;
}

int main() {
  int num = 10;
  std::thread t1(SubtractThree, num);
  std::thread t2(Triple, num);
  std::thread t3(AddFifth, num);
  t1.join();
  t2.join();
  t3.join();
}
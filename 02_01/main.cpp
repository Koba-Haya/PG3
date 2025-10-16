#include <cstdio>

template <typename Type>

Type Min(Type a, Type b) {
  if (a < b) {
    return static_cast<Type>(a);
  } else {
    return static_cast<Type>(b);
  }
}

int main() {
  int a = 10, b = 20;
  float c = 5.6f, d = 5.5f;
  double f = 1.58, e = 2.56;

  printf("Min(%d, %d) = %d\n", a, b, Min(a, b));
  printf("Min(%.1ff, %.1ff) = %.1ff\n", c, d, Min(c, d));
  printf("Min(%.2f, %.2f) = %.2f\n", e, f, Min(e, f));
  return 0;
}
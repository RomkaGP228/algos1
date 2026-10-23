#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  long long a = 0;
  long long b = 1;
  long long t = 0;
  for (int i = 0; i < n; ++i) {
    t = (a + b) % 10;
    a = b;
    b = t;
  }
  std::cout << b << std::endl;
}
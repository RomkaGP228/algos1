#include <iostream>

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int a = 0;
  int b = 0;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
}
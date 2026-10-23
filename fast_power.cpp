#include <iostream>

double rec(double a, long long n) {
  if (n < 0) {
    return rec(1.0 / a, -n);
  }
  if (n == 0) {
    return 1.0;
  }
  if (n % 2 == 0) {
    return rec(a * a, n / 2);
  } else {
    return rec(a, n - 1) * a;
  }
}

int main() {
  double a = 0;
  long long n = 0;
  std::cin >> a >> n;
  std::cout << rec(a, n) << std::endl;
  return 0;
}
// Даны два целых числа l и r. Посчитайте общее количество различных простых
// делителей всех целых чисел между l и r включительно. Например, для l=5 и r=15
// список делителей — 5, 2, 3, 7, 11, 13, итого 6 делителей.

#include <cstddef>
#include <iostream>
#include <vector>
// odd-sieve - решето эратосфена. Тут - оно оптимизированное.
std::vector<size_t> odd_sieve(size_t n) {
  if (n < 2) {
    return {};
  }
  size_t size = (n - 1) / 2;
  std::vector<bool> vect(size + 1, true);
  size_t p = 3;
  while (p * p <= n) {
    size_t idx = (p - 1) / 2;
    if (vect.at(idx)) {
      for (size_t j = (p * p - 1) / 2; j < size + 1; j += p) {
        vect[j] = false;
      }
    }
    p += 2;
  }
  std::vector<size_t> finvect;
  finvect.push_back(2);
  for (size_t i = 1; i < size + 1; ++i) {
    if (vect[i]) {
      finvect.push_back(2 * i + 1);
    }
  }
  return finvect;
}

int main() {
  size_t a = 0;
  size_t b = 0;
  std::cin >> a >> b;
  size_t c = 0;
  for (size_t p : odd_sieve(b)) {
    if ((b / p) * p >= a) {
      c++;
    }
  }
  std::cout << c << std::endl;
}
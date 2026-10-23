#include <iostream>
#include <vector>

std::vector<long long> factorize(long long n) {
  std::vector<long long> factors;
  while (n % 2 == 0) {
    factors.push_back(2);
    n /= 2;
  }
  long long i = 3;
  while (i * i <= n) {
    while (n % i == 0) {
      n /= i;
      factors.push_back(i);
    }
    i += 2;
  }
  if (n > 1) {
    factors.push_back(n);
  }
  return factors;
}

int main() {
  long long a = 0;
  std::cin >> a;
  std::vector<long long> vect = factorize(a);
  for (long long elem : vect) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  return 0;
}
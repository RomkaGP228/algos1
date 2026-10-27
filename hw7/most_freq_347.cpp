#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> counting_sort(std::vector<int> &arr) {
  const int force = 10000;
  int max_val = *std::max_element(arr.begin(), arr.end());
  std::vector<int> count(force + max_val + 1, 0);
  for (int elem : arr) {
    count[force + elem]++;
  }
  return count;
}

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  auto count = counting_sort(arr);
  std::vector<std::vector<int>> buckets(n + 1);
  for (int i = 0; i < count.size(); ++i) {
    if (count[i] > 0) {
      buckets[count[i]].push_back(i - 10000);
    }
  }
  for (int i = n; i > 0; --i) {
    if (k == 0) {
      break;
    }
    for (int elem : buckets[i]) {
      if (k == 0) {
        break;
      }
      std::cout << elem << " ";
      k--;
    }
  }
  std::cout << std::endl;
  return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>
// сортировка подсчетом
std::vector<int> counting_sort(const std::vector<int> arr) {
  int end = *std::max_element(arr.begin(), arr.end());
  std::vector<int> count(end + 1, 0);
  for (int elem : arr) {
    count[elem]++;
  }
  std::vector<int> sorted_arr;
  for (int v = 0; v <= end; v++) {
    for (int i = 0; i < count[v]; i++) {
      sorted_arr.push_back(v);
    }
  }
  return sorted_arr;
}

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  auto sorted_arr = counting_sort(arr);
  int j = 0;
  while (j < n && sorted_arr[j] <= k) {
    k -= sorted_arr[j++];
  }
  std::cout << j << std::endl;
}
#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> counting_sort(std::vector<int> &arr) {
  const int force = 1000000;
  int max_val = *std::max_element(arr.begin(), arr.end());
  std::vector<int> count(force + max_val + 1, 0);
  for (int elem : arr) {
    count[force + elem]++;
  }
  std::vector<int> sorted_arr;
  for (int i = 0; i < count.size(); ++i) {
    for (int j = 0; j < count[i]; ++j) {
      sorted_arr.push_back(i - force);
    }
  }
  return sorted_arr;
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  auto sorted_arr = counting_sort(arr);
  int min_diff = 2 * 1000001;
  for (int i = 0; i < n - 1; ++i) {
    int diff = sorted_arr[i + 1] - sorted_arr[i];
    if (diff < min_diff) {
      min_diff = diff;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    int diff = sorted_arr[i + 1] - sorted_arr[i];
    if (diff == min_diff) {
      std::cout << sorted_arr[i] << " " << sorted_arr[i + 1] << std::endl;
    }
  }
}
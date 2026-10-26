#include <iostream>
#include <vector>

// сортировка подсчетом, но при этом не всего массива
std::vector<int> counting_sort(const std::vector<int> arr, const int end) {
  std::vector<int> count(end + 1, 0);
  for (int elem : arr) {
    if (elem <= end) {
      count[elem]++;
    }
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
  std::cin >> n;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  int x = 0;
  std::cin >> x;
  auto final = counting_sort(arr, x);
  bool found = false;
  for (int i = 0; i < final.size(); ++i) {
    if (final[i] == x) {
      std::cout << i << " ";
      found = true;
    }
  }
  if (!found) {
    std::cout << -1;
  }
  std::cout << std::endl;
}
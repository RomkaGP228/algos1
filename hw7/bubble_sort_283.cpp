#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (arr[j + 1] - arr[j] == arr[j + 1]) {
        int t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
      }
    }
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  bubble_sort(arr);
  for (auto elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}
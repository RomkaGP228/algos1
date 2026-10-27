#include <iostream>
#include <vector>

void cycle_sort(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); ++i) {
    while (arr[i] != i + 1 && arr[arr[i] - 1] != arr[i]) {
      std::swap(arr[i], arr[arr[i] - 1]);
    }
  }
}
void insertion_sort(std::vector<int> &arr) {
  for (int i = 1; i < arr.size(); ++i) {
    int curr = arr[i];
    int j = i - 1;
    while (j >= 0 && curr < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = curr;
  }
}
int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  cycle_sort(arr);
  std::vector<int> duplicates;
  for (int i = 0; i < n; ++i) {
    if (arr[i] != i + 1) {
      duplicates.push_back(arr[i]);
    }
  }
  if (duplicates.empty()) {
    std::cout << -1;
  } else {
    insertion_sort(duplicates);
    for (auto elem : duplicates) {
      std::cout << elem << " ";
    }
  }
  std::cout << std::endl;
  return 0;
}
#include <iostream>
#include <vector>

int main() {
  int n = 0;
  int pivot = 0;
  std::cin >> n >> pivot;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  std::vector<int> res;
  for (int elem : arr) {
    if (elem < pivot) {
      res.push_back(elem);
    }
  }
  for (int elem : arr) {
    if (elem == pivot) {
      res.push_back(elem);
    }
  }
  for (int elem : arr) {
    if (elem > pivot) {
      res.push_back(elem);
    }
  }
  for (int elem : res) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}
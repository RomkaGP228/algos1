#include <iostream>
#include <vector>

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

bool check_alg(const std::vector<int> &arr) {
  int d = arr[1] - arr[0];
  for (int i = 1; i < arr.size() - 1; ++i) {
    if (arr[i + 1] - arr[i] != d) {
      return false;
    }
  }
  return true;
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> n >> m;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  int l = 0;
  int r = 0;
  for (int i = 0; i < m; ++i) {
    std::cin >> l >> r;
    std::vector<int> slice(arr.begin() + l, arr.begin() + 1 + r);
    insertion_sort(slice);
    if (check_alg(slice)) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0;
}
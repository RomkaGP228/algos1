#include <iostream>
#include <vector>

int quick_select(std::vector<int> &arr, int target) {
  int left = 0;
  int right = (int)arr.size() - 1;
  while (left < right) {
    int pivot = arr[left];
    int lt = left;
    int i = left;
    int rt = right;
    while (i <= rt) {
      if (arr[i] < pivot) {
        std::swap(arr[lt++], arr[i++]);
      } else if (arr[i] > pivot) {
        std::swap(arr[i], arr[rt--]);
      } else {
        ++i;
      }
    }
    if (target < lt) {
      right = lt - 1;
    } else if (target > rt) {
      left = rt + 1;
    } else {
      return arr[target];
    }
  }
  return arr[target];
}

int main() {
  int m = 0;
  int n = 0;
  int k = 0;
  std::cin >> m >> n >> k;
  std::vector<std::vector<int>> matrix(m + 1, std::vector<int>(n + 1, 0));
  std::vector<int> values;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      int x = 0;
      std::cin >> x;
      matrix[i][j] =
          matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1] ^ x;
      values.push_back(matrix[i][j]);
    }
  }
  std::cout << quick_select(values, m * n - k) << std::endl;
}
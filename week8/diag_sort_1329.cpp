#include <iostream>
#include <vector>

int partition_lomuto(std::vector<int> &arr, int left, int right);

void quick_sort_lomuto(std::vector<int> &arr, int left, int right) {
  if (left < right) {
    int pivot_pos = partition_lomuto(arr, left, right);
    quick_sort_lomuto(arr, left, pivot_pos - 1);
    quick_sort_lomuto(arr, pivot_pos + 1, right);
  }
}

int partition_lomuto(std::vector<int> &arr, int left, int right) {
  int pivot = arr[right];
  int i = left;
  for (int j = left; j < right; ++j) {
    if (arr[j] <= pivot) {
      int temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
      i++;
    }
  }
  int temp = arr[i];
  arr[i] = arr[right];
  arr[right] = temp;
  return i;
}

int main() {
  int n = 0;
  int m = 0;
  std::cin >> m >> n;
  std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> matrix[i][j];
    }
  }
  for (int d = -(m - 1); d <= n - 1; ++d) {
    int i0 = 0;
    if (d < 0) {
      i0 = -d;
    } else {
      i0 = 0;
    }
    int j0 = 0;
    if (d > 0) {
      j0 = d;
    } else {
      j0 = 0;
    }
    std::vector<int> diag;
    for (int i = i0, j = j0; i < m && j < n; ++i, ++j) {
      diag.push_back(matrix[i][j]);
    }
    quick_sort_lomuto(diag, 0, (int)diag.size() - 1);
    for (int k = 0, i = i0, j = j0; i < m && j < n; ++i, ++j, ++k) {
      matrix[i][j] = diag[k];
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j)
      std::cout << matrix[i][j] << " ";
    std::cout << std::endl;
  }
}
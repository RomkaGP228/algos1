#include <iostream>
#include <vector>

static int cou = 0;
int partition_lomuto(std::vector<int> &arr, int left, int right);

void quick_sort_lomuto(std::vector<int> &arr, int left, int right) {
  if (left < right) {
    int pivot_pos = partition_lomuto(arr, left, right);
    if (left < pivot_pos - 1) {
      quick_sort_lomuto(arr, left, pivot_pos - 1);
      cou++;
    }
    if (pivot_pos + 1 < right) {
      quick_sort_lomuto(arr, pivot_pos + 1, right);
      cou++;
    }
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
  std::cin >> n;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  quick_sort_lomuto(arr, 0, arr.size() - 1);
  std::cout << cou << std::endl;
  for (int elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}
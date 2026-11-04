#include <iostream>
#include <vector>

int partition_hoare(std::vector<int> &arr, int low, int high) {
  int pivot = arr[(high + low) / 2];
  int i = low;
  int j = high;
  while (true) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }
    if (i >= j) {
      return j;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
  }
}

void quick_sort_hoare(std::vector<int> &arr, int low, int high) {
  if (low < high) {
    int part_ind = partition_hoare(arr, low, high);
    quick_sort_hoare(arr, low, part_ind);
    quick_sort_hoare(arr, part_ind + 1, high);
  }
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  quick_sort_hoare(arr, 0, arr.size() - 1);
  for (int elem : arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}
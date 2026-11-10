#include <cmath>
#include <iostream>
#include <vector>

void sift_down(std::vector<int> &arr, int n, int i) {
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[smallest]) {
    smallest = left;
  }
  if (right < n && arr[right] > arr[smallest]) {
    smallest = right;
  }
  if (smallest != i) {
    int temp = arr[i];
    arr[i] = arr[smallest];
    arr[smallest] = temp;
    sift_down(arr, n, smallest);
  }
}

void heapify(std::vector<int> &arr, int n) {
  for (int i = (n / 2) - 1; i >= 0; --i) {
    sift_down(arr, n, i);
  }
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> heap(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> heap[i];
  }
  heapify(heap, n);
  long long sum = 0;
  for (int i = 0; i < k; ++i) {
    sum += (long long)heap[0];
    heap[0] = std::ceil((double)heap[0] / 3);
    sift_down(heap, n, 0);
  }
  std::cout << sum << std::endl;
}
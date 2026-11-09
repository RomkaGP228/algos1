#include <iostream>
#include <vector>

void sift_down(std::vector<int> &arr, int n, int i) {
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] < arr[smallest]) {
    smallest = left;
  }
  if (right < n && arr[right] < arr[smallest]) {
    smallest = right;
  }
  if (smallest != i) {
    int temp = arr[i];
    arr[i] = arr[smallest];
    arr[smallest] = temp;
    sift_down(arr, n, smallest);
  }
}

void sift_up(std::vector<int> &arr, int i) {
  int parent = (i - 1) / 2;
  if (i > 0 && arr[i] < arr[parent]) {
    int temp = arr[i];
    arr[i] = arr[parent];
    arr[parent] = temp;
    sift_up(arr, parent);
  }
}

void add(std::vector<int> &arr, int x, int k) {
  arr.push_back(x);
  sift_up(arr, arr.size() - 1);
  if ((int)arr.size() > k) {
    arr[0] = arr[arr.size() - 1];
    arr.pop_back();
    sift_down(arr, arr.size(), 0);
  }
}

int main() {
  int k, n, q;
  std::cin >> k >> n >> q;
  std::vector<int> heap;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    add(heap, x, k);
  }
  for (int i = 0; i < q; ++i) {
    int x;
    std::cin >> x;
    add(heap, x, k);
    std::cout << heap[0] << " ";
  }
  std::cout << std::endl;
  return 0;
}
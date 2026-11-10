#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

void sift_up_min(std::vector<int> &arr, int i) {
  int parent = (i - 1) / 2;
  if (i > 0 && arr[i] < arr[parent]) {
    int temp = arr[i];
    arr[i] = arr[parent];
    arr[parent] = temp;
    sift_up_min(arr, parent);
  }
}

void sift_up_max(std::vector<int> &arr, int i) {
  int parent = (i - 1) / 2;
  if (i > 0 && arr[i] > arr[parent]) {
    int temp = arr[i];
    arr[i] = arr[parent];
    arr[parent] = temp;
    sift_up_max(arr, parent);
  }
}

void sift_down_min(std::vector<int> &arr, int n, int i) {
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
    sift_down_min(arr, n, smallest);
  }
}

void sift_down_max(std::vector<int> &arr, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }
  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    sift_down_max(arr, n, largest);
  }
}

void balance(std::vector<int> &arr1, std::vector<int> &arr2) {
  int a = arr1.size();
  int b = arr2.size();
  if (a - b > 1) {
    arr2.push_back(arr1[0]);
    sift_up_min(arr2, b);
    arr1[0] = arr1[a - 1];
    arr1.pop_back();
    sift_down_max(arr1, a - 1, 0);
  } else if (b - a > 1) {
    arr1.push_back(arr2[0]);
    sift_up_max(arr1, a);
    arr2[0] = arr2[b - 1];
    arr2.pop_back();
    sift_down_min(arr2, b - 1, 0);
  }
}

int main() {
  std::cout << std::fixed << std::setprecision(1);
  int n;
  std::cin >> n;
  std::vector<int> max_heap;
  std::vector<int> min_heap;
  std::string com;
  int x = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> com;
    if (com == "add") {
      std::cin >> x;
      if ((max_heap.size() == 0 && min_heap.size() == 0) ||
          (x <= max_heap.at(0))) {
        max_heap.push_back(x);
        sift_up_max(max_heap, max_heap.size() - 1);
      } else {
        min_heap.push_back(x);
        sift_up_min(min_heap, min_heap.size() - 1);
      }
      balance(max_heap, min_heap);
    } else if (com == "median") {
      if ((max_heap.size() + min_heap.size()) % 2 != 0) {
        if (max_heap.size() > min_heap.size()) {
          std::cout << (double)max_heap[0] << std::endl;
        } else {
          std::cout << (double)min_heap[0] << std::endl;
        }
      } else {
        std::cout << (double)((double)max_heap[0] + (double)min_heap[0]) / 2
                  << std::endl;
      }
    }
  }
}
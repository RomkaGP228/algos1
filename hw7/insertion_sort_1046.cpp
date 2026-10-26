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

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  insertion_sort(arr);
  int a = 0;
  int b = k - 1;
  int i = 0;
  int min_er = 1000000;
  while (b + i < arr.size()) {
    int er = arr[b + i] - arr[a + i];
    if (er < min_er) {
      min_er = er;
    }
    i++;
  }
  std::cout << min_er << std::endl;
}
#include <iostream>
#include <vector>

// перевернутый ins sort
void inv_insertion_sort(std::vector<int> &arr) {
  for (int i = 1; i < arr.size(); ++i) {
    int curr = arr[i];
    int j = i - 1;
    while (j >= 0 && curr >= arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = curr;
  }
}

void printer(int a) {
  if (a == 0) {
    std::cout << "Gold Medal";
  } else if (a == 1) {
    std::cout << "Silver Medal";
  } else if (a == 2) {
    std::cout << "Bronze Medal";
  } else {
    std::cout << a + 1;
  }
  std::cout << std::endl;
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  std::vector<int> uns_arr = arr;
  inv_insertion_sort(arr);
  for (auto elem : uns_arr) {
    for (int i = 0; i < arr.size(); ++i) {
      if (arr[i] == elem) {
        printer(i);
      }
    }
  }
}
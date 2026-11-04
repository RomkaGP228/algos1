#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> left, std::vector<int> right) {
  std::vector<int> res;
  int i = 0;
  int j = 0;
  while (i < left.size() && j < right.size()) {
    if (left[i] <= right[j]) {
      res.push_back(left[i]);
      i++;
    } else {
      res.push_back(right[j]);
      j++;
    }
  }
  res.insert(res.end(), left.begin() + i, left.end());
  res.insert(res.end(), right.begin() + j, right.end());
  return res;
}

std::vector<int> merge_sort(std::vector<int> arr) {
  if (arr.size() <= 1) {
    return arr;
  }
  int mid = arr.size() / 2;
  std::vector<int> left_arr(arr.begin(), arr.begin() + mid);
  std::vector<int> left = merge_sort(left_arr);
  std::vector<int> right_arr(arr.begin() + mid, arr.end());
  std::vector<int> right = merge_sort(right_arr);
  return merge(left, right);
}

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> arr(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }
  std::vector<int> sorted_arr = merge_sort(arr);
  for (int elem : sorted_arr) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}
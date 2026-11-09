#include <iostream>
#include <vector>

typedef std::pair<int, int> point;
int partition_lomuto(std::vector<point> &arr, int left, int right);

bool compare_points(point &a, point &b) {
  long long da =
      (long long)(a.first * a.first) + (long long)(a.second * a.second);
  long long db =
      (long long)(b.first * b.first) + (long long)(b.second * b.second);
  if (da != db) {
    return da < db;
  }
  return a < b;
}

void quick_sort_lomuto(std::vector<point> &arr, int left, int right) {
  if (left < right) {
    int pivot_pos = partition_lomuto(arr, left, right);
    quick_sort_lomuto(arr, left, pivot_pos - 1);
    quick_sort_lomuto(arr, pivot_pos + 1, right);
  }
}

int partition_lomuto(std::vector<point> &arr, int left, int right) {
  point pivot = arr[right];
  int i = left;
  for (int j = left; j < right; ++j) {
    if (compare_points(arr[j], pivot)) {
      point temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
      i++;
    }
  }
  point temp = arr[i];
  arr[i] = arr[right];
  arr[right] = temp;
  return i;
}

void quick_select(std::vector<point> &a, int k) {
  int left = 0, right = (int)a.size() - 1;
  while (left < right) {
    int p = partition_lomuto(a, left, right);
    if (p == k - 1)
      return;
    if (p > k - 1)
      right = p - 1;
    else
      left = p + 1;
  }
}

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<point> points(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> points[i].first >> points[i].second;
  }
  quick_select(points, k);
  quick_sort_lomuto(points, 0, k - 1);
  for (int i = 0; i < k; ++i) {
    std::cout << points[i].first << " " << points[i].second << std::endl;
  }
}
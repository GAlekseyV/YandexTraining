#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> read_nums(std::istream &is);

size_t find_left_entry(int n, const std::vector<int> v);

size_t find_right_entry(int n, const std::vector<int> v);

/*
 * Возвращает индекс первого элемента вектора v равного n
 */
template<class UnaryPredicate>
size_t findfirstgen(const std::vector<int> &v, int n, UnaryPredicate pred);

/*
 * Возвращает индекс последнего элемента вектора v равного n
 */
template<class UnaryPredicate>
size_t findlastlen(const std::vector<int> &v, int n, UnaryPredicate pred);


int main()
{
  std::vector<int> v_n = read_nums(std::cin);
  std::vector<int> v_m = read_nums(std::cin);

  for (size_t i = 1; i < v_m.size() - 1; i++) {
    std::cout << find_left_entry(v_m[i], v_n) << " "
              << find_right_entry(v_m[i], v_n) << "\n";
  }

  return 0;
}

std::vector<int> read_nums(std::istream &is)
{
  size_t size = 0;
  int num = 0;
  is >> size;
  size += 2;
  std::vector<int> nums(size, 0);
  nums[0] = -1'000'000'001;
  nums[size - 1] = 1'000'000'001;
  for (size_t i = 1; i < size - 1; i++) {
    is >> num;
    nums[i] = num;
  }
  return nums;
}

size_t find_left_entry(int n, const std::vector<int> v)
{
  size_t ans = 0;
  ans = findfirstgen(v, n, std::less<size_t>());
  if (v[ans] != n) {
    ans = 0;
  }
  return ans;
}

size_t find_right_entry(int n, const std::vector<int> v)
{
  size_t ans = 0;
  ans = findlastlen(v, n, std::less<size_t>());
  if (v[ans] != n) {
    ans = 0;
  }
  return ans;
}

template<class UnaryPredicate>
size_t findfirstgen(const std::vector<int> &v, int n, UnaryPredicate pred)
{
  size_t l = 0;
  size_t r = v.size() - 1;
  size_t m = 0;
  while (pred(l, r)) {
    m = (l + r) / 2;
    if (v[m] >= n) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}

template<class UnaryPredicate>
size_t findlastlen(const std::vector<int> &v, int n, UnaryPredicate pred)
{
  size_t l = 0;
  size_t r = v.size() - 1;
  size_t m = 0;
  while (pred(l, r)) {
    m = (l + r + 1) / 2;
    if (v[m] <= n) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  return l;
}
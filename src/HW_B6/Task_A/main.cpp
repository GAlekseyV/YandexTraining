#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> read_nums(std::istream &is);

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
  std::vector<int> nums = read_nums(std::cin);
  std::sort(nums.begin(), nums.end());

  int K = 0;
  std::cin >> K;

  while (K-- > 0) {
    int L = 0;
    int R = 0;
    std::cin >> L >> R;
    // Найти индекс первого элемента меньше или равного L
    // Найти индекс последнего элемента больше или равного R
    auto Lidx = findfirstgen(nums, L, std::less<size_t>());
    auto Ridx = findlastlen(nums, R, std::less<size_t>());

    size_t ans = 0;
    if (Ridx > Lidx) {
      ans = Ridx - Lidx + 1;
    } else if (Ridx == Lidx) {
      if (Ridx != 0 or Ridx != nums.size() - 1) {
        ans = 1;
      }
    }
    std::cout << ans << " " << std::endl;
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
  nums.at(0) = -1'000'000'001;
  nums.at(size - 1) = 1'000'000'001;
  for (size_t i = 1; i < size - 1; i++) {
    is >> num;
    nums[i] = num;
  }
  return nums;
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
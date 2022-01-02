#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main()
{
  size_t n{ 0 };// Количество котят
  size_t m{ 0 };// Количество отрезков

  std::cin >> n >> m;

  std::map<int, int> a_to_cnt;
  for (size_t i = 0; i < n; i++) {
    int ai{ 0 };
    std::cin >> ai;
    a_to_cnt[ai] += 1;
  }

  std::map<int, int> a_to_partsum;
  int prev_cnt{ 0 };
  for (const auto &[k, v] : a_to_cnt) {
    a_to_partsum[k] = prev_cnt;
    prev_cnt += v;
  }
  a_to_partsum[1'000'000'001] = prev_cnt;

  std::vector<std::pair<int, int>> sequences(m);
  for (auto &[l, r] : sequences) {
    std::cin >> l >> r;
  }

  for (const auto &[l, r] : sequences) {
    auto end = a_to_partsum.upper_bound(r);
    if (end == a_to_partsum.end()) {
      end = --a_to_partsum.end();
    }
    auto begin = a_to_partsum.lower_bound(l);
    std::cout << (*end).second - (*begin).second << "\n";
  }

  return 0;
}
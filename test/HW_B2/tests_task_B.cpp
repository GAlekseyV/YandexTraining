#include <algorithm>
#include <catch2/catch.hpp>
#include <cmath>
#include <vector>

size_t max_distance(const std::vector<int> &seq)
{
  size_t ans = 0;
  size_t distance = 0;

  std::vector<size_t> home_idxs = {};
  std::vector<size_t> shop_idxs = {};

  for (size_t i = 0; i < seq.size(); i++) {
    if (seq[i] == 1) { home_idxs.push_back(i); }
    if (seq[i] == 2) { shop_idxs.push_back(i); }
  }

  for (auto h_idx : home_idxs) {

    size_t min = seq.size();
    for (auto s_idx : shop_idxs) {
      distance = std::max(h_idx, s_idx) - std::min(h_idx, s_idx);
      if (distance < min) {
        min = distance;
      }
    }

    if (min > ans) {
      ans = min;
    }
  }

  return ans;
}

TEST_CASE("B. Homes and shops", " ")
{
  REQUIRE(max_distance({ 2, 0, 1, 1, 0, 1, 0, 2, 1, 2 }) == 3);
}

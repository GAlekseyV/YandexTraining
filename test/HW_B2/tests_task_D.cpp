#include <algorithm>
#include <catch2/catch.hpp>
#include <vector>

std::vector<int> calc_ans(const std::vector<int> &seq, int l);

TEST_CASE("D. Benches in the atrium", " ")
{
  REQUIRE(calc_ans({ 0, 2 }, 5) == std::vector<int>{ 2 });
  REQUIRE(calc_ans({ 1, 4, 8, 11 }, 13) == std::vector<int>{ 4, 8 });
  REQUIRE(calc_ans({ 1, 6, 8, 11, 12, 13 }, 14) == std::vector<int>{ 6, 8 });
  REQUIRE(calc_ans({ 0 }, 1) == std::vector<int>{ 0 });
}

bool isOdd(long long n)
{
  if (n % 2 == 1) {
    return true;
  }
  return false;
}

std::vector<int> calc_ans(const std::vector<int> &seq, int l)
{
  int border = 0;
  std::vector<int> ans;

  if (seq.size() == 1) {
    ans.push_back(seq[0]);
  } else {
    border = l / 2;
    auto it = std::lower_bound(seq.begin(), seq.end(), border);
    if (isOdd(l)) {
      if (*(it) == border) {
        ans.push_back(*it);
      } else {
        ans.push_back(*(it - 1));
        ans.push_back(*(it));
      }
    } else {
      ans.push_back(*(it - 1));
      ans.push_back(*(it));
    }
  }
  return ans;
}

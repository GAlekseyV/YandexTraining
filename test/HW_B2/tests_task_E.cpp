#include <algorithm>
#include <catch2/catch.hpp>
#include <vector>

unsigned long long calc_ans(const std::vector<unsigned> &seq);

TEST_CASE("E. Diplomas in folders", " ")
{
  REQUIRE(calc_ans({ 2, 1 }) == 1);
  REQUIRE(calc_ans({ 10 }) == 0);
  REQUIRE(calc_ans({ 2, 2 }) == 2);
  REQUIRE(calc_ans({ 2, 2, 3 }) == 4);
  REQUIRE(calc_ans({ 2, 2, 6 }) == 4);
  REQUIRE(calc_ans({ 1, 2, 3, 4, 5 }) == 10);
}

unsigned long long calc_ans(const std::vector<unsigned> &seq)
{
  unsigned long long ans = 0;
  std::vector<unsigned> sorted_seq = seq;

  if (seq.size() < 2) {
    ans = 0;
  } else {
    std::sort(sorted_seq.begin(), sorted_seq.end());
    unsigned long long sum = 0;
    for (auto num : sorted_seq) {
      sum += num;
    }
    sum -= sorted_seq[sorted_seq.size() - 1];
    ans = sum;
  }
  return ans;
}

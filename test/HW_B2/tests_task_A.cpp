#include <catch2/catch.hpp>
#include <vector>

unsigned int calc_equal_to_the_max(const std::vector<unsigned int> &seq)
{
  unsigned int counter = 0;

  if (!seq.empty()) {
    unsigned int curr_max = seq[0];
    for (const auto num : seq) {
      if (num > curr_max) {
        curr_max = num;
        counter = 0;
      }
      if (curr_max == num) {
        counter++;
      }
    }
  }

  return counter;
}

TEST_CASE("A. he number equal to the maximum", " ")
{
  REQUIRE(calc_equal_to_the_max({ 1, 7, 9 }) == 1);
  REQUIRE(calc_equal_to_the_max({ 1, 3, 3, 1 }) == 2);

  REQUIRE(calc_equal_to_the_max({}) == 0);
}

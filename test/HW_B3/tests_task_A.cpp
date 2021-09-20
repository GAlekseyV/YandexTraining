#include <catch2/catch.hpp>
#include <set>

int num_equals(const std::set<int> &set1, const std::set<int> &set2)
{
  int cnt = 0;
  for (auto item : set1) {
    if (set2.find(item) != set2.end()) {
      cnt++;
    }
  }
  return cnt;
}

TEST_CASE("A. Number of matches", " ")
{
  REQUIRE(num_equals({ 1, 3, 2 }, { 4, 3, 2 }) == 2);
  REQUIRE(num_equals({ 1, 2, 6, 4, 5, 7 }, { 10, 2, 3, 4, 8 }) == 2);
  REQUIRE(num_equals({ 1, 7, 3, 8, 10, 2, 5 }, { 6, 5, 2, 8, 4, 3, 7 }) == 5);
}

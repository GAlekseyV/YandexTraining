#include <algorithm>
#include <catch2/catch.hpp>
#include <string>
#include <string_view>

int calc_cost(const std::string &s);

TEST_CASE("C. Making palindromes", " ")
{
  REQUIRE(calc_cost("a") == 0);
  REQUIRE(calc_cost("ab") == 1);
  REQUIRE(calc_cost("cognitive") == 4);

  REQUIRE(calc_cost("bbb") == 0);
  REQUIRE(calc_cost("cdc") == 0);
  REQUIRE(calc_cost("kezplvfjaqmopodotkrj") == 10);
}

int calc_cost(const std::string &s)
{
  std::string rs(s);
  std::reverse(rs.begin(), rs.end());

  std::string_view rs_view(rs);
  std::string_view s_view(s);

  int counter = 0;

  for (size_t i = 0; i < (s.size() + 1) / 2; i++) {
    if (s_view[i] != rs_view[i]) {
      counter++;
    }
  }
  return counter;
}

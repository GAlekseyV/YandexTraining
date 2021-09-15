#include <catch2/catch.hpp>

int calc_stations(int N, int i, int j)
{
  int ans = 0;
  int max = 0;
  int min = 0;

  if (j > i) {
    max = j;
    min = i;
  } else {
    max = i;
    min = j;
  }

  if (max - min < 2) {
    ans = 0;
  } else {
    ans = max - min - 1;
    if (ans >= (N / 2)) {
      ans = N - max + min - 1;
    }
  }

  return ans;
}

TEST_CASE("B. Circle line", "Base tests")
{
  REQUIRE(calc_stations(100, 5, 6) == 0);
  REQUIRE(calc_stations(10, 1, 9) == 1);

  // Special cases
  REQUIRE(calc_stations(10, 10, 10) == 0);
  REQUIRE(calc_stations(10, 9, 10) == 0);
  REQUIRE(calc_stations(10, 10, 1) == 0);


  REQUIRE(calc_stations(10, 4, 6) == 1);
  REQUIRE(calc_stations(10, 6, 4) == 1);
  REQUIRE(calc_stations(5, 1, 4) == 1);
}

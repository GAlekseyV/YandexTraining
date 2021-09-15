#include <catch2/catch.hpp>

int calc_verdict(int r, int i, int c)
{
  if (i == 0) {
    int ans = 0;
    if (r != 0) {
      ans = 3;
    } else {
      ans = c;
    }
    return ans;
  }

  if (i == 1) {
    return c;
  }

  if (i == 4) {
    int ans = 0;
    if (r != 0) {
      ans = 3;
    } else {
      ans = 4;
    }
    return ans;
  }

  if (i == 6) {
    return 0;
  }

  if (i == 7) {
    return 1;
  }

  return i;
}

TEST_CASE("A. Interactor", " ")
{
  REQUIRE(calc_verdict(0, 0, 0) == 0);
  REQUIRE(calc_verdict(-1, 0, 1) == 3);
  REQUIRE(calc_verdict(42, 1, 6) == 6);
  REQUIRE(calc_verdict(44, 7, 4) == 1);
  REQUIRE(calc_verdict(1, 4, 0) == 3);
  REQUIRE(calc_verdict(-3, 2, 4) == 2);
}

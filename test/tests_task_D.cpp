#include <array>
#include <catch2/catch.hpp>

long calc_school_coordinate(const std::vector<long> &cs)
{
  return cs[0];
}

TEST_CASE("C. Dates", "[tests]")
{
  // Базовые тесты
  REQUIRE(calc_school_coordinate({ 1, 2, 3, 4 }) == 3);
  REQUIRE(calc_school_coordinate({ -1, 0, 1 }) == 0);
}

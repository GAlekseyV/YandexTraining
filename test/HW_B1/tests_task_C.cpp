#include <array>
#include <catch2/catch.hpp>

static const unsigned int months_in_years = 12;
static const std::array<unsigned int, months_in_years> days_in_months{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static const std::array<unsigned int, months_in_years> days_in_months_of_leap_year{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool is_leap_year(unsigned int y)
{
  bool ans = true;
  if (y % 400 != 0) {
    if (y % 100 == 0) {
      ans = false;
    } else {
      if (y % 4 != 0) {
        ans = false;
      }
    }
  }
  return ans;
}

bool is_correct_data(unsigned int d, unsigned int m, unsigned int y)
{
  bool ans = false;
  if (m <= months_in_years) {
    // Количество дней соответствует месяцу
    if (is_leap_year(y)) {
      if (d <= days_in_months_of_leap_year[m - 1]) {
        ans = true;
      }
    } else {
      if (d <= days_in_months[m - 1]) {
        ans = true;
      }
    }
  }
  return ans;
}

TEST_CASE("C. Dates", "[tests]")
{
  // Базовые тесты
  REQUIRE(is_correct_data(1, 2, 2003) == true);
  REQUIRE(is_correct_data(2, 29, 2008) == false);

  // Некорректный месяц
  REQUIRE(is_correct_data(1, 13, 2003) == false);
  REQUIRE(is_correct_data(1, 12, 2003) == true);

  // В невисокосном году
  REQUIRE(is_correct_data(31, 4, 2003) == false);
  REQUIRE(is_correct_data(25, 3, 2003) == true);

  // Високосный год
  REQUIRE(is_correct_data(29, 2, 2004) == true);
  REQUIRE(is_correct_data(29, 2, 2003) == false);
}

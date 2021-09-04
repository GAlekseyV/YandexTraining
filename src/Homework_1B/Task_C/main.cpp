#include <array>
#include <iostream>

static const unsigned int months_in_years = 12;
static const std::array<unsigned int, months_in_years> days_in_months{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static const std::array<unsigned int, months_in_years> days_in_months_of_leap_year{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool check_american_format(unsigned int m, unsigned int d, unsigned int y);
bool check_european_format(unsigned int d, unsigned int m, unsigned int y);
bool is_correct_data(unsigned int d, unsigned int m, unsigned int y);
bool is_leap_year(unsigned int y);

unsigned int check_unambiguity(unsigned int x, unsigned int y, unsigned int z);

int main(int argc, const char **argv)
{
  unsigned int x = 0;
  unsigned int y = 0;
  unsigned int z = 0;

  std::cin >> x >> y >> z;
  std::cout << check_unambiguity(x, y, z);

  return 0;
}

unsigned int check_unambiguity(unsigned int x, unsigned int y, unsigned int z)
{
  unsigned int ans = 2;// Некоректный ответ

  // Одна из дат обязательно корректна по условиям задачи
  if (check_american_format(x, y, z) != check_european_format(x, y, z)) {
    ans = 1;
  } else {// Обе даты корректны
    if (x == y) {// День равен номеру месяца
      ans = 1;
    } else {
      ans = 0;
    }
  }
  return ans;
}

bool check_american_format(unsigned int m, unsigned int d, unsigned int y)
{
  return is_correct_data(d, m, y);
}

bool check_european_format(unsigned int d, unsigned int m, unsigned int y)
{
  return is_correct_data(d, m, y);
}

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

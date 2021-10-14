#include <algorithm>
#include <catch2/catch.hpp>
#include <vector>

long long max_sum(const std::vector<long long> v)
{
  assert(&v);
  std::vector<long long> lprefix(v.size() + 1, 0L);

  size_t i = 1;
  for (const auto &a : v) {
    lprefix[i] = lprefix[i - 1] + a;
    i++;
  }

  long long l = lprefix[0];
  long long r = lprefix[1];
  long long ans = r - l;// Текущая максимальная сумма
  long long min = 0;// Текущий минимум


  for (i = 1; i < lprefix.size(); i++) {
    // Обновляем при необходимости минимум на интервале (0, i-1)
    min = std::min(min, lprefix[i - 1]);
    // Обновляем при необходимости максимум
    ans = std::max(ans, lprefix[i] - min);
  }

  return ans;
}

TEST_CASE("B. Maximum amount on a segment", "[parse line]")
{
  REQUIRE(max_sum({ 1, 2, 3, 4 }) == 10);
  REQUIRE(max_sum({ 5, 4, -10, 4 }) == 9);
  REQUIRE(max_sum({ -5, 1, 2, 10, -1, 5 }) == 17);
  REQUIRE(max_sum({ 4, -10, 4, 5 }) == 9);
  REQUIRE(max_sum({ -1, -2, -3, -4, -5 }) == -1);
  REQUIRE(max_sum({ -5, -4, -3, -2, -1 }) == -1);
  REQUIRE(max_sum({ 450402558, -840167367, -231820501, 586187125, -627664644 }) == 586187125);
}

#include <algorithm>
#include <catch2/catch.hpp>
#include <vector>

// Поиск первого элемента в последовательности, который больше
// или равен n
template<class UnaryPredicate>
size_t findfirstgen(const std::vector<int> &v, int n, UnaryPredicate pred)
{
  size_t l = 0;
  size_t r = v.size() - 1;
  size_t m = 0;
  while (pred(l, r)) {
    m = (l + r) / 2;
    if (v[m] >= n) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}

// Поиск последнего элемента в последовательности меньшего или
// равного n
template<class UnaryPredicate>
size_t findlastlen(const std::vector<int> &v, int n, UnaryPredicate pred)
{
  size_t l = 0;
  size_t r = v.size() - 1;
  size_t m = 0;
  while (pred(l, r)) {
    m = (l + r + 1) / 2;
    if (v[m] <= n) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  return l;
}

//Сколько чисел в массиве имеют значения от L до R
int calcnums(const std::vector<int> &v, int l, int r)
{
  size_t ans = 0;
  auto Lidx = findfirstgen(v, l, std::less<size_t>());
  auto Ridx = findlastlen(v, r, std::less<size_t>());

  if (Ridx > Lidx) {
    ans = Ridx - Lidx + 1;
  } else if (Ridx == Lidx) {
    if (Ridx != 0 or Ridx != v.size() - 1) {
      ans = 1;
    }
  }
  return static_cast<int>(ans);
}

TEST_CASE("A. Binary search. Find first greater or equal n", "[findfirstgen]")
{
  std::vector<int> v{ -1'000'000'001, 1, 2, 3, 4, 1'000'000'001 };
  REQUIRE(findfirstgen(v, 2, std::less<size_t>()) == 2);
  REQUIRE(findfirstgen(v, 1, std::less<size_t>()) == 1);
  REQUIRE(findfirstgen(v, 4, std::less<size_t>()) == 4);

  REQUIRE(findfirstgen(v, 0, std::less<size_t>()) == 1);
  REQUIRE(findfirstgen(v, 5, std::less<size_t>()) == 5);

  v = { -1'000'000'001, 1, 3, 5, 100, 1'000'000'001 };
  REQUIRE(findfirstgen(v, 4, std::less<size_t>()) == 3);

  v = { -1'000'000'001, 1, 3, 3, 3, 1'000'000'001 };
  REQUIRE(findfirstgen(v, 3, std::less<size_t>()) == 2);

  v = { -1'000'000'001, 1, 1'000'000'001 };
  REQUIRE(findfirstgen(v, 1, std::less<size_t>()) == 1);
  REQUIRE(findfirstgen(v, -1'000'000'000, std::less<size_t>()) == 1);
  REQUIRE(findfirstgen(v, 1'000'000'000, std::less<size_t>()) == 2);
}

TEST_CASE("A. Binary search. Find last less or equal n", "[findlastgen]")
{
  std::vector<int> v = { -1'000'000'001, 1, 2, 3, 4, 1'000'000'001 };
  REQUIRE(findlastlen(v, 2, std::less<size_t>()) == 2);
  REQUIRE(findlastlen(v, 1, std::less<size_t>()) == 1);
  REQUIRE(findlastlen(v, 4, std::less<size_t>()) == 4);

  REQUIRE(findlastlen(v, 0, std::less<size_t>()) == 0);
  REQUIRE(findlastlen(v, 5, std::less<size_t>()) == 4);

  v = { -1'000'000'001, 1, 3, 5, 100, 1'000'000'001 };
  REQUIRE(findlastlen(v, 4, std::less<size_t>()) == 2);

  v = { -1'000'000'001, 1, 2, 2, 2, 1'000'000'001 };
  REQUIRE(findlastlen(v, 2, std::less<size_t>()) == 4);

  v = { -1'000'000'001, 1, 1'000'000'001 };
  REQUIRE(findlastlen(v, 1, std::less<size_t>()) == 1);
  REQUIRE(findlastlen(v, -1'000'000'000, std::less<size_t>()) == 0);
  REQUIRE(findlastlen(v, 1'000'000'000, std::less<size_t>()) == 1);
}

TEST_CASE("A. Binary search. Calculate numbers from L to R", "[calcnums]")
{
  std::vector<int> v = { -1'000'000'001, 1, 3, 4, 10, 10, 1'000'000'001 };
  REQUIRE(calcnums(v, 1, 10) == 5);
  REQUIRE(calcnums(v, 2, 9) == 2);
  REQUIRE(calcnums(v, 3, 4) == 2);
  REQUIRE(calcnums(v, 2, 2) == 0);

  v = { -1'000'000'001, 1, 1'000'000'001 };
  REQUIRE(calcnums(v, 1, 1) == 1);
  REQUIRE(calcnums(v, -1'000'000'000, -1'000'000'000) == 0);
  REQUIRE(calcnums(v, 1'000'000'000, 1'000'000'000) == 0);

  v = { -1'000'000'000, 0, 1'000'000'000 };
  REQUIRE(calcnums(v, -1'000'000'000, -1'000'000'000) == 1);
  REQUIRE(calcnums(v, 1'000'000'000, 1'000'000'000) == 1);
  REQUIRE(calcnums(v, -1'000'000'000, 1'000'000'000) == 3);
  REQUIRE(calcnums(v, -999'999'999, 999'999'999) == 1);
  REQUIRE(calcnums(v, -999'999, 1'000'000'000) == 2);
  REQUIRE(calcnums(v, -1'000'000'000, 999'999'999) == 2);
  REQUIRE(calcnums(v, 0, 999'999'999) == 1);
  REQUIRE(calcnums(v, -1, 999'999'999) == 1);
  REQUIRE(calcnums(v, 1, 999'999'999) == 0);
  REQUIRE(calcnums(v, -999'999'999, -1) == 0);
  REQUIRE(calcnums(v, -999'999'999, 0) == 1);
  REQUIRE(calcnums(v, -999'999'999, 1) == 1);
}
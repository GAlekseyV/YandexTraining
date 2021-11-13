#include <algorithm>
#include <iostream>
#include <vector>

/*
 * Расчитывает сколько отрезков длинной lenght достаточно, чтобы
 * чтобы покрыть все точки вектора dots. Вектор dots должен быть
 * отсортирован по возрастанию.
 */
int calc_segments(const std::vector<int> &dots, long long lenght);

int main()
{
  size_t n = 1;
  int k = 1;

  std::cin >> n >> k;

  std::vector<int> dots(n);
  // Read nums
  for (auto &item : dots) {
    std::cin >> item;
  }

  std::sort(dots.begin(), dots.end());

  long long l = 0;
  long long r = (dots[dots.size() - 1] - dots[0] + 1) / k;

  while (l < r) {
    long long m = (r + l) / 2;
    if (calc_segments(dots, m) > k) {
      l = m + 1;
    } else {
      r = m;
    };
  }

  std::cout << l;

  return 0;
}

int calc_segments(const std::vector<int> &dots, long long lenght)
{
  int cnt = 0;
  long long end_of_segment = -1'000'000'001;
  for (const auto &dot : dots) {
    if (dot > end_of_segment) {
      cnt++;
      end_of_segment = dot + lenght;
    }
  }
  return cnt;
}
#include <iostream>

int calc_stations(int N, int i, int j);

int main(int argc, const char **argv)
{
  int N = 0;
  int i = 0;
  int j = 0;

  std::cin >> N >> i >> j;
  std::cout << calc_stations(N, i, j);

  return 0;
}

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
    if (ans >= N / 2) {
      ans = N - max + min - 1;
    }
  }

  return ans;
}
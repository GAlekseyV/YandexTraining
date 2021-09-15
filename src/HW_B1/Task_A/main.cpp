#include <iostream>

int calc_verdict(int r, int i, int c);

int main(int argc, const char **argv)
{
  int r = 0;
  int i = 0;
  int c = 0;

  std::cin >> r >> i >> c;
  std::cout << calc_verdict(r, i, c);

  return 0;
}

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
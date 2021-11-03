#include <algorithm>
#include <cmath>
#include <iostream>

long double calc_f(long double a, long double b, long double c, long double d, long double x);

int main()
{
  // Коэффициенты уравнения
  long double a = 0.0;
  long double b = 0.0;
  long double c = 0.0;
  long double d = 0.0;

  std::cin >> a >> b >> c >> d;

  long double l = -1001.0;
  long double r = 1001.0;
  long double eps = 0.000001;
  long double x = 0.5 * (l + r);
  long double prev_x = 1001;

  long double f_l = 0.0;
  long double f_r = 0.0;
  long double f_x = 0.0;

  while (std::abs(prev_x - x) > eps) {
    // По условиям задания уравнение имеет ровно 1 корень
    // и следовательно пересекает ось х ровно 1 раз.
    f_l = calc_f(a, b, c, d, l);
    f_r = calc_f(a, b, c, d, r);
    f_x = calc_f(a, b, c, d, x);
    if (f_l > 0 && f_r < 0) {
      (f_x >= 0) ? l = x : r = x;
    } else if (f_l < 0 && f_r > 0) {
      (f_x >= 0) ? r = x : l = x;
    } else {
      x = prev_x;
      break;
    }
    prev_x = x;
    x = 0.5 * (l + r);
  }

  std::cout.precision(10);
  std::cout << x;

  return 0;
}

long double calc_f(long double a, long double b, long double c, long double d, long double x)
{
  return a * x * x * x + b * x * x + c * x + d;
}
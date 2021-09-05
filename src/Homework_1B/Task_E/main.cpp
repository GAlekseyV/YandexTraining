#include <iostream>
#include <cmath>

int check_dot(int d, int Xx, int Xy);

int main()
{
  int d = 0;
  int Xx = 0;
  int Xy = 0;

  std::cin >> d >> Xx >> Xy;

  std::cout << check_dot(d, Xx, Xy);

  return 0;
}

bool is_dot_in_triangle(int d, int Xx, int Xy)
{
  return (Xx >= 0 and Xx <= d) and (Xy >= 0 and Xy <= d) and (Xy <= -Xx + d);
}

double dist(int x1, int y1, int x2, int y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int check_dot(int d, int Xx, int Xy)
{
  int ans = 0;
  if (is_dot_in_triangle(d, Xx, Xy)) {
    ans = 0;
  } else {
    double dist_AX = dist(Xx, Xy, 0, 0);
    double dist_BX = dist(Xx, Xy, d, 0);
    double dist_CX = dist(Xx, Xy, 0, d);

    if ((dist_AX <= dist_BX) and (dist_AX <= dist_CX)) {
      ans = 1;
    } else if (dist_BX <= dist_CX) {
      ans = 2;
    } else {
      ans = 3;
    }
  }
  return ans;
}
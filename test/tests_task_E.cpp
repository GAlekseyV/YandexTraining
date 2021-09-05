#include <catch2/catch.hpp>
#include <cmath>

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

TEST_CASE("E. Triangle and Dot", "[tests]")
{
  // Точка внутри треугольника
  REQUIRE(check_dot(5, 1, 1) == 0);

  // Точка снаружи треугольника и ближе к вершине А
  REQUIRE(check_dot(3, -1, -1) == 1);

  // Точка лежит на равном расстоянии от вершин B и C,
  // в этом случае нужно вывести ту вершину, у которой номер меньше,
  // т.е. выведено должно быть число 2
  REQUIRE(check_dot(4, 4, 4) == 2);

  // Точка лежит на стороне треугольника.
  REQUIRE(check_dot(4, 2, 2) == 0);
}

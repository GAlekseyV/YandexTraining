#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

const double PI = 3.141592653589793;

struct polar_rect
{
  double r1;
  double r2;
  double angle1;
  double angle2;

  friend std::istream &operator>>(std::istream &is, polar_rect &rect)
  {
    is >> rect.r1 >> rect.r2 >> rect.angle1 >> rect.angle2;
    return is;
  }
};

enum event_type { END = 0,
  START };

struct event
{
  event_type type;
  double r;
  double angle;
};

bool is_double_equal(double a, double b)
{
  return a == b || std::abs(a - b) < std::abs(std::min(a, b)) * std::numeric_limits<double>::epsilon();
}

int main()
{
  size_t N{ 0 };
  std::cin >> N;

  std::vector<polar_rect> rects;
  std::vector<event> events;
  for (size_t i{ 0 }; i < N; ++i) {
    polar_rect r;
    std::cin >> r;
    if (r.angle1 > r.angle2) {
      // Если прямоугольник пересекает 0, то разбиваем его на два
      rects.push_back({ r.r1, r.r2, r.angle1, 2 * PI });
      events.push_back({ event_type::START, r.r1, r.angle1 });
      events.push_back({ event_type::END, r.r2, 2 * PI });

      rects.push_back({ r.r1, r.r2, 0, r.angle2 });
      events.push_back({ event_type::START, r.r1, 0 });
      events.push_back({ event_type::END, r.r2, r.angle2 });
    } else {
      rects.push_back(r);
      events.push_back({ event_type::START, r.r1, r.angle1 });
      events.push_back({ event_type::END, r.r2, r.angle2 });
    }
  }

  // Сортировка по радиусам
  std::sort(events.begin(), events.end(), [](auto &a, auto &b) {
    if (is_double_equal(a.r, b.r)) {
      return a.type < b.type;
    }
    return a.r < b.r;
  });

  // Определить участок пересечения всех радиусов
  size_t cnt{ 0 };
  double r_min{ 0.0 };
  double r_max{ 0.0 };
  for (const auto &ev : events) {
    if (ev.type == event_type::START) {
      cnt++;
      if (cnt == rects.size()) {
        r_min = ev.r;
      }
    } else if (ev.type == event_type::END) {
      if (cnt == rects.size()) {
        r_max = ev.r;
      }
      cnt--;
    }
  }

  // Сортировка по углам
  std::sort(events.begin(), events.end(), [](auto &a, auto &b) {
    if (is_double_equal(a.angle, b.angle)) {
      return a.type < b.type;
    }
    return a.angle < b.angle;
  });

  // Участки пересечения секторов
  cnt = 0;
  double angle_min{ 0.0 };
  double angle_max{ 0.0 };
  double delta_angle{ 0.0 };
  for (const auto &ev : events) {
    if (ev.type == event_type::START) {
      cnt++;
      if (cnt == N) {
        angle_min = ev.angle;
      }
    } else if (ev.type == event_type::END) {
      if (cnt == N) {
        angle_max = ev.angle;
        delta_angle += angle_max - angle_min;
      }
      cnt--;
    }
  }
  std::cout.precision(12);
  std::cout << 0.5 * (r_max - r_min) * (r_max + r_min) * (delta_angle) << std::endl;

  return 0;
}

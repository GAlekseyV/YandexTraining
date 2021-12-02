#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

enum class Event { END = 0,
  START };

int main()
{
  size_t N = 0;
  std::cin >> N;

  std::vector<std::pair<int, Event>> events(2 * N);

  for (size_t i = 0; i < 2 * N; i += 2) {
    int T = 0;
    std::cin >> T;
    events[i] = std::make_pair(T, Event::START);
    int L = 0;
    std::cin >> L;
    events[i + 1] = std::make_pair(T + L, Event::END);
  }

  std::sort(events.begin(), events.end(), [](const auto &l, const auto &r) {
    if (l.first != r.first) {
      return l.first < r.first;
    }
    return l.second < r.second;
  });

  int cnt = 0;
  int max_cnt = 0;

  for (const auto &ev : events) {
    if (ev.second == Event::START) {
      cnt++;
      max_cnt = std::max(cnt, max_cnt);
    } else if (ev.second == Event::END) {
      cnt--;
    }
  }

  std::cout << max_cnt << std::endl;

  return 0;
}

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

enum class Event { START = 0,
  END };

int main()
{
  size_t N = 0;
  std::cin >> N;

  std::vector<std::pair<int, Event>> events(2 * N);

  for (size_t i = 0; i < 2 * N; i += 2) {
    int l = 0;
    std::cin >> l;
    events[i] = std::make_pair(l, Event::START);
    int r = 0;
    std::cin >> r;
    events[i + 1] = std::make_pair(r, Event::END);
  }

  std::sort(events.begin(), events.end(), [](const auto &l, const auto &r) {
    if (l.first != r.first) {
      return l.first < r.first;
    }
    return l.second < r.second;
  });

  int cnt = 0;
  int sum_painted_line = 0;
  int painted_line = 0;
  int start = 0;

  for (const auto &ev : events) {
    if (ev.second == Event::START) {
      if(cnt == 0){
        start = ev.first;
      }
      cnt++;
    } else if (ev.second == Event::END) {
      cnt--;
      if(cnt == 0){
        painted_line = ev.first - start;
        sum_painted_line += painted_line;
      }
    }
  }

  std::cout << sum_painted_line << std::endl;

  return 0;
}

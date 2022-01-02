#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using segment = std::pair<int, int>;

int main()
{
  int M{ 0 };

  std::vector<segment> segments;

  std::cin >> M;

  int Li = 0;
  int Ri = 0;
  std::cin >> Li;
  std::cin >> Ri;

  while (!(Li == 0 && Ri == 0)) {
    auto l = std::make_pair(Li, Ri);
    if (Ri > 0 && Li < M) {
      segments.push_back(l);
    }

    std::cin >> Li;
    std::cin >> Ri;
  }

  std::sort(segments.begin(), segments.end(), [](const auto &lhs, const auto &rhs) {
    if (lhs.first == rhs.first) {
      return lhs.second < rhs.second;
    }
    return lhs.first < rhs.first;
  });

  std::vector<segment> ans;
  int currR = 0;
  int nextR = 0;
  segment curr_seg = std::make_pair(0, 0);

  for (const auto &seg : segments) {
    auto [l, r] = seg;
    if (l > currR) {
      ans.push_back(curr_seg);
      currR = nextR;
      if (currR >= M) {
        break;
      }
    }
    if (l <= currR && r > nextR) {
      nextR = r;
      curr_seg = seg;
    }
  }

  if (currR < M) {
    currR = nextR;
    ans.push_back(curr_seg);
  }
  if (currR < M) {
    std::cout << "No solution" << std::endl;
  } else {
    std::cout << ans.size() << "\n";
    for (const auto &[l, r] : ans) {
      std::cout << l << " " << r << "\n";
    }
  }

  return 0;
}

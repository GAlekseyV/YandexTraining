#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <vector>

void skipSpaces(std::stringstream &is);

int main()
{
  int N = 0;
  int M = 0;
  std::cin >> N >> M;

  std::map<int, std::list<int>> X_to_Nidx;
  std::map<int, std::list<int>> Y_to_Midx;
  std::vector<int> ans(N);
  int cnt = 0;

  int n = 0;
  for (size_t i = 0; i < N; i++) {
    std::cin >> n;
    X_to_Nidx[n].push_back(static_cast<int>(i + 1));
  }

  for (size_t j = 0; j < M; j++) {
    std::cin >> n;
    Y_to_Midx[n].push_back(static_cast<int>(j + 1));
  }

  auto lit = X_to_Nidx.begin();
  auto rit = Y_to_Midx.begin();

  while (lit != X_to_Nidx.end() and rit != Y_to_Midx.end()) {
    if ((*lit).first < (*rit).first) {
      ans[(*lit).second.front() - 1] = (*rit).second.front();
      cnt++;
      (*lit).second.pop_front();
      (*rit).second.pop_front();
      if ((*lit).second.empty()) {
        lit++;
      }
      if ((*rit).second.empty()) {
        rit++;
      }
    } else {
      rit++;
    }
  }

  std::cout << cnt << '\n';
  for (const auto &elem : ans) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  return 0;
}
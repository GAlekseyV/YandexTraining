#include <algorithm>
#include <iostream>
#include <map>
#include <string>

std::map<unsigned int, int> read_nums(std::istream &is);

int main(__attribute__((unused)) int argc, __attribute__((unused)) const char **argv)
{
  unsigned int S = 0;
  std::cin >> S;

  std::map<unsigned int, int> A_to_min_idx = read_nums(std::cin);
  std::map<unsigned int, int> B_to_min_idx = read_nums(std::cin);
  std::map<unsigned int, int> C_to_min_idx = read_nums(std::cin);

  const int MAX_N = 15001;
  unsigned int ans_i = MAX_N;
  unsigned int ans_j = MAX_N;
  unsigned int ans_k = MAX_N;

  auto Ait = A_to_min_idx.begin();

  while (Ait != A_to_min_idx.end()) {
    if ((*Ait).first + (*B_to_min_idx.rbegin()).first + (*C_to_min_idx.rbegin()).first >= S) {
      auto Bit = B_to_min_idx.begin();
      auto Cit = C_to_min_idx.rbegin();
      while (Bit != B_to_min_idx.end() && Cit != C_to_min_idx.rend()) {
        unsigned int sum = (*Bit).first + (*Cit).first;
        if (sum > S - (*Ait).first) {
          Cit++;
        } else if (sum < S - (*Ait).first) {
          Bit++;
        } else {
          unsigned int cur_i = (*Ait).second;
          unsigned int cur_j = (*Bit).second;
          unsigned int cur_k = (*Cit).second;

          if (ans_i > cur_i) {
            ans_i = cur_i;
            ans_j = cur_j;
            ans_k = cur_k;
          } else if (ans_i == cur_i && ((ans_j > cur_j) || (ans_j == cur_j && ans_k > cur_k))) {
            ans_i = cur_i;
            ans_j = cur_j;
            ans_k = cur_k;
          }
          Bit++;
        }
      }
    }
    Ait++;
  }

  if (ans_i != MAX_N) {
    std::cout << ans_i << " "
              << ans_j << " "
              << ans_k;
  } else {
    std::cout << -1;
  }
  std::cout << std::endl;

  return 0;
}

std::map<unsigned int, int> read_nums(std::istream &is)
{
  int size = 0;
  unsigned int n = 0;
  is >> size;
  std::map<unsigned int, int> m;
  for (int i = 0; i < size; i++) {
    is >> n;
    if (m.count(n) == 0) {
      m[n] = i;
    }
  }
  return m;
}
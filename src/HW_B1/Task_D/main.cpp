#include <iostream>
#include <vector>

long calc_school_coordinate(const std::vector<long> &cs);

int main(int argc, const char **argv)
{
  unsigned int N;
  std::cin >> N;

  std::vector<long> cs(N);

  for (size_t i = 0; i < N; i++) {
    long num;
    std::cin >> num;
    cs[i] = num;
  }

  std::cout << calc_school_coordinate(cs);

  return 0;
}

long calc_school_coordinate(const std::vector<long> &cs)
{
  long ans = 0;
  if (cs.size() % 2 == 1) {
    ans = cs[cs.size() / 2];
  } else {
    ans = (cs[cs.size() / 2 - 1] + cs[cs.size() / 2]) / 2;
  }
  return ans;
}
#include <algorithm>
#include <iostream>
#include <vector>

unsigned long long calc_ans(const std::vector<unsigned> &seq);

int main(int argc, const char **argv)
{
  int N = 0;
  int K = 0;

  std::cin >> N;

  std::vector<unsigned> A;

  for (size_t i = 0; i < N; i++) {
    int num = -1;
    std::cin >> num;
    A.push_back(num);
  }

  std::cout << calc_ans(A) << std::endl;

  return 0;
}

unsigned long long calc_ans(const std::vector<unsigned> &seq)
{
  unsigned long long ans = 0;
  std::vector<unsigned> sorted_seq = seq;

  if (seq.size() < 2) {
    ans = 0;
  } else {
    std::sort(sorted_seq.begin(), sorted_seq.end());
    unsigned long long sum = 0;
    for (auto num : sorted_seq) {
      sum += num;
    }
    sum -= sorted_seq[sorted_seq.size() - 1];
    ans = sum;
  }
  return ans;
}
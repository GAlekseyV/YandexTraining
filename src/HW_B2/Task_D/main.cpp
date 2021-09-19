#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> calc_ans(const std::vector<int> &seq, int l);
bool isOdd(long long n);

int main(int argc, const char **argv)
{
  int L = 0;
  int K = 0;

  std::cin >> L >> K;
  std::vector<int> seq(K);

  for (size_t i = 0; i < K; i++) {
    int num = -1;
    std::cin >> num;
    seq[i] = num;
  }

  for (auto num : calc_ans(seq, L)) {
    std::cout << num << " ";
  }

  return 0;
}

bool isOdd(long long n)
{
  bool ans = false;
  if (n % 2 == 1) {
    ans = true;
  }
  return ans;
}

std::vector<int> calc_ans(const std::vector<int> &seq, int l)
{
  int border = 0;
  std::vector<int> ans;

  if (seq.size() == 1) {
    ans.push_back(seq[0]);
  } else {
    border = l / 2;
    auto it = std::lower_bound(seq.begin(), seq.end(), border);
    if (isOdd(l)) {
      if (*(it) == border) {
        ans.push_back(*it);
      } else {
        ans.push_back(*(it - 1));
        ans.push_back(*(it));
      }
    } else {
      ans.push_back(*(it - 1));
      ans.push_back(*(it));
    }
  }
  return ans;
}
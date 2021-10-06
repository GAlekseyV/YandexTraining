#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
  unsigned int n = 0;
  std::cin >> n;

  long long a = 0;
  std::vector<long long> seq(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a;
    seq[i] = a;
  }

  long long lmax = seq[0];
  long long rmax = seq[seq.size() - 1];

  std::vector<long long> lprefix(seq.size() + 1);

  lprefix[0] = 0;
  size_t i = 1;
  for (const auto a : seq) {
    lprefix[i] = lprefix[i - 1] + a;
    lmax = std::max(lprefix[i], lmax);
    i++;
  }

  long long l = lprefix[0];
  long long r = lprefix[1];
  long long ans = r - l;// Текущая максимальная сумма
  long long min = 0;// Текущий минимум


  for (i = 1; i < lprefix.size(); i++) {
    // Обновляем при необходимости минимум на интервале (0, i-1)
    min = std::min(min, lprefix[i - 1]);
    // Обновляем при необходимости максимум
    ans = std::max(ans, lprefix[i] - min);
  }

  std::cout << ans;

  return 0;
}

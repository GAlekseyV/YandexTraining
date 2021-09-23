#include <iostream>
#include <map>


int main(int argc, const char **argv)
{
  unsigned int n = 0;
  std::cin >> n;

  long long d = 0;
  long long a = 0;

  std::map<long long, long long> d_to_sum_a;

  for (size_t i = 0; i < n; i++) {
    std::cin >> d >> a;
    d_to_sum_a[d] += a;
  }

  for (auto pair : d_to_sum_a) {
    std::cout << pair.first << " " << pair.second << std::endl;
  }

  return 0;
}

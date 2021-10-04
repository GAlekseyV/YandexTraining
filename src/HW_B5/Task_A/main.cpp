#include <iostream>
#include <vector>


int main()
{
  unsigned int n = 0;
  unsigned int q = 0;
  std::cin >> n >> q;

  long long a = 0;
  long long sum = 0;

  std::vector<long long> prefix(n + 1);
  prefix[0] = 0;
  for (size_t i = 1; i < prefix.size(); i++) {
    std::cin >> a;
    prefix[i] = prefix[i - 1] + a;
  }

  int l = 0;
  int r = 0;
  for (size_t i = 0; i < q; i++) {
    std::cin >> l >> r;
    std::cout << prefix[r] - prefix[l - 1] << std::endl;
  }

  return 0;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>

int calc_cost(const std::string &s);

int main()
{
  std::string s = {};
  std::cin >> s;

  std::cout << calc_cost(s) << std::endl;

  return 0;
}

int calc_cost(const std::string &s)
{
  std::string rs(s);
  std::reverse(rs.begin(), rs.end());

  int counter = 0;

  for (size_t i = 0; i < (s.size() + 1) / 2; i++) {
    if (s[i] != rs[i]) {
      counter++;
    }
  }
  return counter;
}

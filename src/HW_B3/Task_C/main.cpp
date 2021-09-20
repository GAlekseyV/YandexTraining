#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int calc_cost(const std::string &s);

int main()
{
  std::string line;
  std::getline(std::cin, line);
  std::stringstream ss;
  ss << line;

  int num = 0;
  std::map<int, int> num_to_cnt;
  std::vector<int> nums;

  while (ss >> num) {
    num_to_cnt[num] += 1;
    nums.push_back(num);
  }

  for (auto num : nums) {
    if (num_to_cnt[num] == 1) {
      std::cout << num << " ";
    }
  }
  std::cout << std::endl;
  return 0;
}

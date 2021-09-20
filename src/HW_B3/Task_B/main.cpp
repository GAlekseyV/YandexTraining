#include <iostream>
#include <set>
#include <sstream>
#include <string>

int main()
{
  std::string line;
  std::getline(std::cin, line);
  std::stringstream ss;
  ss << line;

  int num = 0;
  std::set<int> nums;
  while (ss >> num) {
    if (nums.find(num) != nums.end()) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
    nums.insert(num);
  }

  return 0;
}

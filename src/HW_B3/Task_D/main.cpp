#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, const char **argv)
{
  int n = -1;
  std::set<int> not_ans;
  std::set<int> ans;

  std::cin >> n;

  std::string line;
  std::getline(std::cin, line);
  std::getline(std::cin, line);
  while (line != "HELP") {
    std::stringstream ss;
    ss << line;

    // Считывает вопрос
    std::vector<int> nums;
    int num = -1;
    while (ss >> num) {
      nums.push_back(num);
    }

    // Считывает ответ
    std::getline(std::cin, line);

    if (line == "NO") {
      not_ans.insert(nums.begin(), nums.end());
    } else if (line == "YES") {
      if (ans.empty()) {
        ans.insert(nums.begin(), nums.end());
      } else {
        std::set<int> ts;
        for (auto n : nums) {
          if (ans.count(n) != 0) {// нет в множестве
            ts.insert(n);
          }
        }
        ans = ts;
      }
    }

    std::getline(std::cin, line);
  }

  for (int i = 1; i <= n; i++) {
    if (not_ans.count(i) == 0) {// Числа нет в списке неправильных
      if (ans.empty() or ans.count(i) != 0) {// Число возможно ответ
        std::cout << i << " ";
      }
    }
  }
  std::cout << std::endl;

  return 0;
}

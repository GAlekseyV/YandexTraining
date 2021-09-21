#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

bool is_s_in_n(const std::set<char> &s, const std::set<char> &n);

int main(int argc, const char **argv)
{
  int M = 0;
  int N = 0;

  std::map<std::set<char>, int> set_to_cnt;

  // Считываем версии
  std::cin >> M;// Количество версий

  // Словарь с подсчетом числа версий соответствующих множеству
  std::map<std::set<char>, int> set_to_weight;

  std::string tmpstr;
  for (size_t i = 0; i < M; i++) {
    std::cin >> tmpstr;
    std::set<char> s;
    s.insert(tmpstr.begin(), tmpstr.end());
    set_to_weight[s] += 1;
  }

  // Считываем номера для проверки
  std::cin >> N;// Количество номеров

  std::vector<std::string> numbers;
  std::map<std::string, std::set<char>> number_to_set;
  std::map<std::set<char>, std::vector<std::string>> set_to_numbers;

  for (size_t i = 0; i < N; i++) {
    std::cin >> tmpstr;
    numbers.push_back(tmpstr);
    std::set<char> s;
    s.insert(tmpstr.begin(), tmpstr.end());
    if (number_to_set.count(tmpstr) == 0) {
      set_to_numbers[s].push_back(tmpstr);
    }
    number_to_set[tmpstr] = s;
  }

  int max_cnt = 0;
  for (const auto item : set_to_numbers) {
    int cnt = 0;
    if (set_to_cnt.count(item.first) == 0) {
      for (const auto sw : set_to_weight) {
        if (is_s_in_n(sw.first, item.first)) {
          cnt += sw.second;
        }
      }
      set_to_cnt[item.first] = cnt;
      if (max_cnt < cnt) {
        max_cnt = cnt;
      }
    }
  }

  for (const auto n : numbers) {
    if (set_to_cnt[number_to_set[n]] == max_cnt) {
      std::cout << n << std::endl;
    }
  }

  return 0;
}

bool is_s_in_n(const std::set<char> &s, const std::set<char> &n)
{
  for (auto item : s) {
    if (n.count(item) == 0) {
      return false;
    }
  }
  return true;
}
#include <iostream>
#include <set>
#include <sstream>
#include <string>

int num_equals(const std::set<int> &set1, const std::set<int> &set2);

std::set<int> read_set_from_line(const std::string &line);

int main(int argc, const char **argv)
{
  std::string line;
  std::getline(std::cin, line);
  std::set<int> s1 = read_set_from_line(line);
  std::getline(std::cin, line);
  std::set<int> s2 = read_set_from_line(line);

  std::cout << num_equals(s1, s2);

  return 0;
}

std::set<int> read_set_from_line(const std::string &line)
{
  std::stringstream ss;
  ss << line;

  int num = 0;
  std::set<int> out;
  while (ss >> num) {
    out.insert(num);
  }
  return out;
}

int num_equals(const std::set<int> &set1, const std::set<int> &set2)
{
  int cnt = 0;
  for (auto item : set1) {
    if (set2.find(item) != set2.end()) {
      cnt++;
    }
  }
  return cnt;
}
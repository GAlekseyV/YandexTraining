#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

void skipSpaces(std::stringstream &is);

int main()
{
  std::map<std::string, long> word_to_cnt;
  std::string line;
  std::getline(std::cin, line);
  std::string word;

  while (!line.empty()) {
    std::stringstream ss;
    ss << line;
    while (!ss.eof()) {
      ss >> word;
      skipSpaces(ss);
      word_to_cnt[word] += 1;
    }
    std::getline(std::cin, line);
  }

  std::vector<std::pair<int, std::string>> vp;

  for (const auto &pair : word_to_cnt) {
    vp.emplace_back(std::make_pair(pair.second, pair.first));
  }

  std::sort(vp.begin(), vp.end(), [](auto l, auto r) {
    if (l.first == r.first) {
      return std::lexicographical_compare(l.second.begin(), l.second.end(), r.second.begin(), r.second.end());
    }
    return l.first > r.first;
  });

  for (const auto &pair : vp) {
    std::cout << pair.second << std::endl;
  }

  return 0;
}

void skipSpaces(std::stringstream &is)
{
  char c;
  while (is.get(c)) {
    if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
      continue;
    } else {
      is.putback(c);
      break;
    }
  }
}
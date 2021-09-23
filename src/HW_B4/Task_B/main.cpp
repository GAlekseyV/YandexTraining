#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main()
{
  std::map<std::string, long> name_to_votes;
  std::string line;
  std::getline(std::cin, line);

  std::string name;
  long votes = 0;

  while (!line.empty()) {
    std::stringstream ss;
    ss << line;

    ss >> name >> votes;
    name_to_votes[name] += votes;

    std::getline(std::cin, line);
  }

  for (const auto pair : name_to_votes) {
    std::cout << pair.first << " " << pair.second << std::endl;
  }

  return 0;
}

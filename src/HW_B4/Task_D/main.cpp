#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

std::pair<std::string, int> parse_line(const std::string &line);
void skipSpaces(std::stringstream &is);

const long TOTAL_PLACES = 450;

int main(int argc, const char **argv)
{
  std::string line(" ");
  std::getline(std::cin, line);

  std::pair<std::string, long> name_to_votes;
  std::vector<std::pair<std::string, long>> parties_to_votes;
  std::vector<std::pair<std::string, long>> party_to_places;
  std::vector<std::pair<double, std::string>> rem_to_party;
  std::map<std::string, long> p_to_v;

  long total_votes = 0;

  while (!line.empty()) {
    name_to_votes = parse_line(line);
    total_votes += name_to_votes.second;
    parties_to_votes.push_back(name_to_votes);
    p_to_v.insert(name_to_votes);
    std::getline(std::cin, line);
  }

  int temp_num_places = 0;
  for (const auto &[party, votes] : parties_to_votes) {
    temp_num_places += static_cast<int>((votes / static_cast<double>(total_votes)) * TOTAL_PLACES);
    party_to_places.emplace_back(party, (votes / static_cast<double>(total_votes)) * TOTAL_PLACES);
    double fractional_part = votes / static_cast<double>(total_votes) * TOTAL_PLACES
                             - floor(votes / static_cast<double>(total_votes) * TOTAL_PLACES);
    rem_to_party.emplace_back(fractional_part, party);
  }

  int unallocated_seats = TOTAL_PLACES - temp_num_places;
  if (unallocated_seats > 0) {
    std::sort(rem_to_party.begin(), rem_to_party.end(), [&p_to_v](const auto &l, const auto &r) {
      bool ans = false;
      if (l.first == r.first) {
        ans = p_to_v[l.second] > p_to_v[r.second];
      } else {
        ans = l.first > r.first;
      }
      return ans;
    });
    for (size_t i = 0; unallocated_seats != 0; i++, unallocated_seats--) {
      auto it = std::find_if(party_to_places.begin(), party_to_places.end(), [&rem_to_party, i](const auto &item) {
        return item.first == rem_to_party[i].second;
      });
      (*it).second += 1;
    }
  }

  for (const auto &[name, places] : party_to_places) {
    std::cout << name << " " << places << "\n";
  }

  return 0;
}

std::pair<std::string, int> parse_line(const std::string &line)
{
  std::string word;
  std::string name;
  int num = -1;
  std::stringstream ss;
  ss << line;
  do {
    skipSpaces(ss);
    char c;
    ss.get(c);
    ss.putback(c);
    if (isalpha(c)) {
      ss >> word;
      if (!name.empty()) { name.append(" "); }
      name.append(word);
    } else if (isdigit(c)) {
      if (num != -1) {
        name.append(" ");
        name.append(std::to_string(num));
      }
      ss >> num;
      skipSpaces(ss);
    }
  } while (ss);
  return std::make_pair(name, num);
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
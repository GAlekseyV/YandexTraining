#include <algorithm>
#include <catch2/catch.hpp>
#include <map>
#include <sstream>
#include <string>
#include <vector>

std::pair<std::string, int> parse_line(const std::string &line);
void skipSpaces(std::stringstream &is);
const long TOTAL_PLACES = 450;

std::string elections_result(const std::string &in_str)
{
  std::stringstream ss(in_str);

  std::string line(" ");
  std::getline(ss, line);

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
    std::getline(ss, line);
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

  std::stringstream out_sstrm;
  for (const auto &[name, places] : party_to_places) {
    out_sstrm << name << " " << places << "\n";
  }
  return out_sstrm.str();
}

TEST_CASE("A. Elections. Parse line", "[parse line]")
{
  REQUIRE(parse_line("Partytwo 100").first == "Partytwo");
  REQUIRE(parse_line("Partytwo 100").second == 100);
  REQUIRE(parse_line("Party One 100000\n").first == "Party One");
  REQUIRE(parse_line("Party One 100000\n").second == 100000);
  REQUIRE(parse_line("Party number one 449\n").first == "Party number one");
  REQUIRE(parse_line("Party number one 449\n").second == 449);
  REQUIRE(parse_line("Party 1 34523\n").first == "Party 1");
  REQUIRE(parse_line("Party 1 34523\n").second == 34523);
}

TEST_CASE("A. Elections", "[election_result]")
{
  std::string in_str = "Party One 100000\n Party Two 200000\n Party Three 400000\n";
  REQUIRE(elections_result(in_str) == "Party One 64\nParty Two 129\nParty Three 257\n");

  in_str = "Party number one 100\n Partytwo 100\n";
  REQUIRE(elections_result(in_str) == "Party number one 225\nPartytwo 225\n");

  in_str = "Party number one 449\nPartytwo 1\n";
  REQUIRE(elections_result(in_str) == "Party number one 449\nPartytwo 1\n");

  in_str = "Party number one 1\nPartytwo 500\n";
  REQUIRE(elections_result(in_str) == "Party number one 1\nPartytwo 449\n");

  in_str =
    "Party 1 34523\nParty 2 65434\nParty 3 453\nParty 4 65784\nParty 5 5253\n \
     Party 6 3568\nParty 7 0\nParty 8 1\nParty 9 4592\nParty 10 90389\n";
  REQUIRE(elections_result(in_str) == "Party 1 57\nParty 2 109\nParty 3 1\nParty 4 109\nParty 5 9\nParty 6 6\nParty 7 0\nParty 8 0\nParty 9 8\nParty 10 151\n");

  in_str = "Dream team 84838432\n";
  REQUIRE(elections_result(in_str) == "Dream team 450\n");
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
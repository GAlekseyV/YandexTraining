#include <iostream>
#include <vector>

unsigned int calc_equal_to_the_max(const std::vector<unsigned int> &);

int main(int argc, const char **argv)
{
  const size_t MAX_SEQ_LENGHT = 10001;

  std::vector<unsigned int> seq;

  int cur_number = 0;
  std::cin >> cur_number;

  while (cur_number != 0) {
    seq.push_back(cur_number);
    std::cin >> cur_number;
  }

  std::cout << calc_equal_to_the_max(seq) << std::endl;

  return 0;
}

unsigned int calc_equal_to_the_max(const std::vector<unsigned int> &seq)
{
  unsigned int counter = 0;

  if (!seq.empty()) {
    unsigned int curr_max = seq[0];
    for (const auto num : seq) {
      if (num > curr_max) {
        curr_max = num;
        counter = 0;
      }
      if (curr_max == num) {
        counter++;
      }
    }
  }

  return counter;
}
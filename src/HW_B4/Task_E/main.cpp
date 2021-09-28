#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void skipSpaces(std::istream &is);

int main(__attribute__((unused)) int argc, __attribute__((unused)) const char **argv)
{
  int N = 0;
  const size_t MaxN = 1000;
  std::cin >> N;
  skipSpaces(std::cin);

  int num = -1;
  int msg_cnt = 0;
  std::string line;
  std::vector<std::string> themes;
  std::vector<size_t> msg_idx_to_thm(MaxN);
  std::vector<int> thm_to_cnt_msg;

  for (size_t i = 0; i < N; i++) {
    std::cin >> num;
    skipSpaces(std::cin);
    if (num == 0) {
      // Новая тема
      std::getline(std::cin, line);
      themes.push_back(line);// Сохраняем название темы
      thm_to_cnt_msg.push_back(1);// В теме первое сообщение

      std::getline(std::cin, line);// Считываем сообщение
      msg_cnt += 1;// Увеличиваем счетчик сообщений
      msg_idx_to_thm[msg_cnt - 1] = themes.size() - 1;
    } else {
      // Ответ на сообщение
      thm_to_cnt_msg[msg_idx_to_thm[num - 1]] += 1;// Получаем номер темы и увеличиваем для неё счетчик сообщений
      std::getline(std::cin, line);// Считываем сообщение
      msg_cnt += 1;// Увеличиваем счетчик сообщений
      msg_idx_to_thm[msg_cnt - 1] = msg_idx_to_thm[num - 1];
    }
  }

  auto it = std::max_element(thm_to_cnt_msg.begin(), thm_to_cnt_msg.end());
  std::cout << themes[it - thm_to_cnt_msg.begin()] << std::endl;

  return 0;
}

void skipSpaces(std::istream &is)
{
  char c = 0;
  while (is.get(c)) {
    bool is_space = (c == ' ' || c == '\t' || c == '\r' || c == '\n');
    if (!is_space) {
      is.putback(c);
      break;
    }
  }
}
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int main()
{
  std::string line;
  std::string ans = "YES";
  std::getline(std::cin, line);
  std::stringstream ss(line);
  std::stack<char> st;
  char c = ' ';
  while (ss.get(c)) {
    if (c == '(') {
      st.push(c);
    } else if (c == ')') {
      if (!st.empty()) {
        st.pop();
      } else {
        ans = "NO";
        break;
      }
    }
  }

  if (!st.empty()) {
    ans = "NO";
  }

  std::cout << ans << std::endl;

  return 0;
}

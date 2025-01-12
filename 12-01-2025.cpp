#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool canBeValid(string s, string locked) {
    if (s.length() % 2 != 0)
      return false;

    if (!isValid(s, locked, true))
      return false;

    reverse(s.begin(), s.end());
    reverse(locked.begin(), locked.end());
    return isValid(s, locked, false);
  }

  bool isValid(string s, string locked, bool leftToRight) {
    int openCount = 0, changeable = 0;

    for (int i = 0; i < s.length(); ++i) {
      if (locked[i] == '0') {
        ++changeable;
      } else if ((leftToRight && s[i] == '(') || (!leftToRight && s[i] == ')')) {
        ++openCount;
      } else {
        --openCount;
      }

      if (openCount + changeable < 0)
        return false;
    }

    return true;
  }
};

int main() {
  Solution solution;

  string s1 = "()))";
  string locked1 = "0100";
  cout << solution.canBeValid(s1, locked1) << endl; // Output: 1 (true)

  string s2 = "()";
  string locked2 = "11";
  cout << solution.canBeValid(s2, locked2) << endl; // Output: 1 (true)

  string s3 = "())";
  string locked3 = "110";
  cout << solution.canBeValid(s3, locked3) << endl; // Output: 0 (false)

  return 0;
}

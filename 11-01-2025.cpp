#include <iostream>
#include <string>
#include <bitset>
using namespace std;

class Solution {
 public:
  bool canConstruct(string s, int k) {
    if (s.length() < k)
      return false;

    bitset<26> odd;
    for (const char c : s)
      odd.flip(c - 'a');

    return odd.count() <= k;
  }
};

int main() {
  Solution sol;
  cout << (sol.canConstruct("annabelle", 2) ? "true" : "false") << endl;
  cout << (sol.canConstruct("leetcode", 3) ? "true" : "false") << endl;
  cout << (sol.canConstruct("true", 4) ? "true" : "false") << endl;
  cout << (sol.canConstruct("aabbcc", 3) ? "true" : "false") << endl;
  cout << (sol.canConstruct("xyz", 5) ? "true" : "false") << endl;
  return 0;
}
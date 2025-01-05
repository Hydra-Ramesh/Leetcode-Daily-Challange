#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int countPalindromicSubsequence(string s) {
    vector<int> first(26, -1), last(26, -1);
    int n = s.length();
    
    // Record the first and last occurrence of each character
    for (int i = 0; i < n; ++i) {
        if (first[s[i] - 'a'] == -1) {
            first[s[i] - 'a'] = i;
        }
        last[s[i] - 'a'] = i;
    }
    
    int count = 0;
    
    // For each character, count unique characters between its first and last occurrence
    for (int i = 0; i < 26; ++i) {
        if (first[i] != -1 && last[i] > first[i]) {
            unordered_set<char> unique_chars;
            for (int j = first[i] + 1; j < last[i]; ++j) {
                unique_chars.insert(s[j]);
            }
            count += unique_chars.size();
        }
    }
    
    return count;
}

int main() {
    string s = "aabca";
    cout << countPalindromicSubsequence(s) << endl; // Output: 3
    return 0;
}

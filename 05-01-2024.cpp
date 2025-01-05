#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shiftingLetters(string str, vector<vector<int>>& shifts) {
        int length = str.size();
        vector<int> delta(length + 1, 0);

        for (const auto& shift : shifts) {
            int direction = (shift[2] == 0) ? -1 : 1;
            delta[shift[0]] += direction;
            delta[shift[1] + 1] -= direction;
        }

        for (int i = 1; i <= length; ++i) {
            delta[i] += delta[i - 1];
        }

        string result(length, 'a');
        for (int i = 0; i < length; ++i) {
            int newCharIndex = (str[i] - 'a' + delta[i] % 26 + 26) % 26;
            result[i] = 'a' + newCharIndex;
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string str = "abc";
    vector<vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}};

    cout << "Original string: " << str << endl;
    cout << "After shifts: " << solution.shiftingLetters(str, shifts) << endl;

    // Test case 2
    str = "abcdef";
    shifts = {{0, 2, 1}, {2, 5, 0}, {1, 4, 1}};

    cout << "Original string: " << str << endl;
    cout << "After shifts: " << solution.shiftingLetters(str, shifts) << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int s = 0;
        for (int x : derived) {
            s ^= x;
        }
        return s == 0;
    }
};

int main() {
    Solution sol;
    vector<int> derived = {1, 2, 3, 2, 1}; // Example input
    
    if (sol.doesValidArrayExist(derived)) {
        cout << "Valid array exists" << endl;
    } else {
        cout << "Valid array does not exist" << endl;
    }
    
    return 0;
}

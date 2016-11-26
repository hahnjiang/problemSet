#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a1 = 1, a2 = 2, s;
        for (int i = 3; i <= n; i++) {
            s = a1 + a2;
            a1 = a2;
            a2 = s;
        }
        return s;
    }
};
int main() {
    Solution s;
    cout << s.climbStairs(10) << endl;
    cout << s.climbStairs(5) << endl;
}

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0x80000000) {
            return 0;
        }
        int r = 0, p = 1;
        if (x < 0) {
            x = -x;
            p = -1;
        }
        while (x != 0) {
            if (r > (0x7fffffff - x % 10) / 10) {
                return 0;
            }
            r = r * 10 + (x % 10);
            x = x / 10;
        }
        return p * r;
    }
};
int main() {
    Solution s;
    cout << s.reverse(123) << endl;
    cout << s.reverse(-123) << endl;
    cout << s.reverse(-2147483412) << endl;
    return 0;
}

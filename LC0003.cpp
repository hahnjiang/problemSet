#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int st = 0, en = 1, res = 1;
        int c[256];
        memset(c, 0, sizeof(c));
        c[s[0]] = 1;
        while (st <= en && en < s.size()) {
            if (c[s[en]] == 1) {
                c[s[st]]--;
                st++;
            } else {
                c[s[en]]++;
                en++;
            }
            if (en - st > res) {
                res = en - st;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcdefg") << endl;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}

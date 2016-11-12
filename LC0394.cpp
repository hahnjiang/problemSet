#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string solve(string s, int &st) {
            int tmp = 0;
            string res;
            while (st < s.size()) {
                if ('[' == s[st]) {
                    st++;
                    string sub = solve(s, st);
                    for (int i=0; i<tmp; i++) {
                        res += sub;
                    }
                    tmp = 0;
                } else if (']' == s[st]) {
                    st++;
                    return res;
                } else if (isDigit(s[st])) {
                    tmp = tmp*10 + s[st] - '0';
                    st++;
                } else {
                    res += s[st];
                    st++;
                }
            }
            return res;
        }
        string decodeString(string s) {
            int idx = 0;
            return solve(s, idx);
        }
        bool isDigit(char ch) {
            return '0' <= ch && ch <= '9';
        }
};

int main() {
    Solution s;
    cout <<  s.decodeString("3[a]2[bc]") << endl;
    cout <<  s.decodeString("3[a2[c]]") << endl;
    cout <<  s.decodeString("2[abc]3[cd]ef") << endl;
    cout <<  s.decodeString("abcde") << endl;
    return 0;
}

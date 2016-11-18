#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int next[10005];
        int l = str.size();
        next[0] = 0;
        for (int i = 1; i < l; i++) {
            int k = next[i - 1];
            while (str[i] != str[k] && k > 0) {
                k = next[k - 1];
            }
            if (str[i] == str[k]) {
                next[i] = k + 1;
            }
        }
        for (int i = 0; i < l; i++) {
            cout << next[i] << " ";
        }
        cout << endl;
        cout << l << endl;
        return (next[l - 1] > 0) && ((l % (l - next[l - 1])) == 0);
    }
};
int main() {
    Solution s;
    cout << s.repeatedSubstringPattern("ababac") << endl;
    cout << s.repeatedSubstringPattern("abac") << endl;
    cout << s.repeatedSubstringPattern("abab") << endl;
    cout << s.repeatedSubstringPattern("aba") << endl;
    cout << s.repeatedSubstringPattern("abcabcabcabc") << endl;
}

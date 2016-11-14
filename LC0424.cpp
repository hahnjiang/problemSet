#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    public:
        int characterReplacement(string s, int k) {
             vector<int> wc(26, 0);
             int best=0;
             for (int i=0, st=0; i<s.size(); i++) {
                 wc[s[i]-'A']++;
                 int sum=0;
                 for (int j=0; j<wc.size(); j++) {
                     sum+=wc[j];
                 }
                 int tmp = *max_element(wc.begin(), wc.end());
                 if (sum-tmp<=k) {
                     best = (i-st+1>best)?(i-st+1):best;
                 } else {
                     wc[s[st]-'A']--;
                     st++;
                 }
             }
             return best;
        }
};

int main() {
    Solution s;
    cout << s.characterReplacement("ABAB", 2) << endl;
    cout << s.characterReplacement("AABABBA", 1) << endl;
    return 0;
}

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool canCross(vector<int>& stones) {
            map<int, set<int> > m;
            vector<int> dp(stones.size(), 0);
            m[0].insert(0);
            int k = 0;
            for (int i = 1; i < stones.size(); ++i) {
                while (dp[k] + 1 < stones[i] - stones[k]) ++k;
                for (int j = k; j < i; ++j) {
                    int t = stones[i] - stones[j];
                    if (m[j].count(t - 1) || m[j].count(t) || m[j].count(t + 1)) {
                        m[i].insert(t);
                        dp[i] = max(dp[i], t);
                    }
                }
            }
            return dp.back() > 0;
        }
};

int main() {
    vector<int> stones;
    stones.push_back(0);
    stones.push_back(1);
    stones.push_back(3);
    stones.push_back(6);
    stones.push_back(10);
    stones.push_back(13);
    stones.push_back(15);
    stones.push_back(18);
    Solution s;
    cout << s.canCross(stones) << endl;
}

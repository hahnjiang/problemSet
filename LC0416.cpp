#include "stdio.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool canPartition(vector<int> &nums) {
            int sum=0;
            for (int i=0; i<nums.size(); i++) {
                sum += nums[i];
            }
            if ((sum%2) == 0) {
                int goal = sum/2;
                int dp[10005];
                memset(dp, 0, sizeof(dp));
                for (int i=0; i<nums.size(); i++) {
                    for (int j=goal; j>=nums[i]; j--) {
                        if (i>0 && dp[j-nums[i]]+1 > dp[j]) {
                            dp[j] = dp[j-nums[i]]+1;
                        }
                    }
                }
                return dp[goal]>0;
            } else {
                return false;
            }
        }
};
int main() {
    Solution s;
    vector<int> vd1;
    vd1.push_back(1);
    vd1.push_back(5);
    vd1.push_back(11);
    vd1.push_back(5);
    cout << s.canPartition(vd1) << endl;
}

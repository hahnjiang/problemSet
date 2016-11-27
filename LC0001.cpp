#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};
int main() {
    vector<int> input = {2, 7, 11, 15};
    Solution s;
    vector<int> res = s.twoSum(input, 9);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}

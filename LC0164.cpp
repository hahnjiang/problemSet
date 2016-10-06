#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void countSort(vector<int>& nums, int exp) {
            int l = nums.size();
            vector<int> sorted(l);
            int count[10] = {0};
            for (int i=0; i<l; i++) {
                count[(nums[i]/exp)%10]++;
            }
            for (int i=1; i<10; i++) {
                count[i]+=count[i-1];
            }
            for (int i=l-1; i>=0; i--) {
                int sign = (nums[i]/exp)%10;
                sorted[count[sign]-1] = nums[i];
                count[sign]--;
            }
            nums = sorted;
        }
        void radixSort(vector<int>& nums) {
            int maxNum = 0;
            for (int i=0; i<nums.size(); i++) {
                if (nums[i] > maxNum) {
                    maxNum = nums[i];
                }
            }
            for (int exp=1; maxNum/exp > 0; exp *= 10) {
                countSort(nums, exp);
            }
        }
        int maximumGap(vector<int>& nums) {
            radixSort(nums);
            int result = 0;
            for (int i=1; i<nums.size(); i++) {
                if (nums[i]-nums[i-1] > result) {
                    result = nums[i]-nums[i-1];
                }
            }
            return result;
        }
};

int main() {
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(16);
    nums.push_back(8);
    Solution s;
    s.maximumGap(nums);
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << "\t";
    }
    cout << endl;
}

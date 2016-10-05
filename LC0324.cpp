#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    public:
        void wiggleSort(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<int> temp(nums.size());
            int l = nums.size();
            for (int i=0; i<l/2; i++) {
                temp[i*2+1] = nums[l-i-1];
            }
            int tmp = l-(l)/2;
            for (int i=0; i<tmp; i++) {
                temp[i*2] = nums[tmp-i-1];
            }
            nums = temp;
        }
};

int main() {
    Solution s;
    vector<int> list;
    /** TEST 1
      list.push_back(4);
      list.push_back(5);
      list.push_back(6);
      list.push_back(1);
      list.push_back(1);
      list.push_back(1);
     **/
    list.push_back(1);
    list.push_back(2);
    list.push_back(1);
    list.push_back(2);
    list.push_back(1);
    list.push_back(2);
    list.push_back(1);
    s.wiggleSort(list);
    for (int i=0; i<list.size(); i++) {
        cout << list[i] << "\t";
    }
    cout << endl;
}

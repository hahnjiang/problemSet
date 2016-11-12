#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
    public:
        bool isValidSerialization(string preorder) {
            vector<string> input;
            string tmp = "";
            for (int i=0; i<preorder.size(); i++) {
                if (preorder[i] == ',') {
                    input.push_back(tmp);
                    tmp = "";
                } else {
                    tmp += preorder[i];
                }
            }
            if (tmp.size() > 0) {
                input.push_back(tmp);
            }
            vector<string> tree;
            for (int i=0; i<input.size(); i++) {
                if (input[i] == "#") {
                    while (tree.size()>=2 && tree[tree.size()-1]=="#" && tree[tree.size()-2]!="#") {
                        tree.pop_back();
                        tree.pop_back();
                    }
                    tree.push_back(input[i]);
                } else {
                    tree.push_back(input[i]);
                }
            }
            return tree.size()==1 && tree[0]=="#";
        }
        bool isDigit(char ch) {
            return '0' <= ch && ch <= '9';
        }
};

int main() {
    Solution s;
    cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << s.isValidSerialization("1,#") << endl;
    cout << s.isValidSerialization("9,#,#,1") << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> solve(TreeNode *root, string path) {
        vector<string> result;
        if (root == NULL) {
            return result;
        }
        if (root->left == NULL && root->right == NULL) {
            result.push_back(path + to_string(root->val));
        }
        if (root->left != NULL) {
            vector<string> tmp =
                solve(root->left, path + to_string(root->val) + "->");
            for (int i = 0; i < tmp.size(); i++) {
                result.push_back(tmp[i]);
            }
        }
        if (root->right != NULL) {
            vector<string> tmp =
                solve(root->right, path + to_string(root->val) + "->");
            for (int i = 0; i < tmp.size(); i++) {
                result.push_back(tmp[i]);
            }
        }
        return result;
    }
    vector<string> binaryTreePaths(TreeNode *root) { return solve(root, ""); }
};

int main() { return 0; }

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (root==NULL) {
                return 0;
            }
            int left=0, right=0;
            if (root->left!=NULL) {
                left=maxDepth(root->left);
            }
            if (root->right!=NULL) {
                right=maxDepth(root->right);
            }
            return ((left>right)?(left):(right))+1;
        }
};
int main() {
}

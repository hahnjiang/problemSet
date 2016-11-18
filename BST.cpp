#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree {
public:
    Tree() { root = NULL; }
    Tree(vector<int> data) {
        root = NULL;
        for (int i = 0; i < data.size(); ++i) {
            insert(data[i]);
        }
    }
    void insert(int val) { root = insert(val, root); }
    bool find(int val) { return find(val, root); }
    void preorder() {
        if (root == NULL) {
            cout << "NULL" << endl;
            return;
        }
        preorder(root);
    }
    ~Tree() {}

private:
    TreeNode *root;
    void preorder(TreeNode *point) {
        if (point == NULL) {
            return;
        }
        cout << point->val << endl;
        preorder(point->left);
        preorder(point->right);
    }
    bool find(int val, TreeNode *point) {
        if (point == NULL) {
            return false;
        }
        if (val > point->val) {
            return find(val, point->right);
        } else if (val < point->val) {
            return find(val, point->left);
        }
        return true;
    }
    TreeNode *insert(int val, TreeNode *point) {
        if (point == NULL) {
            point = new TreeNode(val);
            return point;
        }
        if (val < point->val) {
            point->left = insert(val, point->left);
        } else if (val > point->val) {
            point->right = insert(val, point->right);
        }
        return point;
    }
};

int main() {
    vector<int> data = {5, 4, 6, 7, 8};
    Tree tree(data);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.preorder();
    cout << tree.find(7) << endl;
    cout << tree.find(9) << endl;
    return 0;
}

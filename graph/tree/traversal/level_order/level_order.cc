#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int v) : val(v) {}
};

void level_order(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    queue<TreeNode*> q;

    cout << root->val << endl;
    q.push(root);

    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();

        if (cur->left != nullptr) {
            cout << cur->left->val << endl;
            q.push(cur->left);
        }

        if (cur->right != nullptr) {
            cout << cur->right->val << endl;
            q.push(cur->right);
        }
    }
}

int main() {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n1->left = n2;
    n1->right = n3;
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    n2->left = n4;
    n2->right = n5;

    level_order(n1);
}
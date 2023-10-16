#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int v) : val(v) {}
};

void preorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
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

    preorder(n1);
}
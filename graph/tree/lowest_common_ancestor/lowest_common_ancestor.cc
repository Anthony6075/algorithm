#include <iostream>
#include <climits>
using namespace std;

struct Node {
	int data;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int d) :data(d) {}
};

bool isNodePresent(Node* root, Node* node) {
	if (root == nullptr) {
		return false;
	}

	if (root == node) {
		return true;
	}

	return isNodePresent(root->left, node) ||
		isNodePresent(root->right, node);
}

int findLevel(Node* root, Node* node, int level) {
	if (root == nullptr) {
		return INT_MIN;
	}

	if (root == node) {
		return level;
	}

	int left = findLevel(root->left, node, level + 1);

	if (left != INT_MIN) {
		return left;
	}

	return findLevel(root->right, node, level + 1);
}

Node* findLCA(Node* root, Node* x, Node* y) {
	if (root == nullptr) {
		return nullptr;
	}

	if (root == x || root == y) {
		return root;
	}

	Node* left = findLCA(root->left, x, y);
	Node* right = findLCA(root->right, x, y);
	if (left && right) {
		return root;
	}

	if (left) {
		return left;
	}

	if (right) {
		return right;
	}

	return nullptr;
}

int findDistance(Node* root, Node* x, Node* y) {
	Node* lca = nullptr;

	if (isNodePresent(root, x) && isNodePresent(root, y)) {
		lca = findLCA(root, x, y);
	} else {
		return INT_MIN;
	}

	return findLevel(lca, x, 0) + findLevel(lca, y, 0);
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->right->right = new Node(8);

	cout <<findDistance(root, root->right->left->left, root->right->right) << endl;

	return 0;
}

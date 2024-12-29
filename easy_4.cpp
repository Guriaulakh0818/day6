#include <iostream>
#include <limits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findMinValue(TreeNode* root) {
    if (root == NULL) {
        return numeric_limits<int>::max();
    }
    int minValue = root->val;
    int leftMin = findMinValue(root->left);
    int rightMin = findMinValue(root->right);
    return min(minValue, min(leftMin, rightMin));
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    cout << "Minimum value in the binary tree: " << findMinValue(root) << endl;
    return 0;
}

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
    int diameter(TreeNode* root) {
        int maxDiameter = 0;
        height(root, maxDiameter);
        return maxDiameter;
    }

private:
    int height(TreeNode* node, int& maxDiameter) {
        if (!node) return 0;
        int leftHeight = height(node->left, maxDiameter);
        int rightHeight = height(node->right, maxDiameter);
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution solution;
    cout << "Diameter of the binary tree: " << solution.diameter(root) << endl;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

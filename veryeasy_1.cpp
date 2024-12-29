#include <iostream>
#include <algorithm> 
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << "Maximum Depth of the Binary Tree: " << maxDepth(root) << endl;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}

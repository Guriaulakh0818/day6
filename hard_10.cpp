#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inorderMap);
    }
private:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRootIndex = inorderMap[root->val];
        int leftTreeSize = inRootIndex - inStart;
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTreeSize, inStart, inRootIndex - 1, inorderMap);
        root->right = buildTreeHelper(preorder, preStart + leftTreeSize + 1, preEnd, inRootIndex + 1, inEnd, inorderMap);
        return root;
    }
};
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);
    printInorder(root);
    cout << endl;
    return 0;
}

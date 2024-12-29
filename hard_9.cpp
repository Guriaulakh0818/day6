#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserializeHelper(ss);
    }
private:
    TreeNode* deserializeHelper(istringstream& ss) {
        string val;
        getline(ss, val, ',');
        if (val == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);
        return node;
    }
};
int main() {
    Codec codec;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;
    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized root value: " << deserialized->val << endl;
    return 0;
}

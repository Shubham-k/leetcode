/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;

    void isValidBSTHelper(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        isValidBSTHelper(root->left);
        v.push_back(root->val);
        isValidBSTHelper(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        isValidBSTHelper(root);
        return v[k - 1];
    }
};
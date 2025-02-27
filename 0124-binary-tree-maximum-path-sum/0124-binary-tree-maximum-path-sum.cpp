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
    int maxSum = INT_MIN;

    int maxPathSumHelper(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftSum = max(0, maxPathSumHelper(root->left));
        int rightSum = max(0, maxPathSumHelper(root->right));
        maxSum = max(maxSum, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        maxPathSumHelper(root);
        return maxSum;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int max_sum;
public:
    int gain_from_subtree(TreeNode* root) {
        if(!root) return 0;
        int gain_from_left = max(gain_from_subtree(root->left), 0);
        int gain_from_right = max(gain_from_subtree(root->right), 0);
        max_sum = max(root->val + gain_from_left + gain_from_right, max_sum);
        return root->val + max(gain_from_left, gain_from_right);
    }
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
        gain_from_subtree(root);
        return max_sum;
    }
};
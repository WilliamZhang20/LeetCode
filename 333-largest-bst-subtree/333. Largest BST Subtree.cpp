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
    TreeNode* prev = NULL;
public:
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool inOrderSorted(TreeNode* root) {
        if(!root) {
            return true;
        }
        if(!inOrderSorted(root->left)) {
            return false;
        }
        if(prev && prev->val >= root->val) {
            return false;
        }
        prev = root;
        return inOrderSorted(root->right);
    }
    int largestBSTSubtree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        prev = NULL;
        if(inOrderSorted(root)) {
            return countNodes(root);
        }
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};
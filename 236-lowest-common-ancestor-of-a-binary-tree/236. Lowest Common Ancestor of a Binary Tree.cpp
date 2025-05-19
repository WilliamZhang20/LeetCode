/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* leftRes = nullptr;
        TreeNode* rightRes = nullptr;
        if(root->val == p->val || root->val == q->val) {
            return root;
        }
        if(root->left != nullptr) {
            leftRes = lowestCommonAncestor(root->left, p, q);
        }
        if(root->right != nullptr) {
            rightRes = lowestCommonAncestor(root->right, p, q);
        }
        if(leftRes && !rightRes) {
            return leftRes;
        } else if(!leftRes && rightRes) {
            return rightRes;
        } else if(leftRes && rightRes) {
            return root;
        }
        return nullptr;
    }
};
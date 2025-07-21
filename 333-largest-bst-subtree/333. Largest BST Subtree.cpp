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
    int findMax(TreeNode* root) {
        if(!root) {
            return INT_MIN;
        }
        return max({root->val, findMax(root->left), findMax(root->right)});
    }
    int findMin(TreeNode* root) {
        if(!root) {
            return INT_MAX;
        }
        return min({root->val, findMin(root->left), findMin(root->right)});
    }
    bool isValidBST(TreeNode* root) {
        if(!root) {
            return true;
        }
        int leftMax = findMax(root->left);
        int rightMin = findMin(root->right);
        if(leftMax >= root->val || rightMin <= root->val) {
            return false;
        }
        if(isValidBST(root->left) && isValidBST(root->right)) {
            return true;
        }
        return false;
    }
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        if(isValidBST(root)) {
            std::cout << root->val << " valid\n";
            return countNodes(root);
        }
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};
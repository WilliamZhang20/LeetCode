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
    int pIndex;
    unordered_map<int, int> inOrderMap;
public:
    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        if(left > right) return nullptr;

        int rootValue = preorder[pIndex++];
        TreeNode* root = new TreeNode(rootValue);

        root->left = arrayToTree(preorder, left, inOrderMap[rootValue] - 1);
        root->right = arrayToTree(preorder, inOrderMap[rootValue]+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pIndex = 0;
        for(int i=0; i<inorder.size(); i++) {
            inOrderMap[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, preorder.size()-1);
    }
};
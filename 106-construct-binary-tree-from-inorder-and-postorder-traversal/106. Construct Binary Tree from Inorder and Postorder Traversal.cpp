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
    TreeNode* arrayToTree(vector<int>& postorder, int left, int right) {
        if(left > right) return nullptr;

        int rootValue = postorder[pIndex--];
        TreeNode* root = new TreeNode(rootValue);

        root->right = arrayToTree(postorder, inOrderMap[rootValue]+1, right);
        root->left = arrayToTree(postorder, left, inOrderMap[rootValue] - 1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        pIndex = postorder.size()-1;
        for(int i=0; i<inorder.size(); i++) {
            inOrderMap[inorder[i]] = i;
        }
        return arrayToTree(postorder, 0, postorder.size()-1);
    }
};
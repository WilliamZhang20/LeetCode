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
class BSTIterator {
public:
    int idx = 0;
    vector<TreeNode*>ans;
    void inorder(TreeNode* root , vector<TreeNode*>&arr){
        if(root==NULL)return ;
        inorder(root->left,arr);
        arr.push_back(root);
        inorder(root->right,arr);
    }
    BSTIterator(TreeNode* root) {
        vector<TreeNode*>arr;
        idx = 0;
        inorder(root,arr);
        ans = arr;
    }
    
    int next(){
        int x = ans[idx]->val;
        idx++;
        return x;
    }
    bool hasNext() {
     if(idx<ans.size())return true;
     return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
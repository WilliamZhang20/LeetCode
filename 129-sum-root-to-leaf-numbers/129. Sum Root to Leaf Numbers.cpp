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
private:
    string curr;
    int sum;
public:
    Solution() : curr(""), sum(0) {}
    void solve(TreeNode* node) {
        if(node->left != nullptr) {
            curr += to_string(node->left->val);
            solve(node->left);
        }
        if(node->right != nullptr) {
            curr += to_string(node->right->val);
            solve(node->right);
        }
        if(!node->left && !node->right) {
            cout << curr << "\n";
            sum += std::stoi(curr);
        }
        curr.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        curr += to_string(root->val);
        solve(root);
        return sum;
    }
};
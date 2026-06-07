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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> kids;
        for(auto& d : descriptions) {
            if(!mp[d[0]]) mp[d[0]] = new TreeNode(d[0]);
            if(!mp[d[1]]) mp[d[1]] = new TreeNode(d[1]);

            if(d[2]) mp[d[0]]->left = mp[d[1]];
            else mp[d[0]]->right = mp[d[1]];

            kids.emplace(d[1]);
        }
        // to find root, find values in mp that aren't in kids
        for(auto& [k, v] : mp) {
            if(!kids.count(k)) return v;
        }
        return nullptr;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> q;
        if(root) q.push(root);
        else return "";
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr) {
                result += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            } else {
                result += "null,";
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<string> tokens;
        stringstream ss(data);
        string token;
        while(getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty() && i < tokens.size()) {
            TreeNode* parent = q.front();
            q.pop();
            if(tokens[i] != "null") {
                TreeNode* leftChild = new TreeNode(stoi(tokens[i]));
                parent->left = leftChild;
                q.push(leftChild);
            }
            i++;
            if(i < tokens.size() && tokens[i] != "null") {
                TreeNode* rightChild = new TreeNode(stoi(tokens[i]));
                parent->right = rightChild;
                q.push(rightChild);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
class Solution {
    struct TrieNode {
        // contains both char c and its object
        unordered_map<char, TrieNode*> children;
        bool isEnd;
    };

    // we need root
    TrieNode* root = new TrieNode();

    // insert
    void insert(const string& word) {
        TrieNode* curr = root;

        // add to children
        for (char c : word) {
            if (!curr->children.contains(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }

        // once we hit string end that's the end of word
        curr->isEnd = true;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        // insert all
        for (string s : strs) {
            insert(s);
        }

        string prefix;
        TrieNode* curr = root;
   
        // we can ONLY continue when there's only one path to go
        // and if that path ends it's done
        while (curr->children.size() == 1 && !curr->isEnd) {
            auto [c, next] = *curr->children.begin();

            prefix += c;
            curr = next;
        }

        return prefix;
    }
};
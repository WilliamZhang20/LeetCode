class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode() {
        isEnd = false;
        for(int i=0; i<26; i++) {
            children[i] = nullptr;
        }
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;
        for(auto& c: word) {
            int index = c - 'a';
            if(!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
};
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(auto word: wordDict) {
            trie.insert(word);
        }
        unordered_map<int, vector<string>> dp;
        for(int i=s.size(); i>=0; i--) {
            vector<string> validSentences;
            TrieNode* curr = trie.root;
            for(int j=i; j<s.size(); j++) {
                char c = s[j];
                int idx = c - 'a';
                if(!curr->children[idx]) {
                    break;
                }
                curr = curr->children[idx];
                if(curr->isEnd) {
                    string currWord = s.substr(i, j - i + 1);
                    if(j == s.size()-1) {
                        validSentences.push_back(currWord);
                    } else {
                        for(string sentence : dp[j + 1]) {
                            validSentences.push_back(currWord + " " + sentence);
                        }
                    }
                }
            }
            dp[i] = validSentences;
        }
        return dp[0];
    }
};
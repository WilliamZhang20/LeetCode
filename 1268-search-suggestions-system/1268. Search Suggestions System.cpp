#include <vector>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    // Fix: Consistently use 'children' instead of mixing 'child' and 'children'
    unique_ptr<TrieNode> children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    unique_ptr<TrieNode> root;

    Trie() {
        root = make_unique<TrieNode>();
    }

    void insert(const string& word) {
        TrieNode* current = root.get();
        for (char ch : word) {
            int index = ch - 'a';
            if (!current->children[index]) {
                current->children[index] = make_unique<TrieNode>();
            }
            current = current->children[index].get();
        }
        current->isEndOfWord = true;
    }

    // Helper function to perform DFS and gather up to 3 lexicographically smallest words
    void getWordsWithPrefix(TrieNode* node, string& currentWord, vector<string>& result) {
        if (!node || result.size() == 3) {
            return;
        }
        
        if (node->isEndOfWord) {
            result.push_back(currentWord);
        }

        // Traverse in alphabetical order ('a' to 'z') to guarantee lexicographical sorting
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                currentWord.push_back('a' + i);
                getWordsWithPrefix(node->children[i].get(), currentWord, result);
                currentWord.pop_back(); // Backtrack
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie search;
        vector<vector<string>> ans;
        
        for (auto& product : products) {
            search.insert(product);
        }

        TrieNode* curr = search.root.get();
        string prefix = "";
        bool broken = false;

        for (char ch : searchWord) {
            vector<string> temp;
            
            // If the prefix path is already broken, we can't match any more characters
            if (broken || !curr->children[ch - 'a']) {
                broken = true;
                ans.push_back({});
                continue;
            }

            // Move to the child node corresponding to the typed character
            curr = curr->children[ch - 'a'].get();
            prefix.push_back(ch);
            
            // Collect up to 3 words starting from this node
            string tempWord = prefix;
            search.getWordsWithPrefix(curr, tempWord, temp);
            ans.push_back(temp);
        }

        return ans;
    }
};
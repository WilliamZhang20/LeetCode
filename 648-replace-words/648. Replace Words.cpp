class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd = false;
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;
        for(char& c: word) {
            int idx = (c - 'a');
            if(!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    string search(string word) {
        // returns the SHORTEST root of the word
        string res;
        TrieNode* node = root;
        for(char& c: word) {
            int idx = (c - 'a');
            if(!node->children[idx]) {
                return word;
            }
            node = node->children[idx];
            res += c;
            if(node->isEnd) break;
        }
        return res;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie roots;
        for(auto& word: dictionary) {
            roots.insert(word);
        }
        stringstream ss(sentence);
        string token;
        string ans;
        while (getline(ss, token, ' ')) {
            ans += roots.search(token) + " ";
        }
        ans.pop_back();
        return ans;
    }
};
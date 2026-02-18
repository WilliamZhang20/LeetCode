class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool word = false;
};

class WordDictionary {
    TrieNode* trie;
public:
    WordDictionary() {
        trie = new TrieNode();
    }
    
    void addWord(string word) { // unchanged with '*'
        TrieNode* node = trie;
        for(const char& c: word) {
            if(!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word = true;
    }

    bool searchTrie(string word, TrieNode* node) {
        for(int i=0; i<word.length(); ++i) {
            char ch = word[i];
            if(!node->children.count(ch)) {
                if(ch == '.') {
                    for(auto x : node->children) {
                        TrieNode* child = x.second;
                        if(searchTrie(word.substr(i+1), child)) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                node = node->children[ch];
            }
        }
        return node->word;
    }
    
    bool search(string word) {
        return searchTrie(word, trie);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
class TrieNode {
public:
    bool isWord;
    string word; // store at terminal
    TrieNode* children[26];
    TrieNode() {
        isWord = false;
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
        for(auto& c : word) {
            int index = c - 'a';
            if(!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isWord = true;
        node->word = word;
    }
};
class Solution {
    int m, n;
    vector<vector<bool>> visited;
    vector<string> ans;
    int dirs[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
public:
    void dfs(int i, int j, vector<vector<char>>& board, TrieNode* curr) {
        if (curr->isWord) {
            ans.push_back(curr->word);
            curr->isWord = false; // avoid duplicates
        }
        visited[i][j] = true;
        for(auto& d: dirs) {
            int x = i + d[0];
            int y = j + d[1];

            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (visited[x][y]) continue;

            char c = board[x][y];
            int idx = c - 'a';

            if (curr->children[idx]) {
                dfs(x, y, board, curr->children[idx]);
            }
        }
        visited[i][j] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        visited.assign(n, vector<bool>(m, false));
        Trie t;
        for(auto& word: words)
            t.insert(word);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int idx = board[i][j] - 'a';
                if(t.root->children[idx]) dfs(i, j, board, t.root->children[idx]);
            }
        }
        return ans;
    }
};
class Solution {
    int n;
    int m;
    array<array<int, 2>, 4> dirs = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
    vector<vector<bool>> vis;
public:
    bool dfs(int pos, int i, int j, const string& word, vector<vector<char>>& board) {
        if(pos == word.length()) return true;
        vis[i][j] = true;
        for(auto& dir : dirs) {
            int x = i+dir[0];
            int y = j + dir[1];
            if (x >= 0 && x < n && y >= 0 && y < m &&
                !vis[x][y] && board[x][y] == word[pos]) {

                if (dfs(pos + 1, x, y, word, board)) {
                    vis[i][j] = false;
                    return true;
                }
            }
        }

        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        vis.assign(n, vector<bool>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0] && dfs(1, i, j, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
};
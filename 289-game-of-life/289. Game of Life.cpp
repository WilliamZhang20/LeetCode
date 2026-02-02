class Solution {
    int dirs[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int lN = 0;
                for(auto& dir: dirs) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if(x >= 0 && x < n && y >= 0 && y < m) {
                        if(abs(board[x][y]) == 1) ++lN;
                    }
                }
                if(board[i][j] == 1 && (lN < 2 || lN > 3)) board[i][j] = -1;
                else if(board[i][j] == 0 && lN == 3) board[i][j] = 2;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                board[i][j] = board[i][j] > 0 ? 1 : 0;
            }
        }
    }
};
class Solution {
    vector<vector<string>> ans;
    bool isSafe(vector<string>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // left & right diag
        int maxLeft = min(row, col);
        for(int i=1;i<=maxLeft;i++){
            if(board[row-i][col-i]=='Q') return false;
        }
        int maxRight = min(row, int(board.size())-1-col);
        for (int i = 1; i <= maxRight; i++) {
            if (row-i >= 0 && col+i < board.size() && board[row-i][col+i] == 'Q') return false;
        }
        return true;
    }
    void generate(vector<string>& board, int row) {
        if(row == board.size()) {
            ans.push_back(board);
            return;
        }
        // add or no add to diff cols + backtrack
        for(int i=0; i<board[row].length(); i++) {
            if(isSafe(board, row, i)) {
                // add Q
                board[row][i] = 'Q';
                // recurse
                generate(board, row+1);
                board[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        generate(board, 0);
        return ans;
    }
};
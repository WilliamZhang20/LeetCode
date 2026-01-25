class TicTacToe {
    vector<int> rows;
    vector<int> cols;
    int diagonal = 0;
    int antiDiag = 0;
    int threshold;
public:
    TicTacToe(int n) : threshold(n) {
        rows.resize(n);
        cols.resize(n);
    }
    
    int move(int row, int col, int player) {
        int play = (player == 1) ? 1 : -1;
        rows[row] += play;
        cols[col] += play;
        if (row == col) diagonal += play;
        if (row + col == threshold - 1) antiDiag += play;
        if(abs(rows[row]) == threshold || abs(cols[col]) == threshold || abs(diagonal) == threshold || abs(antiDiag) == threshold) {
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
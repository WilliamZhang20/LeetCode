class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int communicableServercount = 0;

        vector<int> colCount(size(grid[0]), 0);
        vector<int> lastServerInRow(size(grid), -1);

        for (int row = 0; row < size(grid); ++row) {
            int serverCountInRow = 0;

            for (int col = 0; col < size(grid[0]); ++col) {
                if (grid[row][col]) {
                    serverCountInRow++;
                    colCount[col]++;
                    lastServerInRow[row] = col;
                }
            }

            if (serverCountInRow > 1) {
                communicableServercount += serverCountInRow;
                lastServerInRow[row] = -1;
            }
        }

        for (int row = 0; row < size(grid); ++row) {
            if (lastServerInRow[row] != -1 &&
                colCount[lastServerInRow[row]] > 1) {
                communicableServercount++;
            }
        }

        return communicableServercount;
    }
};
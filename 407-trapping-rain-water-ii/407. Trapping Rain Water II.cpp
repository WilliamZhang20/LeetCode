class Solution {
    array<int, 4> dRow = {0, 0, -1, 1};
    array<int, 4> dCol = {-1, 1, 0, 0};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int nRows = heightMap.size();
        int nCols = heightMap[0].size();
        vector<vector<bool>> visited(nRows, vector<bool>(nCols, false));
        priority_queue<Cell> b;
        int total = 0;
        for(int i=0; i<nRows; i++) {
            // push first and last column
            b.emplace(heightMap[i][0], i, 0);
            b.emplace(heightMap[i][nCols-1], i, nCols-1);
            visited[i][0] = visited[i][nCols-1] = true;
        }
        for(int i=0; i<nCols; i++) {
            b.emplace(heightMap[0][i], 0, i);
            b.emplace(heightMap[nRows-1][i], nRows-1, i);
            visited[0][i] = visited[nRows-1][i] = true;
        }
        
        while(!b.empty()) {
            Cell top = b.top();
            b.pop();
            for(int i=0; i<4; i++) {
                int nr = top.row + dRow[i];
                int nc = top.col + dCol[i];
                if(isValidCell(nr, nc, nRows, nCols) && !visited[nr][nc]) {
                    int nh = heightMap[nr][nc];

                    if(nh < top.height) {
                        total += top.height - nh;
                    }

                    b.emplace(max(nh, top.height), nr, nc);
                    visited[nr][nc] = true;
                }
            }
        }
        return total;
    }
private:
    bool isValidCell(int row, int col, int numOfRows, int numOfCols) {
        return row >= 0 && col >= 0 && row < numOfRows && col < numOfCols;
    }
    class Cell {
    public:
        int height;
        int row;
        int col;

        // Constructor to initialize a cell
        Cell(int height, int row, int col)
            : height(height), row(row), col(col) {}

        // Overload the comparison operator to make the priority queue a
        // min-heap based on height
        bool operator<(const Cell& other) const {
            // Reverse comparison to simulate a min-heap
            return height >= other.height;
        }
    };
};
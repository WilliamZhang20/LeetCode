class Solution {
    int m;
    int n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';
        for(vector<int>& dir : dirs) {
            int nx = i + dir[0];
            int ny = j + dir[1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }
            if(grid[nx][ny] == '1') {
                dfs(nx, ny, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    count += 1;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    std::cout << "incr\n";
                    result++;
                    dfs(i, j, grid);
                }
            }
        }
        return result;
    }
private:
    int m;
    int n;
    std::vector<std::vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    void dfs(int i, int j, vector<vector<char>>& grid) {
        std::cout << i << " " << j << "\n";
        grid[i][j] = '0';
        for(vector<int>& v : dirs) {
            int x = i + v[0];
            int y = j + v[1];
            if(x < 0 || x >= m || y < 0 || y >= n) {
                continue;
            }
            if(grid[x][y] == '1') {
                dfs(x, y, grid);
            }
        }
    }
};
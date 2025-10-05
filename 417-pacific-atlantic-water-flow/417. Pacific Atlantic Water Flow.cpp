class Solution {
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int m;
    int n;

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        for (auto& d: directions) {
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if(vis[x][y]) continue;
            if(heights[x][y] < heights[i][j]) continue;
            dfs(x, y, heights, vis);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> vp(m, vector<bool>(n, false)); // pacific
        vector<vector<bool>> va(m, vector<bool>(n, false)); // atlantic
        for(int i=0; i<n; i++) {
            dfs(0, i, heights, vp);
            dfs(m-1, i, heights, va);
        }
        for(int i=0; i<m; i++) {
            dfs(i, 0, heights, vp);
            dfs(i, n-1, heights, va);
        }
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vp[i][j] && va[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
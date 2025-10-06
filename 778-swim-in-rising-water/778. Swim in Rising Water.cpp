class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
public:
    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        while(!pq.empty()) {
            auto [d, r, c] = pq.top();
            pq.pop();
            if(vis[r][c]) continue;
            vis[r][c] = true;
            
            if(r == m-1 && c == n-1) return d;

            for(auto& [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                    int new_d = max(d, grid[nr][nc]);
                    pq.emplace(new_d, nr, nc);
                }
            }
        }
        return -1;
    }
};
using pii = pair<int, int>;

class Solution {
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    bool inside(int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.emplace(0, 0);
        cost[0][0] = 0;
        while(!pq.empty()) {
            pii curr = pq.top();
            pq.pop();
            for(auto& [f, s] : dir) {
                int x = curr.first + f;
                int y = curr.second + s;
                if(inside(x, y)) {
                    int cc = max(cost[curr.first][curr.second], abs(heights[x][y] - heights[curr.first][curr.second]));
                    if(cc < cost[x][y]) {
                        cost[x][y] = cc;
                        pq.emplace(x, y);
                    }
                }
            }
        }
        return cost[m-1][n-1];
    }
};
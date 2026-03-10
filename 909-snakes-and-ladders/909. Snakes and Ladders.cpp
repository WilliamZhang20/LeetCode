class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int n2 = n * n;
        vector<int> dist(n2+1, 1000);
        queue<int> q;
        vector<bool> vis(n2+1, false);
        q.push(1);
        dist[1] = 0;
        while(!q.empty()) {
            // convert from cell value to i, j: [n, x / n]
            int val = q.front();
            q.pop();
            if(vis[val]) continue;
            vis[val] = true;
            for(int x=1; x<=6; x++) {
                if(val + x > n2) break;
                int r = (val + x - 1) / n; 
                int c = (val + x - 1) % n;
                if (r % 2 == 1) c = n - 1 - c;
                r = n - 1 - r;
                if(board[r][c] != -1) {
                    q.push(board[r][c]);
                    dist[board[r][c]] = min(dist[board[r][c]], dist[val] + 1);
                } else if(!vis[val + x]) {
                    dist[val + x] = min(dist[val + x], dist[val] + 1);
                    q.push(val + x);
                }
            }
        }
        if(dist[n2] == 1000) return -1;
        return dist[n2];
    }
};
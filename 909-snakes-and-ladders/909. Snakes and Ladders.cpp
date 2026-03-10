class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int n2 = n * n;
        queue<int> q;
        vector<bool> vis(n2+1, false);
        q.push(1);
        vis[1] = true;
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int cur = q.front();
                q.pop();
                if(cur == n2) return steps;
                for(int d=1; d<=6 && cur + d <= n2; d++) {
                    int nxt = cur + d;
                    int r = (nxt - 1) / n;
                    int c = (nxt - 1) % n;
                    if(r % 2) c = n - 1 - c;
                    r = n - 1 - r;
                    if(board[r][c] != -1)
                        nxt = board[r][c];
                    if(!vis[nxt]) {
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
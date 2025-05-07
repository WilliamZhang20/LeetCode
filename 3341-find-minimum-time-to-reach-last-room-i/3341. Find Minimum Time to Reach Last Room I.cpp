struct State {
    int x;
    int y;
    int dis;
};

class Solution {
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int inf = 0x3f3f3f3f;
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, inf)); // distances from 0, 0
        vector<vector<bool>> v(n, vector<bool>(m, 0)); // visited segment

        d[0][0] = 0;

        auto cmp = [](const State& a, const State& b) { return a.dis > b.dis; };

        priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
        q.push(State{0, 0, 0}); // opting for aggregate initialization

        while(!q.empty()) {
            State curr = q.top();
            q.pop();
            if(v[curr.x][curr.y]) continue;
            v[curr.x][curr.y] = true;
            for(vector<int>& dir : dirs) {
                int nx = curr.x + dir[0];
                int ny = curr.y + dir[1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int dist = max(d[curr.x][curr.y], moveTime[nx][ny]) + 1;
                if(dist < d[nx][ny]) {
                    d[nx][ny] = dist;
                    q.push(State{nx, ny, dist});
                }                
            }
        }
        
        return d[n-1][m-1];
    }
};
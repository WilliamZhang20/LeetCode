constexpr int MOD = 1e9+7;
#include <climits>

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<roads.size(); i++) {
            adj[roads[i][0]].emplace_back(roads[i][1], roads[i][2]);
            adj[roads[i][1]].emplace_back(roads[i][0], roads[i][2]);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> sp(n, LLONG_MAX); // from node 0
        vector<int> pathcnt(n, 0);
        sp[0] = 0;
        pathcnt[0] = 1;
        pq.emplace(0, 0); // time, node
        while(!pq.empty()) {
            long long time = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            if (time > sp[curr]) {
                continue;
            }
            for(auto& [neighbor, road] : adj[curr]) {
                if(time + road < sp[neighbor]) {
                    sp[neighbor] = time + road;
                    pathcnt[neighbor] = pathcnt[curr];
                    pq.emplace(sp[neighbor], neighbor);
                }
                else if(time + road == sp[neighbor]) {
                    pathcnt[neighbor] = (pathcnt[curr] + pathcnt[neighbor]) % MOD;
                }
            }
        }
        return pathcnt[n-1];
    }
};
class Solution {
    int SENTINEL = 1e6;

    vector<vector<int>> graph;
    map<int, int> rank;
    map<pair<int, int>, bool> conn;
public:
    int dfs(int node, int discoveryRank) {
        if(rank[node] != SENTINEL) {
            return rank[node];
        }
        int minRank = discoveryRank+1;
        rank[node] = discoveryRank;
        for(auto& neighbor: graph[node]) {
            if(rank[neighbor] == discoveryRank-1) continue;
            int recurRank = dfs(neighbor, discoveryRank+1);
            if(recurRank <= discoveryRank) {
                int u = min(node, neighbor);
                int v = max(node, neighbor);
                conn[{u, v}] = false;
            }
            minRank = min(minRank, recurRank);
        }
        return minRank;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        for(int i=0; i<n; i++) {
            rank[i] = SENTINEL;
        }
        for(auto& c: connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
            int u = min(c[0], c[1]);
            int v = max(c[0], c[1]);
            conn[{u, v}] = true;
        }
        dfs(0, 0);
        vector<vector<int>> res;
        for(auto& [k, v] : conn) {
            if(v) res.push_back(vector<int>{k.first, k.second});
        }
        return res;
    }
};
class Solution {
    vector<vector<int>> graph;
    vector<int> disc; // Discovery time of each node
    vector<int> low;  // Lowest discovery time reachable via back-edge
    vector<vector<int>> bridges;
    int timer;

public:
    void dfs(int u, int p) {
        disc[u] = low[u] = ++timer;
        
        for (int v : graph[u]) {
            if (v == p) continue; // Don't go back to parent
            
            if (disc[v] == 0) { // If v is not visited
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                
                // If the lowest vertex reachable from v is still deeper than u, 
                // then u-v is a bridge.
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                // Update low value of u for back-edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.assign(n, vector<int>());
        disc.assign(n, 0);
        low.assign(n, 0);
        timer = 0;

        for (const auto& edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1);
        return bridges;
    }
};
class Solution {
    vector<vector<pair<int, int>>> graph;
    int ans = 0;
    int maxT;
    vector<int> v;
    vector<int> visited;
    void dfs(int node, int time, int score) {
        if(time > maxT) {
            return;
        }
        if(!visited[node]) {
            score += v[node];
        }
        visited[node] += 1;

        if(node == 0) ans = max(ans, score);

        for(auto& [nei, cost] : graph[node]) {
            dfs(nei, time+cost, score);
        }

        visited[node] -= 1;
    }
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        graph.resize(values.size());
        int n = values.size();
        maxT = maxTime;
        v = values;
        for (auto& edge : edges) {
            auto& u = edge[0];
            auto& v = edge[1];
            auto& t = edge[2];

            graph[u].emplace_back(v, t);
            graph[v].emplace_back(u, t);
        }

        visited.resize(n);
        dfs(0, 0, 0);
        return ans;
    }
};
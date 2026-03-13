class Solution {
    vector<vector<int>> graph;
    int diameter = 0;
public:
    int dfs(int curr, vector<bool>& v) {
        v[curr] = true;
        int best1 = 0, best2 = 0; 
        for(auto& n: graph[curr]) {
            if(!v[n]) {
                int d = dfs(n, v);
                if(d > best1) {
                    best2 = best1;
                    best1 = d;
                } else if(d > best2) {
                    best2 = d;
                }
            }
        }
        diameter = max(diameter, best1 + best2);
        return 1 + best1;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        graph.resize(n);
        for(auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> v(n, false);
        dfs(0, v);
        return diameter;
    }
};
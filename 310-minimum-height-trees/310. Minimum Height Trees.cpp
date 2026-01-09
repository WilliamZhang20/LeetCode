class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 2) {
            vector<int> result;
            for (int i = 0; i < n; ++i) result.push_back(i);
            return result;
        }
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> leaves;
        for(int i=0; i<n; i++) {
            if(degree[i]==1) {
                leaves.push(i);
            }
        }
        int remNodes = n;
        while(remNodes > 2) {
            int curr = leaves.size();
            remNodes -= curr;
            for(int i=0; i < curr; i++) {
                int leaf = leaves.front();
                leaves.pop();
                for(auto neighbor: adj[leaf]) {
                    if(--degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        vector<int> result;
        while(!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        for(const auto val : prerequisites) {
            int dest = val[0];
            int src = val[1];
            adj[src].push_back(dest);
            indegree[dest]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            if(adj.count(node)) {
                for(auto neighbor: adj[node]) {
                    indegree[neighbor]--;
                    if(indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }
        if(ans.size() == numCourses) {
            return ans;
        }
        return {};
    }
};
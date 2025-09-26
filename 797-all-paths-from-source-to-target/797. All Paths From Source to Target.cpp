class Solution {
    vector<vector<int>> result;
    void explore(vector<int>& path, vector<vector<int>>& graph, int src, int dest) {
        if(src == dest) {
            result.push_back(path);
            return;
        }
        for(int i=0; i<graph[src].size(); i++) {
            path.push_back(graph[src][i]);
            explore(path, graph, graph[src][i], dest);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // graph is already the adjacency list
        vector<int> path;
        path.push_back(0);
        int dest = graph.size() - 1;
        explore(path, graph, 0, dest);
        return result;
    }
};
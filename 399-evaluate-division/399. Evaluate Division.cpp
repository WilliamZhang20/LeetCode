class Solution {
    unordered_map<string, vector<pair<string, double>>> graph;
public:
    double dfs(double val, string src, string dest, unordered_map<string, bool>& vis) {
        vis[src] = true;
        double ret;
        std::cout << src << " " << dest << " " << val << "\n";
        for(int i=0; i<graph[src].size(); i++) {
            if(graph[src][i].first == dest) {
                return val * graph[src][i].second;
            }
            else if(!vis[graph[src][i].first]) {
                ret = dfs(graph[src][i].second * val, graph[src][i].first, dest, vis);
                if(ret != -1) {
                    return ret;
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0; i<equations.size(); i++) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        vector<double> result;
        for(int i=0; i<queries.size(); i++) {
            unordered_map<string, bool> vis;
            double val = 1;
            result.push_back(dfs(val, queries[i][0], queries[i][1], vis));
        }   
        return result;
    }
};
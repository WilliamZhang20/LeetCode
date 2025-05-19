// leetcode 399
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> result;
        for(int i=0; i<equations.size(); i++) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        for(int i=0; i<queries.size(); i++) {
            // search for division
            result.push_back(dfs(queries[i][0], queries[i][1]));
            visited.clear();
        }
        return result;
    }
private:
    unordered_map<string, vector<pair<string, double>>> graph; // adjacency list
    unordered_set<string> visited;
    double dfs(std::string source, std::string destination) {
        if(graph[source].size() != 0 && source == destination) {
            return 1;
        }
        visited.insert(source);
        for(int i=0; i<graph[source].size(); i++) {
            if(visited.count(graph[source][i].first)) {
                continue;
            }
            double result = dfs(graph[source][i].first, destination);
            if(result != -1) {
                return result*graph[source][i].second;
            }
        }
        return -1;
    }
};
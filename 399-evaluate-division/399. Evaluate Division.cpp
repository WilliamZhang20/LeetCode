class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;

    pair<string, double> find(string i) {
        if(parent.find(i) == parent.end()) {
            parent[i] = i;
            weight[i] = 1.0;
            return {i, 1.0};
        }
        if(parent[i] == i) return {i, 1.0};

        pair<string, double> res = find(parent[i]);
        parent[i] = res.first;
        weight[i] *= res.second;
        return {parent[i], weight[i]};
    }

    void unite(string i, string j, double d) {
        // merge two sets
        pair<string, double> root1 = find(i);
        pair<string, double> root2 = find(j);

        if(root1.first != root2.first) {
            parent[root1.first] = root2.first;
            weight[root1.first] = (d * root2.second) / root1.second;
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            unite(equations[i][0], equations[i][1], values[i]);
        }
        vector<double> res;
        for(auto& q : queries) {
            string var1 = q[0], var2 = q[1];

            if (parent.find(var1) == parent.end() || parent.find(var2) == parent.end()) {
                res.push_back(-1.0);
            } else {
                pair<string, double> res1 = find(var1);
                pair<string, double> res2 = find(var2);

                if(res1.first != res2.first) {
                    res.push_back(-1.0); // different parents, can't figure it out
                }
                else {
                    res.push_back(res1.second / res2.second);
                }
            }
        }
        return res;
    }
};
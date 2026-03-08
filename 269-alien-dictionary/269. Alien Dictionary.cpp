class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<int, int> indegree;
        for (auto &w : words)
            for (char c : w)
                indegree[c - 'a'] = 0;
        vector<vector<int>> graph(26);
        string order = "";
        for (int i = 0; i < words.size() - 1; i++) {
            string &a = words[i];
            string &b = words[i + 1];

            int len = min(a.size(), b.size());

            for (int j = 0; j < len; j++) {
                int u = a[j] - 'a';
                int v = b[j] - 'a';

                if (u != v) {
                    graph[u].push_back(v);
                    indegree[v]++;
                    break;
                }

                if (j == len - 1 && a.size() > b.size())
                    return "";
            }
        }
        queue<int> q;
        for(auto& [k, v] : indegree)
            if(v == 0)
                q.push(k);

        while(!q.empty()) {
            int node = q.front();
            order += 'a' + node;
            q.pop();
            for (int nei : graph[node]) {
                if (--indegree[nei] == 0)
                    q.push(nei);
            }
        }
        if(order.size() != indegree.size()) return "";
        return order;
    }
};
class Solution {
    // need to keep track of existence of req time range - range query...
    // sorting...
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<int> ans(queries.size(), 0);
        vector<pair<int, int>> sortedQueries;
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());
        int left = 0;
        int right = 0;
        unordered_map<int, int> servers;
        int active = 0;
        for(int i=0; i<queries.size(); i++) {
            int start = sortedQueries[i].first - x;
            while(right < logs.size() && logs[right][1] <= sortedQueries[i].first) {
                if(servers[logs[right][0]] == 0) {
                    active += 1;
                }
                servers[logs[right][0]] += 1;
                right += 1;
            }
            while(left < right && logs[left][1] < start) {
                servers[logs[left][0]] -= 1;
                if(servers[logs[left][0]] == 0) {
                    active -= 1;
                }
                left += 1;
            }
            ans[sortedQueries[i].second] = n - active;
        }
        return ans;
    }
};
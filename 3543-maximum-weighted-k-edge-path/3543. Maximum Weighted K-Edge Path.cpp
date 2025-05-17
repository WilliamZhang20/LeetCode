class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<set<int>>> dp(n, vector<set<int>>(k+1));
        for(int u=0; u<n; u++) {
            dp[u][0].insert(0); // establish base case
        }
        for(int e = 0; e < k; e++) {
            for(auto& edge: edges) {
                int u = edge[0], v = edge[1], wt = edge[2];
                for(auto& w: dp[u][e]) {
                    int new_w = w + wt;
                    if(new_w < t) {
                        dp[v][e+1].insert(new_w);
                    }
                }
            }
        }
        int ans = -1;
        for(int u = 0; u<n; u++) {
            if(!dp[u][k].empty()) {
                // retrieve last element using std::prev from ordered set
                ans = max(ans, *prev(dp[u][k].end()));
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        // build it up bottom up
        vector<int> dp(budget+1, 0);
        // iterate through...take or no take...maximizing value
        for(int i=0; i<n; i++) {
            int cost = present[i];
            int profit = future[i] - present[i];
            for(int b = budget; b >= cost; --b) {
                dp[b] = max(dp[b], dp[b - cost] + profit);
            }
        }
        return dp[budget];
    }
};
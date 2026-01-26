class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        for (const auto& t : transactions) {
            balance[t[0]] -= t[2];
            balance[t[1]] += t[2];
        }
        
        vector<int> debts;
        for (const auto& [person, amount] : balance) {
            if (amount != 0) {
                debts.push_back(amount);
            }
        }
        
        int n = debts.size();
        if (n == 0) return 0;
        
        // dp[mask] = minimum transactions to settle debts represented by mask
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        
        // Precompute subset sums
        vector<int> subsetSum(1 << n, 0);
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subsetSum[mask] += debts[i];
                }
            }
        }
        
        // DP transition
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == INT_MAX) continue;
            
            int remaining = ((1 << n) - 1) ^ mask;
            
            for (int subset = remaining; subset > 0; subset = (subset - 1) & remaining) {
                if (subsetSum[subset] == 0) {
                    int bits = __builtin_popcount(subset);
                    dp[mask | subset] = min(dp[mask | subset], dp[mask] + bits - 1);
                }
            }
        }
        
        return dp[(1 << n) - 1];
    }
};
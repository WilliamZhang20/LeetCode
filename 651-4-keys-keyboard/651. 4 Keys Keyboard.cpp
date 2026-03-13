class Solution {
public:
    int maxA(int n) {
        // return max number of A's printed
        // dp[i] = max number of a's printed with i key presses
        vector<int> dp(n+1, 0);
        iota(dp.begin(), dp.end(), 0);
        for(int i=1; i<=n-3; i++) {
            for(int j=i+3; j<=min(n, i+6); j++) {
                dp[j] = max(dp[j], (j - i - 1)*dp[i]);
            }
        }
        
        return dp[n];
    }
};
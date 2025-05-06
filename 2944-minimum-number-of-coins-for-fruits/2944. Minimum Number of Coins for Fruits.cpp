class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--) {
            dp[i] = INT_MAX;
            for(int j=i+1; j <= min(n, 2 * i + 2); j++) {
                dp[i] = min(dp[i], dp[j]);
            }
            dp[i] += prices[i];
        }
        for(int i: dp) {
            cout << i << "\n";
        }
        return dp[0]; // must purchase first
    }
};
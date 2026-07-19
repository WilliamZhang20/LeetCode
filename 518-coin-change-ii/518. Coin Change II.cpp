class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                if(dp[j] < INT_MAX - dp[j-coin]) { // if it shoots past INT_MAX, it's bad
                    dp[j] += dp[j-coin];
                }
            }
        }
        
        return dp[amount];
    }
};
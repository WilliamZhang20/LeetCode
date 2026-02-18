class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num: nums) {
            total += num;
        }
        if(total % 2 != 0) return false;
        int subSum = total / 2;
        int n = nums.size();
        bool dp[n + 1][subSum + 1];
        memset(dp, 0, (n + 1) * (subSum + 1) * sizeof(bool));
        dp[0][0] = true;
        for(int i=1; i<=n; i++) {
            int curr = nums[i-1];
            for(int j=0; j<=subSum; j++) {
                if(j < curr)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-curr];
            }
        }
        return dp[n][subSum];
    }
};
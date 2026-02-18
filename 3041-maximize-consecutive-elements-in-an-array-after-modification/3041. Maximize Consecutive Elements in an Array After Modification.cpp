class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<long long, int> dp;
        int ans = 0;
        for(int x: nums) {
            int use_x = dp.count(x-1) ? dp[x-1] + 1 : 1;
            int use_x1 = dp.count(x) ? dp[x] + 1 : 1;
            dp[x] = max(dp[x], use_x);
            dp[x+1] = max(dp[x+1], use_x1);
            ans = max(ans, max(dp[x], dp[x+1]));
        }
        return ans;
    }
};
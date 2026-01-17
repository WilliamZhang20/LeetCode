class Solution {
public:
    int n;
    int t1, t2;
    int MOD = 1e9+7;
    unordered_map<long long, int> dp;

    int dfs(int i, int expected, int curXor, vector<int>& nums) {
        if(i == n) {
            return 0;
        }
        long long key = ((long long)i << 40) | ((long long)expected << 20) | curXor;
        if(dp.count(key)) return dp[key];

        int res = 0;
        int target = (expected == 0) ? t1 : t2;
        int newXor = curXor ^ nums[i];
        
        res = (res + dfs(i + 1, expected, newXor, nums)) % MOD;

        if (newXor == target) {
            if (i == n - 1) {
                res = (res + 1) % MOD;
            } else {
                res = (res + dfs(i + 1, 1 - expected, 0, nums)) % MOD;
            }
        }
        return dp[key] = res;
    }
    
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        n = nums.size();
        this->t1 = target1;
        this->t2 = target2;
        return dfs(0, 0, 0, nums);
    }
};
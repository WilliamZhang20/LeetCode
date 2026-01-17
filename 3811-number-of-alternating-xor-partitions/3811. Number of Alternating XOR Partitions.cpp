class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        const int MOD = 1e9 + 7;

        unordered_map<int, long long> mp1;
        unordered_map<int, long long> mp2;

        int px = 0;
        int dp1 = 0, dp2 = 0;
        for(int& val: nums) {
            px ^= val;
            
            long long curDp1 = mp2[px ^ target1];
            if (px == target1) curDp1 = (curDp1 + 1) % MOD;

            long long curDp2 = mp1[px ^ target2];
            
            mp1[px] = (mp1[px] + curDp1) % MOD;
            mp2[px] = (mp2[px] + curDp2) % MOD;

            dp1 = curDp1;
            dp2 = curDp2;
        }
        return (dp1 + dp2) % MOD;
    }
};
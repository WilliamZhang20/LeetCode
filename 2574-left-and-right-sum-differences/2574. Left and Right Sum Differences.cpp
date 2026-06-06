class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int prefix = 0;
        for(int i=0; i<n; i++) {
            ans[i] = prefix;
            prefix += nums[i];
        }
        int suffix = 0;
        for(int i=n-1; i>=0; i--) {
            ans[i] = abs(ans[i]-suffix);
            suffix += nums[i];
        }
        return ans;
    }
};
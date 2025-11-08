class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n); // how long non-decreasing ends at i
        vector<int> right(n); // how long non-decreasing begins from i
        left[0] = 1;
        for (int i=1; i<n; ++i) {
            if (nums[i] >= nums[i - 1])
                left[i] = left[i - 1] + 1;
            else
                left[i] = 1;
        }
        right[n-1] = 1;
        for(int i=n-2; i>=0; i--) {
            if(nums[i] <= nums[i+1]) 
                right[i] = right[i+1] + 1;
            else
                right[i] = 1;
        }
        int ans = 1;
        for(int i=0; i<n; i++) {
            int len = 0;
            if (n == 1)
                len = 1;
            else if(i == 0) 
                len = 1 + right[1];
            else if(i == n-1) 
                len = left[n-2] + 1;
            else if(nums[i+1] >= nums[i-1])
                len = left[i-1] + right[i+1] + 1;
            else
                len = max(left[i-1], right[i+1]) + 1; // choose only 1
            ans = max(ans, len);
        }
        return ans;
    }
};
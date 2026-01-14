class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int right = n-1;
        while (right > 0 && nums[right] > nums[right-1]) {
            --right;
        }
        if(right == 0) {
            return (long long)n*(n+1) / 2;
        }
        long long ans = n - right + 1;
        for(int left = 0; left < n; ++left) {
            if(left > 0 && nums[left] <= nums[left-1]) {
                break;
            }

            while(right < n && nums[left] >= nums[right]) {
                right++;
            }

            ans += (n - right + 1);
        }
        return ans;
    }
};
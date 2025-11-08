class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<=n-3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            if(nums[i] > 0)
                break;
            int left = i+1;
            int right = n-1;
            int target = -nums[i];
            while(left < right) {
                int s = nums[left] + nums[right];
                if(s < target) {
                    left++;
                } else if(s > target) {
                    right--;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left += 1;
                    right -= 1;
                    while(left < right && nums[left] == nums[left-1]) left += 1;
                    while(left < right && nums[right] == nums[right+1]) right -= 1;
                }
            }
        }
        return res;
    }
};
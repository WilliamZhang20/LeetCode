class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int currSum = 1e6;
        for(int i=0; i<nums.size(); i++) {
            int left = i + 1;
            int right = n-1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    ++left;
                }
                else if (sum > target) {
                    --right;
                }
                else {
                    return target;
                }
                if(abs(target - sum) < abs(target - currSum)) {
                    currSum = sum;
                }
            }
        }
        return currSum;
    }
};
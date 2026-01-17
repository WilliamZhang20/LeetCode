class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int result = 0;
        unordered_set<int> vals;
        int prev = nums[0];
        if(nums[0] != target[0]) {
            vals.insert(nums[0]);
        }
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != target[i]) {
                vals.insert(nums[i]);
            }
            prev = nums[i];
        }
        return vals.size();
    }
};
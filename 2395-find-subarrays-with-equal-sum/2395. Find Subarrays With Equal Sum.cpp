class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> sums;
        int curr = nums[0] + nums[1];
        sums.insert(curr);
        for(int i=2; i<nums.size(); i++) {
            curr -= nums[i-2];
            curr += nums[i];
            if(sums.count(curr)) {
                return true;
            }
            sums.insert(curr);
        }
        return false;
    }
};
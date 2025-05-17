class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for(int i=0; i<nums.size(); i++) {
            count[nums[i]]++;
        }
        for(int i=1; i<=2; i++) {
            count[i] += count[i-1];
        }
        vector<int> ret(nums.size());
        for(int i=nums.size()-1; i>=0; i--) {
            ret[count[nums[i]]-1] = nums[i];
            count[nums[i]]--;
        }
        nums = ret;
    }
};
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size() + 1);
        for(int i=0; i<queries.size(); i++) {
            diff[queries[i][0]] -= 1;
            diff[queries[i][1]+1] += 1;
        }
        if(nums[0] + diff[0] > 0) {
            return false;
        }
        for(int i=1; i<nums.size(); i++) {
            diff[i] += diff[i-1];
            nums[i] += diff[i];
            if(nums[i] > 0) {
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> output;
    int n;
    void backtrack(int first, vector<int>& nums, vector<int>& curr) {
        output.push_back(curr); // all sizes included
        for(int i=first; i<n; i++) {
            curr.push_back(nums[i]);
            backtrack(i+1, nums, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        backtrack(0, nums, curr);
        return output;
    }
};
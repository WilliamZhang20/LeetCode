class Solution {
    void explore(vector<int>& candidates, int& target, vector<vector<int>>& ans, vector<int>& curr, int idx, int sum) {
        if (sum == target) {
            ans.push_back(curr);
            return;
        }
        if(sum > target || idx == candidates.size()) {
            return;
        }
        curr.push_back(candidates[idx]);
        explore(candidates, target, ans, curr, idx, sum + candidates[idx]);
        curr.pop_back();
        explore(candidates, target, ans, curr, idx+1, sum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        explore(candidates, target, ans, curr, 0, 0);
        return ans;
    }
};
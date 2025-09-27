class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, candidates, target, 0, curr);
        return ans;
    }
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& candidates, int rem, int idx, vector<int>& curr) {
        if(rem == 0) {
            ans.push_back(curr);
            return;
        }
        else if(rem < 0) {
            return;
        }
        for(int i=idx; i<candidates.size() && rem >= candidates[i]; i++) {
            if(i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }
            curr.push_back(candidates[i]);
            backtrack(ans, candidates, rem-candidates[i], i+1, curr);
            curr.pop_back();
        }
    }
};
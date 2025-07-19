class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> soln;
        findSolns(candidates, target, 0, soln, 0, result);
        return result;
    }
private:
    void findSolns(vector<int>& candidates, int target, int idx, vector<int>& soln, int buildup, vector<vector<int>>& res) {
        if(buildup == target) {
            res.push_back(soln);
            return;
        }
        if(buildup > target || idx == candidates.size()) {
            return;
        }
        // include
        soln.push_back(candidates[idx]);
        findSolns(candidates, target, idx, soln, buildup + candidates[idx], res);
        soln.pop_back();
        // or not include
        findSolns(candidates, target, idx+1, soln, buildup, res);
    }
};
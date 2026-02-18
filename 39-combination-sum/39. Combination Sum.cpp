class Solution {
    vector<vector<int>> result;
    vector<int> path;
public:
    void dfs(int start, int remaind, vector<int>& candidates) {
        if(remaind == 0) {
            result.push_back(path);
            return;
        }
        if(remaind < 0) return;
        for(int i=start; i<candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(i, remaind - candidates[i], candidates);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, target, candidates);
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans, 0, 1, n, k, curr);
        return ans;
    }
private:
    void backtrack(vector<vector<int>>& ans, int sum, int idx, int& target, int& k, vector<int>& curr) {
        if(curr.size() > k) {
            return;
        }
        if(sum == target && curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        else if(sum > target || idx == 10) {
            return;
        }
        curr.push_back(idx);
        backtrack(ans, sum+idx, idx+1, target, k, curr);
        curr.pop_back();
        backtrack(ans, sum, idx+1, target, k, curr);
    }
};
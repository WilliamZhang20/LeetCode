class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(auto val : st) {
            if(!st.count(val - 1)) {
                int j=val + 1;
                while(st.count(j)) {
                    ++j;
                }
                res = max(res, j - val);
            }
        }
        return res;
    }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& lhs, auto& rhs) {
            return lhs[1] < rhs[1];
        });
        int ans = 0, k = INT_MIN;
        for(const auto& interval: intervals) {
            if(interval[0] >= k) {
                k = interval[1];
            } else {
                ans += 1;
            }
        }
        return ans;
    }
};